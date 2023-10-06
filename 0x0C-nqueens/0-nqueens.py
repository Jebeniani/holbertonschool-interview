#!/usr/bin/python3

import sys


def placing_n(n, row, col, result):
    """
    A recursive function that tries to place a queen in a given row
    by checking all the possible columns in that row.
    """
    while col < n:
        if check_around(row, col, result):
            result.append([row, col])
            if row == n - 1:
                print(result)
                result.pop()
            else:
                placing_n(n, row + 1, 0, result)
        col += 1
    if len(result) > 0:
        result.pop()


def check_around(row, col, result):
    """
    A helper function that checks if a queen can be placed
    in the given row and column without attacking other queens
    in the result list.
    """
    diagR = [i[0] + i[1] for i in result]
    diagL = [i[1] - i[0] for i in result]
    colms = [i[1] for i in result]
    rows = [i[0] for i in result]
    if row in rows or col in colms or row + col in diagR or col - row in diagL:
        return False
    return True


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        sys.exit(1)
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    result = []
    placing_n(n, 0, 0, result)
