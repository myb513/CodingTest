import sys
from collections import deque

T = int(sys.stdin.readline())

for _ in range(T):
    p = sys.stdin.readline()
    n = int(sys.stdin.readline())
    queue = sys.stdin.readline()[1:-2] # remove '[' and ']'
    if queue:
        queue = deque(map(int, queue.split(','))) # if not empty, map to int
    else:
        queue = deque() # if empty, declare an empty deque

    is_reversed = False
    is_error = False

    for command in p:
        try:
            if command == 'R':
                is_reversed = not is_reversed # change the flag for reverse
            elif command == 'D':
                if is_reversed:
                    queue.pop() # if reversed, remove the last element
                else:
                    queue.popleft() # if not reversed, remove the first element
        except IndexError:
            is_error = True # if the deque is empty
            print('error')
            break

    if not is_error:
        if is_reversed:
            queue.reverse() # if reversed, change the order
        print('[' + ','.join(map(str, queue)) + ']')
