#!/usr/bin/python3
"""
a method that calculates the fewest number
of operations needed to result
in exactly "n" "H" charachters in the file.
"""
import math


def minOperations(n):
    if n < 2:
        return 0
    else:
        for i in range(2, n + 1):
            if n % i == 0:
                return minOperations(n // i) + i
