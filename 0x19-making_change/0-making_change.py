#!/usr/bin/python3
"""Given a pile of coins of different values,
determine the fewest number of coins needed
to meet a given amount total.
"""
import sys


def makeChange(coins, total):
    """Make Change
    Params
    ------
    coins
      array - of all coins
    total
      int
    Return
    -----
      min_amount_of_coins
    """

    if total <= 0:
        return 0

    saved_change = 0
    added_change = 0
    coins = reversed(sorted(coins))

    if total <= 0:
        return (0)

    for coin in coins:
        while saved_change + coin <= total:
            added_change += 1
            saved_change += coin

    if saved_change != total:
        return (-1)
    return added_change
