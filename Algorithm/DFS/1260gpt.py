from collections import deque

n, m, v = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

for i in range(1, n+1):
    graph[i].sort()

def dfs(v):
    visited[v] = True
    print(v, end=' ')
    for adj in graph[v]:
        if not visited[adj]:
            dfs(adj)

def bfs(v):
    queue = deque([v])
    visited[v] = True

    while queue:
        node = queue.popleft()
        print(node, end=' ')
        for adj in graph[node]:
            if not visited[adj]:
                visited[adj] = True
                queue.append(adj)

dfs(v)
print()
visited = [False] * (n+1)
bfs(v)
print()
