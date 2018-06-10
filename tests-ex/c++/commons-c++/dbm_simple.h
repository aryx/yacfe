#ifndef DBM_SIMPLE_H
#define DBM_SIMPLE_H

#include <commons/common.h>

// less templatized version than dbm.h.


#include <qdbm/xcuria.h>
#include <qdbm/xdepot.h>

// there is also a xml and binary serialisation interface
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


/*###########################################################################*/
//* Interface
/*###########################################################################*/

template <typename Key, typename Value>
class hash_dbm : public commons::uncopyable {
public:
	hash_dbm(string filename, int omode);
	~hash_dbm();

	Value get(const Key& k); // throw commons::NotFound
	void  put(const Key& k, const Value& v);

	Value operator[](const Key& k) { return this->get(k); }
	//Value find(Key& k)       { this->get(k); }

	bool hasKey(const Key& k);

    // TODO begin, end,   clear
	void iterInit();
	Key nextKey();

private:	
	qdbm::Depot *dbm;	
};



/*###########################################################################*/
//* Implementation
/*###########################################################################*/


template <typename Key, typename Value> 
hash_dbm<Key,Value>::
hash_dbm(string filename, int omode)
{
	try {
		dbm = new qdbm::Depot(filename.c_str(), omode);
	}
	catch (qdbm::Depot_error &e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}

template <typename Key, typename Value> 
hash_dbm<Key,Value>::
~hash_dbm() 
{
	dbm->close(); 
	dbm = NULL;
}


template <typename Key, typename Value> 
Value hash_dbm<Key,Value>::
get(const Key& k)
{
	try {
		Value v;
		
		std::ostringstream oss;
		boost::archive::text_oarchive oa(oss);
		oa & k;

		try {
			char* val = this->dbm->get(oss.str().c_str(), -1);
			// this happens when the silent flag of dbm is set
			// (but default = off)
			if(val==NULL) 
				throw commons::NotFound(__HERE__,"dbm");
		
			std::istringstream iss(val);
			boost::archive::text_iarchive ia(iss);
			ia >> v;
			free(val);
			return v;
		}
		catch (qdbm::Depot_error &e) { 
			if (e.code() == qdbm::Depot::ENOITEM)
				throw commons::NotFound(__HERE__,"dbm");
			else 
				throw commons::Failwith(__HERE__, string("qdbm:")+ e.message());
		}
	}
	catch (qdbm::Depot_error &e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}


template <typename Key, typename Value> 
bool hash_dbm<Key,Value>::
hasKey(const Key& k)
{
	try {
		Value _v = this->get(k);
		return true;
	}
	catch (commons::NotFound& e) { return false; }
}



template <typename Key, typename Value> 
void hash_dbm<Key,Value>::
put(const Key& k, const Value& v) 
{
	try {
		std::ostringstream ossk;
		boost::archive::text_oarchive oak(ossk);
		oak & k;

		std::ostringstream ossv;
		boost::archive::text_oarchive oav(ossv);
		oav & v;

		this->dbm->put(ossk.str().c_str(), -1, ossv.str().c_str(), -1);
		return;
	  }
	  catch (qdbm::Depot_error &e) { 
		  throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	  }
	}
    // TODO begin, end,   clear

template <typename Key, typename Value> 
void hash_dbm<Key,Value>::
iterInit() 
{ 
	try {
		this->dbm->iterinit(); 
	}
	catch (qdbm::Depot_error &e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}

template <typename Key, typename Value> 
Key hash_dbm<Key,Value>::
nextKey() 
{ 
	try {
		Key k;
		
		try {
			char *val = this->dbm->iternext();
			// if silent flag was set
			if(val==NULL)
				throw commons::EndOfIter(__HERE__);
			
			std::istringstream iss(val);
			boost::archive::text_iarchive ia(iss);
			ia >> k;
			free(val);
			return k;
		}
		catch (qdbm::Depot_error &e) { 
			if (e.code() == qdbm::Depot::ENOITEM)
				throw commons::EndOfIter(__HERE__);
			else 
				throw commons::Failwith(__HERE__, string("qdbm:")+ e.message());
		}
	}
	catch (qdbm::Depot_error &e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}


#endif

