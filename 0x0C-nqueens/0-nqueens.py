#!/usr/bin/python3
"""The N queens puzzle"""
from sys import argv, stdout


def ERROR_EXIT(message):
    """STDOUT ERR message"""
    stdout.write("{}\n".format(message))
    exit(1)


if argv.__len__() == 2:
    try:
        N = int(argv[1])
        if N < 4:
            ERROR_EXIT("N must be at least 4")
    except Exception as e:
        ERROR_EXIT("N must be a number")
else:
    ERROR_EXIT("Usage: nqueens N")
