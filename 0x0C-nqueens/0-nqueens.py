#!/usr/bin/python3
""" Its like Ive forgotten everything in a couple short weeks"""

from sys import argv


def nqueens():
    """main for nqueens"""

    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        N = int(argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)

    if (N < 4):
        print("N must be at least 4")
        exit(1)

    board = [[0 for i in range(N)] for j in range(N)]

    col = 0

    positions(board, col, N)


def positions(board, col, N):
    """should work out everything else lets see how that goes"""

    if col == N:
        printSomething(board, N)
    else:
        for i in range(N):
            thing = True
            for j in range(col):
                if check(board, j, i, col):
                    thing = False
            if thing is True:
                board[col] = i
                positions(board, col + 1, N)


def check(board, j, i, col):
    """ It's not uncommon for recursion to fuck my world up"""

    if ((board[j] == i) or (board[j] == i - j + col) or
            (board[j] == j - col + i)):
        return True
    return False


def printSomething(board, N):
    """ At some point it should spit out answers"""

    result = []

    for col in range(N):
        for row in range(N):
            if board[row] == col:
                result.append([col, row])
    print(result)


if __name__ == "__main__":
    nqueens()
