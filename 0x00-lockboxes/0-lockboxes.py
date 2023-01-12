#!/usr/bin/python3
"""You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
Write a method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    seen = [False] * len(boxes)
    seen[0] = True
    stack = [0]

    while stack:
        node = stack.pop()
        for keys in boxes[node]:
            if not seen[keys]:
                seen[keys] = True
                if keys < len(boxes):
                    stack.append(keys)
    return all(seen)
