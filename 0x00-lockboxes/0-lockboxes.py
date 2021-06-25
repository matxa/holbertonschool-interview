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
    box_numbers = [box_index for box_index in range(1, len(boxes))]
    available_keys = boxes[0]
    for box in boxes:
        if boxes.index(box) in available_keys:
            available_keys.extend(box)

    available_keys = list(set(available_keys))
    if 0 in available_keys:
        available_keys.remove(0)

    print(f"box numbers - {box_numbers}\nkeys - {available_keys}")

    if set(available_keys) == set(box_numbers):
        return True
    else:
        return False
    

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')
boxes = [[1, 4, 6], [2, 0], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes), "\t: True")
print('-----------------------------')
boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes),  "\t: False")
print('-----------------------------')
boxes = [[1,3],[3,0,1],[2],[0]]
print(canUnlockAll(boxes),  "\t: False")
print('-----------------------------')
