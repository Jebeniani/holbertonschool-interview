# Coin Change Algorithm
The Coin Change Algorithm is a function that determines the fewest number of coins needed to meet a given total amount. It takes a list of coin values and a target total as input, and returns the minimum number of coins required to reach the target amount. This algorithm utilizes dynamic programming to optimize the solution.

## Function Signature 

```py
def makeChange(coins, total):
    """
    Returns the fewest number of coins needed to meet the given total amount.

    Args:
        coins (list): A list of coin values.
        total (int): The target total amount.

    Returns:
        int: The fewest number of coins needed to reach the target amount.
             Returns -1 if the target amount cannot be met by any combination of coins.
    """
```

## Input
The function makeChange takes the following parameters:

* coins: A list of coin values available for use.
* total: The target total amount to be achieved.

## Output

The function returns an integer representing the fewest number of coins needed to meet the target total amount. If the target amount cannot be reached using the available coins, the function returns -1.
