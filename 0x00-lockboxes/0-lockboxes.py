#!/usr/bin/python3
"""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """true = all boxes unlocked, false = all boxes NOT unlocked"""
    box_number = 0
    keys = [0]

    # make sure lists are valid
    if boxes is None or boxes == []:
        return False

    # comparing key values to box numbers in the lists
    for i in keys:
        for j in boxes[i]:
            if j not in keys:
                if j < len(boxes):
                    keys.append(j)
    if len(keys) != len(boxes):
        # keys do not match the box numbers
        return False

    # passes the above algorithm
    return True
