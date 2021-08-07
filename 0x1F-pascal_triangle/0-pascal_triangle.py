#!/usr/bin/python3
"""0. Pascal's Triangle"""


def pascal_triangle(n):
    """Pascal’s triangle
    Parameters
    ----------
    n: int - num of rows
    Return
    ------
    int[]
    """
    result = [[1]]

    if (n <= 0):
        return []

    for row in range(2, n + 1):
        tmp_array = [1]
        for column in range(1, row - 1):
            tmp_array.append(result[-1][column] + result[-1][column - 1])
        tmp_array.append(1)
        result.append(tmp_array)
    return result
