"""
Project Euler Problem 7
=======================

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
that the 6th prime is 13.

What is the 10001st prime number?
"""

primes = [2]
found = 1

c = 3
while found < 10001:
    for i in range(2, int(c**.5)+1):
        if c % i == 0:
            break
    else:
        # if previous loop doesn't break, then run this code.
        found += 1
        primes.append(c)
    c += 2

print(primes[-1])
