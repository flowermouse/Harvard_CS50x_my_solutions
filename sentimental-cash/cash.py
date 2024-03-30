# TODO
from cs50 import get_float


def greedy_cash(n):
    if n < 5:
        return n
    elif n in range(5, 10):
        return 1 + greedy_cash(n - 5)
    elif n in range(10, 25):
        return 1 + greedy_cash(n - 10)
    elif n >= 25:
        return 1 + greedy_cash(n - 25)
n = -1
while n < 0:
    n = get_float('Change owed: ')
print(int(greedy_cash(100 * n)))
