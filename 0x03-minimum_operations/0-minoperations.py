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


def minOperations(n): 
    """
    calculates the fewest number of operations needed
    """

    # initial state
    result = 0

    # return 0 if <=  1
    if type(n) is not int or n < 2:
        return result

    # iterate for the remaining numbers
    for i in range(2, n + 1):
        while n % i == 0:
            result += i
            n = n // i
    
    # n is prime 
    if n > 1:
        result += n
        
    # Return the minimum operations to obtain n
    return result