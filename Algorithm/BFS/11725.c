#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct Node {
    int data;
    struct Node* parent;
    int* children;
    int childCount;
} Node;

Node** createTree(int n) {
    Node** tree = (Node**)malloc((n + 1) * sizeof(Node*));
    for (int i = 1; i <= n; i++) {
        tree[i] = (Node*)malloc(sizeof(Node));
        tree[i]->data = i;
        tree[i]->parent = NULL;
        tree[i]->children = NULL;
        tree[i]->childCount = 0;
    }
    return tree;
}

void freeTree(Node** tree, int n) {
    for (int i = 1; i <= n; i++) {
        free(tree[i]->children);
        free(tree[i]);
    }
    free(tree);
}

void setParent(Node** tree, int x, int parent) {
    tree[x]->parent = tree[parent];
}

void BFS(Node** tree, int n) {
    int* visited = (int*)calloc(n + 1, sizeof(int));
    int* queue = (int*)malloc((n + 1) * sizeof(int));
    int front = 0;
    int rear = 0;

    visited[1] = 1;
    queue[rear++] = 1;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < tree[current]->childCount; i++) {
            int child = tree[current]->children[i];
            if (!visited[child]) {
                visited[child] = 1;
                setParent(tree, child, current);
                queue[rear++] = child;
            }
        }
    }

    free(visited);
    free(queue);
}

int main(void) {
    int n;
    scanf("%d", &n);

    Node** tree = createTree(n);

    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        tree[x]->children = (int*)realloc(tree[x]->children, (tree[x]->childCount + 1) * sizeof(int));
        tree[x]->children[tree[x]->childCount++] = y;

        tree[y]->children = (int*)realloc(tree[y]->children, (tree[y]->childCount + 1) * sizeof(int));
        tree[y]->children[tree[y]->childCount++] = x;
    }

    BFS(tree, n);

    for (int i = 2; i <= n; i++) {
        printf("%d\n", tree[i]->parent->data);
    }

    freeTree(tree, n);

    return 0;
}
