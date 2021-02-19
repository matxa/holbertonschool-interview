#!/usr/bin/python3
"""Validate UTF-8"""


def validUTF8(data):
    """Return if valid
    else return False
    """
    num_of_bytes = 0
    for num in data:
        num = num & 255
        if num_of_bytes == 0:
            if num >= 0 and num <= 127:
                continue
            if num <= 223:
                num_of_bytes += 1
                continue
            if num <= 239:
                num_of_bytes += 2
                continue
            if num <= 255:
                num_of_bytes += 3
                continue
            return False
        if num >= 128 and num <= 192:
            num_of_bytes -= 1
            continue
        else:
            return False
    if num_of_bytes == 0:
        return True
    return False
