paper = [list(map(int,input().split())) for _ in range(10)]
cnt = [0]*5
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
answer = 26

def dfs(x, y, c):
    global answer
    if y > 9:
        x += 1
        y = 0
    if x > 9:
        answer = min(answer, c)
        return
    if paper[x][y] == 0:
        dfs(x, y+1, c)
    else:
        for k in range(5):
            if cnt[k] == 5:
                continue
            if x + k > 9 or y + k > 9:
                continue
            flag = 0
            for i in range(x, x + k + 1):
                for j in range(y, y + k + 1):
                    if paper[i][j] == 0:
                        flag = 1
                        break
                if flag:
                    break
            if not flag:
                for i in range(x, x + k + 1):
                    for j in range(y, y + k + 1):
                        paper[i][j] = 0
                cnt[k] += 1
                dfs(x, y+1, c+1)
                cnt[k] -= 1
                for i in range(x, x + k + 1):
                    for j in range(y, y + k + 1):
                        paper[i][j] = 1

dfs(0,0,0)
print(answer if answer != 26 else -1)
