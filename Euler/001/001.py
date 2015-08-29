"""
Project Euler Problem 1
=======================

If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
"""

from math import ceil

def oneToN(n):
    return (n*(n+1))//2

print(3*oneToN(ceil(1000/3)-1)+5*oneToN(ceil(1000/5)-1)-15*oneToN(ceil(1000/15)-1))
