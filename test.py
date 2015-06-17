#!/usr/bin/env python

import argparse

def f0(args):
    print 0
def f1(args):
    print 1
    print args.a
def f2(args):
    print 2

parser = argparse.ArgumentParser()
subparsers_0 = parser.add_subparsers()

parser_0 = subparsers_0.add_parser('p0')
parser_0.set_defaults(func=f0)

parser_1 = subparsers_0.add_parser('p1')
parser_1.add_argument('-a', nargs="*")
parser_1.set_defaults(func=f1)

parser_2 = subparsers_0.add_parser('p2')
parser_2.add_argument("-a", help="apple",  default="hello")
parser_2.add_argument("-b", help="banana", action='store_true')
parser_2.set_defaults(func=f2)

parser.add_argument("-c")

args = parser.parse_args()
args.func(args)




