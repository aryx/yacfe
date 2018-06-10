#include <commons/common.h>
#include <commons/unit_testing.h>
#include <commons/program_options.h>

#include <commons/dbm.h>
#include <cmath>

namespace co = commons;

/*****************************************************************************/
class Pair {
public:
	int first;
	int second;
	Pair(int i, int j) : first(i), second(j) { };
	Pair() { }

	// can also define the serialise function outside of the class.
    friend class boost::serialization::access;
	template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & first;
        ar & second;
    }
};

// for Pair
ostream& operator<<(ostream& os, const Pair& x) 
{
	os << "first:" << x.first << endl;
	os << "second:" << x.second << endl;
	return os;
}

//for std::pair
template <typename T1, typename T2> 
ostream& operator<<(ostream& os, const pair<T1,T2>& x) 
{
	os << "first:" << x.first << endl;
	os << "second:" << x.second << endl;
	return os;
}



/*****************************************************************************/
//* Test persistency and serialization 
/*****************************************************************************/
int test_hash_map_memory()
{
	hash_map<string, pair<int,int> > h;
	h["foo"] = std::make_pair(1,1);
	h["bar"] = std::make_pair(2,3);

	cout << h["foo"] << endl;
	cout << h["foobar"] << endl;
	return 0;
}

int test_qdbm_simple()
{
  try {
    // open the database
	qdbm::Curia dbm("qdbm-simple.db", qdbm::Curia::OWRITER | qdbm::Curia::OCREAT);

    // store the record
    dbm.put("foo", -1, "1,1", -1);

    // retrieve the record
    char* val = dbm.get("foo", -1);
    cout << "Name: " << "foo" << endl;
    cout << "Number: " << val << endl;
    free(val);

    // close the database
    dbm.close();

  } 
  catch(qdbm::Curia_error& e) {  cerr << e << endl;  }
  return 0;
}



int test_qdbm_serialize()
{
  try {

    // open the database
	qdbm::Curia dbm("qdbm.db", qdbm::Curia::OWRITER | qdbm::Curia::OCREAT);

	const Pair x(2,3); // need the const

	std::ostringstream oss;
	boost::archive::text_oarchive oa(oss);
	oa << x;

    // store the record
    dbm.put("foo", -1, oss.str().c_str(), -1);

    // retrieve the record
    char* val = dbm.get("foo", -1);

	std::istringstream iss(val);
	boost::archive::text_iarchive ia(iss);
	Pair res(0,0);
	ia >> res;

    cout << "Name: " << "foo" << endl;
    cout << "String: " << val << endl;
    cout << "Number: " << res << endl;
    free(val);

    // close the database
    dbm.close();

  } 
  catch(qdbm::Curia_error& e) { cerr << e << endl; }
  return 0;
}


int test_qdbm_serialize_use()
{
  try {

    // open the database
	qdbm::Curia dbm("qdbm.db", qdbm::Curia::OWRITER | qdbm::Curia::OCREAT);

    // retrieve a record
    char* val = dbm.get("foo", -1);

	std::istringstream iss(val);
	boost::archive::text_iarchive ia(iss);
	Pair res(0,0);
	ia >> res;

	res.first++;

	std::ostringstream oss;
	boost::archive::text_oarchive oa(oss);
	//oa << (const_cast<Pair>(res));
	oa & res;
    dbm.put("foo", -1, oss.str().c_str(), -1);
	
    cout << "Name: " << "foo" << endl;
    cout << "String: " << val << endl;
    cout << "Number: " << res << endl;
    free(val);

    // close the database
    dbm.close();

  } 
  catch(qdbm::Curia_error& e) { cerr << e << endl; }
  return 0;
}




int test_persistent_hash()
{
	hash_dbm<string, Pair> h("qdbm.db");
	Pair t1(3,4);
	h.put("foo", t1);
	Pair res = h.get("foo");
	res.first++;
	h.put("foo", res);
	Pair res2 = h.get("foo");
	cout << res2 << endl;
	return 0;
}

int test_persistent_hash_use()
{
	hash_dbm<string, Pair> h("qdbm.db");
	
	//hash_dbm<string, Pair> h2(h);

	Pair res = h.get("foo");
	res.first++;
	h.put("foo", res);
	Pair res2 = h.get("foo");
	
	h.put("bar", res);

	cout << res2 << endl;

	Pair notfound = h.get("notfound");

	try {
		h.iterInit();
		while(true) {
			string key = h.nextKey();
			//Pair res = h.get(key);
			//cout << "key=" << key << ". res=" << res << endl;
			cout << "key=" << key << ". res=" << h[key] << endl;
		}
	}
	catch (co::EndOfIter& e) { }
	return 0;
}

