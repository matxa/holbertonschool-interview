#!/usr/bin/python3
"""
minOperations algo file
"""


def minOperations(n):
    """Return the minimun number
    of operation
    """
    min_step = 0
    for i in range(2, n):
        while n % i == 0:
            min_step += i
            n = n / i
    return min_step
