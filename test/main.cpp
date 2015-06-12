
#include <argparse.h>

void f0(struct ap_args * args)
{
	//prt 0
}
void f1(struct ap_args * args)
{
	//print 1
	//print args.a
}
void f2(struct ap_args * args)
{
	//print 2
}

int main(int ac, char** av)
{

	ap_parser * parser = new ap_parser();

	ap_subparsers * subparsers = parser->add_subparsers();

	ap_parser * parser_0 = subparsers->add_parser("p0");
	ap_parser * parser_1 = subparsers->add_parser("p1");
	ap_parser * parser_2 = subparsers->add_parser("p2");


	parser_0->set_defaults("func", f0);
	parser_1->set_defaults("func", f1);
	parser_2->set_defaults("func", f2);

	parser_2->add_argument("-a", "apple",  3 /*nargs=3*/);

	parser_2->add_argument("-a", "apple",  1 /*, default="hello"*/);

	parser_2->add_argument("-b", "banana", 0 /*action='store_true'*/);

	ap_args * args = parser->parse_args(ac, av);
	
	args->call("func", args);

}


