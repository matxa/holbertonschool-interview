#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you.
    Each box is numbered sequentially from 0 to n - 1 and
    each box may contain keys to the other boxes.

    * boxes is a list of lists
    * A key with the same number as a box opens that box
    * You can assume all keys will be positive integers
    * The first box boxes[0] is unlocked
    * Empty boxes don't have a key to open other boxes
    * Return True if all boxes can be opened, else return False
    """
    if not boxes:
        return False
    if len(boxes) == 1:
        if type(boxes[0]) != list:
            return False
    for b in boxes:
        if type(b) != list:
                return False
    box_numbers = [num for num in range(1, len(boxes))]
    box_keys = []
    for index_of_box in range(1, len(boxes)):
        for box in boxes:
            if type(box) != list:
                return False
            if boxes.index(box) != index_of_box:
                for key in box:
                    if key == index_of_box:
                        box_keys.append(key)
    if set(box_numbers) == set(box_keys):
        return True
    else:
        return False
