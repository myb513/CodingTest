#include <stdio.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define MAX_NODES 26

// 이진 트리 배열 구현
typedef struct BinaryTree {
    char nodes[MAX_NODES];
    int left[MAX_NODES];
    int right[MAX_NODES];
} BinaryTree;

// 전위 순회 함수
void preorderTraversal(BinaryTree* tree, int node) {
    if (node == -1) {
        return;
    }

    printf("%c", tree->nodes[node]);
    preorderTraversal(tree, tree->left[node]);
    preorderTraversal(tree, tree->right[node]);
}

// 중위 순회 함수
void inorderTraversal(BinaryTree* tree, int node) {
    if (node == -1) {
        return;
    }

    inorderTraversal(tree, tree->left[node]);
    printf("%c", tree->nodes[node]);
    inorderTraversal(tree, tree->right[node]);
}

// 후위 순회 함수
void postorderTraversal(BinaryTree* tree, int node) {
    if (node == -1) {
        return;
    }

    postorderTraversal(tree, tree->left[node]);
    postorderTraversal(tree, tree->right[node]);
    printf("%c", tree->nodes[node]);
}

int main() {
    int N;
    scanf("%d", &N);

    BinaryTree tree;
    for (int i = 0; i < N; i++) {
        char node, leftChild, rightChild;
        scanf(" %c %c %c", &node, &leftChild, &rightChild);

        int index = node - 'A';
        tree.nodes[index] = node;
        tree.left[index] = (leftChild == '.') ? -1 : leftChild - 'A';
        tree.right[index] = (rightChild == '.') ? -1 : rightChild - 'A';
    }

    // 전위 순회
    preorderTraversal(&tree, 0);
    printf("\n");

    // 중위 순회
    inorderTraversal(&tree, 0);
    printf("\n");

    // 후위 순회
    postorderTraversal(&tree, 0);
    printf("\n");

    return 0;
}
