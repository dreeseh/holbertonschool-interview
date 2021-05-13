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

    # initial state
    result = 0

    # if n is impossible to achieve, return 0.
    if type(n) is not int or n <= 1:
        return result

    # iterate for the remaining numbers
    for i in range(2, int(math.sqrt(n))):
        while n % i == 0:
            result += i
            n = n // i

    # for prime numbers
    if n > 1:
        result += n

    # Return the minimum operations to obtain n
    return result
