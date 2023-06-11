#!/usr/bin/python3
# 0-print_list_integer.py


def print_list_integer(my_list=[]):
    """P ri nt  al l in teg er s of a lis t."""
    for i in range(len(my_list)):
        print("{:d}".format(my_list[i]))
