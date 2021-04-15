#!/usr/bin/python3
""" Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""
from typing import List


def rain(walls: List) -> int:
    """
    Parameters:
        walls: ist of non-negative integers

    Returns:
        int: indicating total amount of rainwater retained
    """
    walls_length = len(walls)
    max_water = 0

    for i in range(1, walls_length - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, walls_length):
            right = max(right, walls[j])
        max_water = max_water + (min(left, right) - walls[i])
    return max_water
