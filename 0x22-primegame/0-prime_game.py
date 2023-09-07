def isWinner(x, nums):
    """
    Determine the winner of a game with given rounds and number sets.

    Args:
        x (int): Number of rounds.
        nums (list): List of integers representing the sets for each round.

    Returns:
        str or None: The name of the player who won the most rounds
    """
    if not nums or x < 1:
        return None

    max_set_value = max(nums)
    sieve = [True for _ in range(max(max_set_value + 1, 2))]

    for i in range(2, int(pow(max_set_value, 0.5)) + 1):
        if not sieve[i]:
            continue
        for j in range(i * i, max_set_value + 1, i):
            sieve[j] = False
    sieve[0] = sieve[1] = False

    prime_count = 0
    for i in range(len(sieve)):
        if sieve[i]:
            prime_count += 1
        sieve[i] = prime_count

    maria_wins = 0
    for max_n in nums:
        maria_wins += sieve[max_n] % 2 == 1

    if maria_wins * 2 == len(nums):
        return None
    if maria_wins * 2 > len(nums):
        return "Maria"
    return "Ben"
