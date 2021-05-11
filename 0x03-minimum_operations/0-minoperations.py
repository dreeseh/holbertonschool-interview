#!/usr/bin/python3
import math


def minOperations(n): 
    """ minOperations module finds the minimum number
    of operations needed,
    returns an integer,
    returns 0 if operation is impossible.
    """

    # initial state
    dp = 0

    # return 0 if <=  1
    if type(n) is not int or n < 2:
        return dp

    # iterate for the remaining numbers
    for i in range(2, int(math.sqrt(n) + 1)):
        while n % i == 0:
            dp += i
            n = n // i
    
    # n is prime 
    if n > 1:
        dp += n
        
    # Return the minimum operations to obtain n
    return dp