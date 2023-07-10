import sys

INF = int(1e9)

def tsp(N, W):
    # dp[i][j]: i번 도시를 방문하고, j의 비트마스크로 표현된 도시들을 방문한 상태에서의 최소 비용
    dp = [[INF] * (1 << N) for _ in range(N)]
    dp[0][1] = 0  # 시작 도시(0)를 방문한 상태

    for visited in range(1, 1 << N):
        for cur in range(N):
            # cur번 도시를 방문한 상태일 때
            if visited & (1 << cur):
                for prev in range(N):
                    # prev번 도시에서 cur번 도시로 갈 수 있는 경우
                    if visited & (1 << prev) and W[prev][cur] != 0:
                        dp[cur][visited] = min(dp[cur][visited], dp[prev][visited - (1 << cur)] + W[prev][cur])

    # 모든 도시를 방문하고 시작 도시(0)로 돌아오는 경로의 비용 계산
    result = INF
    for cur in range(1, N):
        if W[cur][0] != 0:  # cur번 도시에서 시작 도시(0)로 갈 수 있는 경우
            result = min(result, dp[cur][(1 << N) - 1] + W[cur][0])

    return result


# 입력 받기
N = int(sys.stdin.readline())
W = []
for _ in range(N):
    W.append(list(map(int, sys.stdin.readline().split())))

# TSP 알고리즘 수행
min_cost = tsp(N, W)

# 결과 출력
print(min_cost)
