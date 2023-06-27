from itertools import combinations

N, M = map(int, input().split())
city = [list(map(int, input().split())) for _ in range(N)]

houses = []
chickens = []
for i in range(N):
    for j in range(N):
        if city[i][j] == 1:
            houses.append((i, j))
        elif city[i][j] == 2:
            chickens.append((i, j))

def chicken_distance(house, chicken):
    return abs(house[0] - chicken[0]) + abs(house[1] - chicken[1])

min_distance = float('inf')

for chicken_comb in combinations(chickens, M):
    total_distance = 0
    for house in houses:
        total_distance += min(chicken_distance(house, chicken) for chicken in chicken_comb)
    min_distance = min(min_distance, total_distance)

print(min_distance)
