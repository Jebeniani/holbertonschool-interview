#!/usr/bin/python3
"""nqueens.py"""
import sys


def is_safe(board, row, col, n):
    """
    Check if it's safe to place a queen at the given position
    """
    for i in range(row):
        if board[i][col] == 1:
            return False

    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i, j = i - 1, j - 1

    i, j = row, col
    while i >= 0 and j < n:
        if board[i][j] == 1:
            return False
        i, j = i - 1, j + 1

    return True


def solve(board, row, n):
    """
    Recursively solve the N-Queens problem
    """
    if row == n:
        solutions.append(["." * col + "Q" + "." * (n - col - 1)for col in board])
        return

    for col in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1
            solve(board, row + 1, n)
            board[row][col] = 0


def print_solutions(solutions):
    """
    Print the solutions in the required format
    """
    for solution in solutions:
        for row in solution:
            print(row)
        print()


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    board = [[0 for _ in range(n)] for _ in range(n)]

    solve(board, 0, n)
    print_solutions(solutions)
