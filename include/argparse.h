#ifndef ARGPARSE_H
#define ARGPARSE_H

#include <vector>

class ap_parser;
class ap_subparsers;
class ap_args;
class ap_arg;

class ap_parser
{
public:
	ap_subparsers *				add_subparsers();
	void					set_defaults(
			const char * name,
			void(*func)(ap_args * args));
	void					add_argument(
			const char * name,
			const char * help,
			int nargs);
	ap_args *				parse_args(
			int ac,
			char ** av);
	void					help(
			int ac,
			char ** av);
	char *					usage(
		int ac,
		char ** av);
	std::vector<ap_arg *>			list_positional_args();


	std::vector<ap_arg *>			_M_args;
	std::vector<ap_subparsers *>		_M_subparsers;
};
class ap_subparsers
{
public:
	ap_parser *				add_parser(const char * name);
	std::vector<ap_parser *>		_M_parsers;
};
class ap_args
{
public:
	void					call(
			const char * name,
			ap_args * args);
};
class ap_arg
{
public:
	char const *			_M_name;
	char const *			_M_help;
	int				_M_nargs;
};


/**
 * name  name of argument ("-a", "--apple")
 * help  help text
 * nargs number of arguments to except. 0 means 'store_true'. -1 means '+'. -2 means '*'
 */



#endif

