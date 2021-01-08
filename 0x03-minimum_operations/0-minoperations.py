#!/usr/bin/python3
"""minOperations algo file"""


def minOperations(n):
    """
    Find the minimum operations to get from 1 to n
    using only 2 methods cp and paste.
    """
    h, cp, p = 1, 1, 1

    if (n < 2):
        return 0

    while p < n and p != n:
        if n % p == 0 and p != 1 and p + cp < n:
            cp = p
            h += 1
            p += cp
        else:
            p += cp
        h += 1
    return h
