#!/usr/bin/python3
""" Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    """
    Parameters:
        walls: ist of non-negative integers

    Returns:
        int: indicating total amount of rainwater retained
    """
    walls_length = len(walls)

    if walls_length < 1 or walls is None:
        return 0

    retained_water = 0
    walls.sort()

    for i in range(walls_length):
        if i + 1 < walls_length:
            if walls[i] > 0 and walls[i + 1] >= walls[i]:
                retained_water += walls[i]

    return retained_water
