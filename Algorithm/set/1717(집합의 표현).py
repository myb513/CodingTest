import sys

def find(x):
    if x == parent[x]:
        return x
    else:
        p = find(parent[x])
        parent[x] = p
        return parent[x]

def union(x, y):
    x = find(x)
    y = find(y)

    if x != y:
        parent[y] = x

n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n+1)]

for _ in range(m):
    op, a, b = map(int, sys.stdin.readline().split())
    if op == 0:
        union(a, b)
    elif op == 1:
        if find(a) == find(b):
            print('YES')
        else:
            print('NO')
