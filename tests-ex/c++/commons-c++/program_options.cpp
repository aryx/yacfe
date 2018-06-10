#include <commons/program_options.h>

namespace commons {

ProgramOptions 
parse_cmdline(int argc, char** argv, ProgramOptionsDescription desc)
{
	ProgramOptions res;
	
	// standard code. boost is quite verbose, hmm.
	po::options_description hidden("Hidden options");
	hidden.add_options()
		("restargs", po::value< vector<string> >(), "rest arguments");
	po::positional_options_description p;
	p.add("restargs", -1);
	po::options_description all_options;
	all_options.add(desc).add(hidden);
	
	store(po::command_line_parser(argc, argv).
		  options(all_options).positional(p).run(), res.options);
	po::notify(res.options);

	if(res.options.count("restargs"))
		res.args = res.options["restargs"].as< vector<string> >();
	return res;
}

void 
usage_and_exit(string usage_str, ProgramOptionsDescription desc)
{
	cout << usage_str;
	cout << desc << "\n";
	exit(1);
}
}
