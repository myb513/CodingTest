import sys

def find_shortest_paths(V, E, roads):
    # 인접 행렬 초기화
    INF = float('inf')
    graph = [[INF] * V for _ in range(V)]

    # 주어진 도로 정보로 인접 행렬 갱신
    for a, b, c in roads:
        graph[a - 1][b - 1] = c

    # 플로이드-와샬 알고리즘을 사용하여 최단 거리 구하기
    for k in range(V):
        for i in range(V):
            for j in range(V):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

    return graph


def find_min_cycle(V, graph):
    min_cycle = float('inf')

    # 각 정점에서 시작하여 다른 모든 정점으로 가는 최단 거리 계산
    for i in range(V):
        for j in range(V):
            if i != j and graph[i][j] != float('inf'):
                # 시작 정점과 종료 정점이 같은 경우, 그리고 최소 사이클인지 확인
                cycle_length = graph[i][j] + graph[j][i]
                min_cycle = min(min_cycle, cycle_length)

    if min_cycle == float('inf'):
        return -1
    else:
        return min_cycle


# 입력 받기
V, E = map(int, sys.stdin.readline().split())

roads = [tuple(map(int, sys.stdin.readline().split())) for _ in range(E)]


# 최단 거리 구하기
graph = find_shortest_paths(V, E, roads)



# 최소 사이클 길이 출력
min_cycle = find_min_cycle(V, graph)
print(min_cycle)
