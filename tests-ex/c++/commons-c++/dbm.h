#ifndef DBM_H
#define DBM_H

#include <commons/common.h>

// Persistent part (QDBM)
#include <qdbm/xcuria.h>
#include <qdbm/xdepot.h>

// Serialization part (boost)
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
//#include <boost/archive/xml_oarchive.hpp>
//#include <boost/archive/xml_iarchive.hpp>

/*###########################################################################*/
//* Interface
/*###########################################################################*/

/* Why need persistency ? 
 * Why use a DBM ? 
 * Why need serialization ?
 * 
 * What are the alternatives ? One alternative is to use files. But if
 * have variable length entry in our data ? If the keys are sparsed ?
 *
 * Can we define a std::hash_map like interface ? It's difficult
 * to allow to do transparently  h["key"] = make_pair(1,2);
 * because STL use a ref technique: some functions return a _memory_ ref (&)
 * to an object but in the case of a hash on disk, there is no
 * memory to reference. One way will be to return a special object
 * that behaves like a reference but it's tricky.
 *
 *
 * references:
 * http://en.wikipedia.org/wiki/Serialization
 * http://en.wikipedia.org/wiki/Dbm
 *
 * http://www.boost.org/libs/serialization/doc/index.html
 * see also C++ faq lite section on serialisation
 *
 */

/* todo? need function object for serialisation ? or just use the implicit way
 * used here by using the boost::serialization requirment
 * 
 * todo? opti for string ? use template specialization ? maybe boost
 * already do such specialization need bench
 * to see if worthwhile
 */


/* requirments: Value must have a default constructor 
 * requirments: both Key and Value must be serializable via the 
 *   boost::serialisation library.
 */
template <typename Key, typename Value,
		  typename Dbm = qdbm::Depot,
		  typename DbmExn = qdbm::Depot_error,
		  typename ArchiveIn = boost::archive::text_iarchive,
		  typename ArchiveOut = boost::archive::text_oarchive
		  >
class hash_dbm : public commons::uncopyable {
public:
	hash_dbm(string filename, int omode = Dbm::OWRITER|Dbm::OCREAT);
	~hash_dbm();

	Value get(const Key& k);
	void  put(const Key& k, const Value& v);

	Value operator[](const Key& k)   { return this->get(k); }
	//Value find(Key& k)       { this->get(k); }

	bool hasKey(const Key& k);

	// todo? clear()

    // todo: begin(), end()
	void iterInit();
	Key nextKey();

private:	
	Dbm *dbm;	
};

/*###########################################################################*/
//* Implementation
/*###########################################################################*/

template <typename Key, typename Value, typename Dbm, typename DbmExn, typename ArchiveIn, typename ArchiveOut>
hash_dbm<Key,Value,Dbm,DbmExn,ArchiveIn,ArchiveOut>::
hash_dbm(string filename, int omode)
{ 
	try {
		dbm = new Dbm(filename.c_str(), omode);
	}
	catch (DbmExn& e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}

template <typename Key, typename Value, typename Dbm, typename DbmExn, typename ArchiveIn, typename ArchiveOut>
hash_dbm<Key,Value,Dbm,DbmExn,ArchiveIn,ArchiveOut>::
~hash_dbm()      
{ 
	dbm->close(); 
	delete dbm; 
}
	
template <typename Key, typename Value, typename Dbm, typename DbmExn, typename ArchiveIn, typename ArchiveOut>
Value hash_dbm<Key,Value,Dbm,DbmExn,ArchiveIn,ArchiveOut>::
get(const Key& k) 
{
	Value v;
	try {
		
		// serializing the key
		std::ostringstream oss;
		ArchiveOut oa(oss);
		oa & k;

		try {
			int sizeval = 0;
			char* val = this->dbm->get(oss.str().c_str(),oss.str().size(),
									   0, -1, &sizeval
									   );
			// this happens when the silent flag of dbm is set
			// (but default = off)
			if(val==NULL) 
				throw commons::NotFound(__HERE__,"dbm");
			
			// unserializing val
			//std::istringstream iss(val);
			string strval(val, val+sizeval);
			std::istringstream iss(strval);

			ArchiveIn ia(iss);
			ia >> v;
			free(val);
			return v;
		}
		catch (DbmExn &e) { 
			if (e.code() == Dbm::ENOITEM)
				throw commons::NotFound(__HERE__,"dbm");
			else 
				throw commons::Failwith(__HERE__, string("qdbm:")+ e.message());
		}
	}
	catch (DbmExn& e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}

template <typename Key, typename Value, typename Dbm, typename DbmExn, typename ArchiveIn, typename ArchiveOut>
bool hash_dbm<Key,Value,Dbm,DbmExn,ArchiveIn,ArchiveOut>::
hasKey(const Key& k) 
{
	try {
		/*Value _v =*/ this->get(k);
		return true;
	}
	catch (commons::NotFound& e) { return false; }
}

template <typename Key, typename Value, typename Dbm, typename DbmExn, typename ArchiveIn, typename ArchiveOut>
void hash_dbm<Key,Value,Dbm,DbmExn,ArchiveIn,ArchiveOut>::
put(const Key& k, const Value& v) 
{
	try {
		// serializing key
		std::ostringstream ossk;
		ArchiveOut oak(ossk);
		oak & k;
		
		// serializing val
		std::ostringstream ossv;
		ArchiveOut oav(ossv);
		oav & v;
		
		this->dbm->put(ossk.str().c_str(), ossk.str().size(),
					   ossv.str().c_str(), ossv.str().size());
		return;
	}
	catch (DbmExn& e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}
 

template <typename Key, typename Value, typename Dbm, typename DbmExn, typename ArchiveIn, typename ArchiveOut>
void hash_dbm<Key,Value,Dbm,DbmExn,ArchiveIn,ArchiveOut>::
iterInit() 
{ 
	try {
		this->dbm->iterinit(); 
	}
		catch (DbmExn &e) { 
			throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
		}
}

template <typename Key, typename Value, typename Dbm, typename DbmExn, typename ArchiveIn, typename ArchiveOut>
Key hash_dbm<Key,Value,Dbm,DbmExn,ArchiveIn,ArchiveOut>::
nextKey() 
{ 
	Key k;
	try {
		try {
			int sizeval = 0;
			char *val = this->dbm->iternext(&sizeval);
			// if silent flag was set
			if(val==NULL)
				throw commons::EndOfIter(__HERE__);
			
			//std::istringstream iss(val);
			string strval(val, val+sizeval);
			std::istringstream iss(strval);

			ArchiveIn ia(iss);
			ia >> k;
			free(val);
			return k;
		}
		catch (DbmExn& e) { 
			if (e.code() == Dbm::ENOITEM)
				throw commons::EndOfIter(__HERE__);
			else 
				throw commons::Failwith(__HERE__, string("qdbm:")+ e.message());
		}
	}
	catch (DbmExn& e) { 
		throw commons::Failwith(__HERE__, string("qdbm:") + e.message());
	}
}

#endif