int test_serialize_binary()
{
	double d = -6.7;
	{
		ofstream ofs("serialize.raw");
		boost::archive::binary_oarchive oa(ofs);
		oa & d;
	}

	d = 0.0;
	{
		ifstream ifs("serialize.raw");
		boost::archive::binary_iarchive ia(ifs);
		ia & d;
	}
	assert(std::abs(d + 6.7) < 0.0001); 
	return 0;
}

int test_qdbm_serialize_binary()
{
	// try a Pair with a 0. does it confuse qdbm ? 

  try {

    // open the database
    co::pr2("open");
	co::command("rm -f qdbm.db");
	qdbm::Depot dbm("qdbm.db", qdbm::Depot::OWRITER | qdbm::Depot::OCREAT);

	const Pair x(2,3); // need the const

	std::ostringstream oss;
	boost::archive::binary_oarchive oa(oss);
	oa << x;

    // store the record
    co::pr2("store");
    dbm.put("foo", -1, oss.str().c_str(), oss.str().size());
	cout << "size= " << oss.str().size() << endl;
	cout << "strlen= " << strlen(oss.str().c_str()) << endl;

    // retrieve the record
    co::pr2("get");
	int sizeval = 0;
    char* val = dbm.get("foo", -1, 0, -1, &sizeval);
	cout << "sizeval= " << sizeval << endl;

    co::pr2("reading");
	//std::istringstream iss(val);
	string strval(val, val+sizeval);
	std::istringstream iss(strval);

	boost::archive::binary_iarchive ia(iss);
	Pair res(0,0);
	ia >> res;

    cout << "Name: " << "foo" << endl;
    cout << "String: " << val << endl;
    cout << "Number: " << res << endl;
    free(val);

    // close the database
    dbm.close();

  } 
  catch(qdbm::Depot_error& e) { cerr << e << endl; }
  return 0;
}

/*****************************************************************************/
int test_glob()
{
	vector<co::filename> files = co::glob("*.cpp");
	FOREACH(string& s, files) {
		cout << s << endl;
	}
	return 0;
}

int test_split()
{
	vector<string> xs = co::split("this is a    big melon");
	FOREACH(string& s, xs) {
		cout << s << endl;
	}
	return 0;
}

int test_exn()
{
	try {
		throw co::Todo(__HERE__);
	}
	catch(co::exception& e) {
		cout << e.what() << endl;
		cout << e.diagnostic() << endl;
	}
	return 0;
}

/*****************************************************************************/


int main1(int argc, char **argv)
{
	co::pr2("here");

	bool verbose = false;
	int n = 0;

	string usage_str = 
		string("usage: ") + /*argv[0]*/ "commons_test " + 
		"[options] " + "action" + "\nOptions are:";

	co::ProgramOptionsDescription desc(usage_str);
	desc.add_options()
		("help,h", "produce help message")
		("verbose,v", co::cmdline_bool(&verbose), "guess what")
		("number,n", co::cmdline_option(&n), "guess what")
		;
	co::ProgramOptions cmdline = co::parse_cmdline(argc, argv, desc);

	if (cmdline.options.has("help")) 
		co::usage_and_exit(usage_str, desc);
	if (cmdline.args.size() != 1) 
		co::usage_and_exit(usage_str, desc);

	string s = cmdline.args[0];
	cout << "s=" << s << endl;
	cout << "n=" << n << endl;


	if(s == "hash_map_memory")
		return test_hash_map_memory();
	if(s == "qdbm_simple")
		return test_qdbm_simple();
	if(s == "qdbm_serialize")
		return test_qdbm_serialize();
	if(s == "qdbm_serialize_use")
	   return test_qdbm_serialize_use();
	if(s == "persistent_hash")
		return test_persistent_hash();
	if(s == "persistent_hash_use")
		return test_persistent_hash_use();
	if(s == "serialize_binary")
		return test_serialize_binary();
	if(s == "qdbm_serialize_binary")
		return test_qdbm_serialize_binary();
	

	if(s == "glob")
		return test_glob();
	if(s == "exn")
		return test_exn();
	if(s == "split")
		return test_split();


	if(s == "unit_test") {
		bool success = co::unit_test_run_default();
		return (success ? 0 : 1);
	}

	throw co::Failwith(__HERE__, "no valid action for:" + s);

}

int main(int argc, char **argv)
{
	try { return main1(argc, argv); }
	catch (co::exception& e) { cerr << e.diagnostic() << endl; }
	
}
