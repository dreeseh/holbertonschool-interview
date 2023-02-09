#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
1. Copy All
2. Paste
Given a number n, write a method that calculates the fewest number
of operations needed to result in exactly n H characters in the file.
Returns an integer.
If n is impossible to achieve, return 0.
"""
import math


def minOperations(n):
    """
    calculates the fewest number of operations needed
    """

    answer = 0
    i = 2
    while n > 1:
        while n % i == 0:
            answer += i
            n /= i
        i += 1
    return answer
