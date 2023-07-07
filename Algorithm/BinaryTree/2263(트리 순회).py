import sys

def construct_preorder(inorder, postorder):
    if not inorder or not postorder:
        return []

    preorder = []
    stack = [(inorder, postorder, 0, 0, len(inorder))]

    while stack:
        inorder, postorder, in_start, post_start, length = stack.pop()

        if length == 0:
            continue

        # 포스트오더의 마지막 노드가 루트 노드
        root_val = postorder[post_start + length - 1]
        preorder.append(root_val)

        # 루트 노드의 인덱스를 기준으로 왼쪽과 오른쪽 서브트리 분할
        root_idx = inorder.index(root_val)

        left_length = root_idx - in_start
        right_length = length - left_length - 1

        # 오른쪽 서브트리부터 스택에 추가
        stack.append((inorder, postorder, root_idx + 1, post_start + left_length, right_length))
        # 왼쪽 서브트리 스택에 추가
        stack.append((inorder, postorder, in_start, post_start, left_length))

    return preorder


# 입력 받기
n = int(sys.stdin.readline())
inorder = list(map(int, sys.stdin.readline().split()))
postorder = list(map(int, sys.stdin.readline().split()))

# 프리오더 구성
preorder = construct_preorder(inorder, postorder)

# 결과 출력
print(' '.join(map(str, preorder)))
