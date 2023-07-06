#!/usr/bin/python3
"""
    Returns the fewest number of coins needed to meet the given total amount.

    Args:
        coins (list): A list of coin values.
        total (int): The target total amount.

    Returns:
        int: The fewest number of coins needed to reach the target amount.
             Returns -1 if the target amount cannot be met
             by any combination of coins.
    """


def makeChange(coins, total):
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for amount in range(1, total + 1):
        for coin in coins:
            if coin <= amount:
                dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    if dp[total] == float('inf'):
        return -1

    return dp[total]
