#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <argparse.h>

ap_subparsers *			ap_parser::add_subparsers()
{
	ap_subparsers * subparsers = new ap_subparsers();

	_M_subparsers.push_back(subparsers);

	return subparsers;
}
std::vector<ap_arg *>		ap_parser::list_positional_args()
{
	std::vector<ap_arg *> ret;

	for(auto arg : _M_args)
	{
		if(arg->_M_nargs = 0) {
			ret.push_back(arg);
		}
	}
}
ap_parser *			ap_subparsers::add_parser(
		const char * name)
{
	ap_parser * parser = new ap_parser();

	parser->_M_name = name;
	
	_M_parsers.push_back(parser);
}
void				ap_parser::set_defaults(
		const char * name,
		void(*func)(struct ap_args * args))
{
}
void			ap_parser::add_argument(
		const char * name,
		const char * help,
		int nargs)
{
	struct ap_arg * arg = (struct ap_arg *)malloc(sizeof(struct ap_arg));
	
	arg->_M_name = name;
	arg->_M_help = help;
	arg->_M_nargs = nargs;
}
struct ap_args *	ap_parser::parse_args(
		int ac,
		char ** av)
{
	if(ac > 1) {
		if(strcmp(av[1], "-h") == 0) {
			help(ac, av);
			exit(0);
		}
	}

	return 0;
}
void			ap_args::call(
		const char * name,
		struct ap_args * args_1)
{
}
char *			ap_parser::subparsers_str()
{
	char * s = new char[512];

	if(_M_subparsers.empty()) {
		strcat(s, "");
	} else {
		for(auto subparser : _M_subparsers) {
			strcat(s, " {");
			for(auto parser : subparser->_M_parsers) {
				char c[64];
				sprintf(c, "%s,", parser->_M_name);
				strcat(s, c);
			}
			strcat(s, "}");
		}
	}
	return s;
}
char *			ap_parser::usage(
		int ac,
		char ** av)
{
	//  usage: test.py [-h] {p0,p1,p2} ...
	
	char * s = new char[512];

	if(_M_subparsers.empty()) {
	} else {
		sprintf(s, "usage: %s [-h] %s ...", av[0], subparsers_str());
	}

	return s;
}
void			ap_parser::help(
		int ac,
		char ** av)
{
	printf("%s\n\n", usage(ac, av));
	printf("positional arguments:\n");

	if(_M_subparsers.empty()) {
	} else {
		printf("  %s\n", subparsers_str());
	}
	
	printf("\n");
	printf("optional arguments:\n");
	for(auto arg : _M_args) {
		printf("  %s\n", arg->help());
	}
}
char *			ap_arg::help()
{
	char * s = new char[256];
	char * arg_str = new char[128];

	//name help nargs

	if(_M_nargs == 0) { // store true
		strcat(arg_str, " ");
	} else if(_M_nargs == -1) { // nargs = "+"
		sprintf(arg_str, " %s [%s ...] ", _M_name, _M_name);
	} else if(_M_nargs == -2) { // nargs = "*"
		sprintf(arg_str, " [%s [%s ...]] ", _M_name, _M_name);
	}

	sprintf(s, "  %s%s%s\n", _M_name, arg_str, _M_help);
	return s;
}




