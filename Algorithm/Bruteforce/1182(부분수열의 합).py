def subset_sum(arr, N, S):
    result = 0

    # DFS를 이용해 부분 수열의 합 계산
    def dfs(idx, total):
        nonlocal result
        if idx >= N:
            return
        total += arr[idx]
        if total == S:
            result += 1
        dfs(idx + 1, total - arr[idx])  # 해당 인덱스를 뽑지 않는 경우
        dfs(idx + 1, total)  # 해당 인덱스를 뽑는 경우

    dfs(0, 0)
    return result


N, S = map(int, input().split())
arr = list(map(int, input().split()))
print(subset_sum(arr, N, S))
