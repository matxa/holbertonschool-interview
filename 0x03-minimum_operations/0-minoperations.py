#!/usr/bin/python3
"""
minOperations algo file
"""


def minOperations(n):
    """Return the minimun number
    of operation
    """
    min = 0
    i = 2
    while i <= n:
        while n % 2 == 0:
            min += i
            n = n / i
        i += 1
    return min
