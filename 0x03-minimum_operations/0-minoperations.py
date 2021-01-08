#!/usr/bin/python3
"""minOperations algo file"""


def minOperations(n):
    """
    Find the minimum operations to get from 1 to n
    using only 2 methods copy and paste.
    """
    if n < 2:
        return 0
    min_step = 0
    for i in range(2, n):
        while n % i == 0:
            min_step += i
            n = n / i
    return min_step
