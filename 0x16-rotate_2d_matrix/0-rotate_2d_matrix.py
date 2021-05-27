#!/usr/bin/python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """Given an n x n 2D matrix,
    rotate it 90 degrees clockwise
    Params
    ------
      matrix: list
    """
    _le = len(matrix[0])
    for _out in range(_le):
        for _in in range(_out, _le - _out - 1):
            temp = matrix[_out][_in]
            matrix[_out][_in] = matrix[_le - 1 - _in][_out]
            matrix[_le - 1 - _in][_out] = matrix[_le - 1 - _out][_le - 1 - _in]
            matrix[_le - 1 - _out][_le - 1 - _in] = matrix[_in][_le - 1 - _out]
            matrix[_in][_le - 1 - _out] = temp
