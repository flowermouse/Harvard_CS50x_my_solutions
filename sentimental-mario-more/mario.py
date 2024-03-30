# TODO
n = 0
while n <= 0 or n > 8:
    try:
        n = int(input('Height:'))
    except ValueError:
        print('not a integer')
for i in range(n):
    for j in range(2 * n + 2):
        if j < n - i - 1 or j == n or j == n + 1:
            print(' ', end='')
        elif j >= n + 1 and j - n - 2 > i:
            nothing = 'do nothing'
        else:
            print('#', end='')
    print('')
