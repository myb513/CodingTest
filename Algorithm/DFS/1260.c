#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void addEdge(Node** graph, int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->next = graph[v];
    graph[v] = newNode;
}

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

// 그래프의 DFS 탐색
void dfs(Node** graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    // 인접 리스트를 배열로 옮겨서 정렬
    Node* curr = graph[v];
    int adj[1001];
    int adjCount = 0;
    while (curr != NULL) {
        adj[adjCount++] = curr->vertex;
        curr = curr->next;
    }
    qsort(adj, adjCount, sizeof(int), cmp);

    // 정렬된 인접 리스트 순서대로 방문
    for (int i = 0; i < adjCount; i++) {
        int vertex = adj[i];
        if (!visited[vertex]) {
            dfs(graph, vertex, visited);
        }
    }
}

// 그래프의 BFS 탐색
void bfs(Node** graph, int v, int* visited, int N) {
    int front = 0;
    int rear = 0;
    int queue[1001];

    visited[v] = 1;
    queue[rear++] = v;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        // 작은 번호의 정점부터 방문하도록 인접 리스트를 정렬
        Node* curr = graph[vertex];

        // 인접 리스트를 배열로 옮겨서 정렬
        int adj[1001];
        int adjCount = 0;
        while (curr != NULL) {
            adj[adjCount++] = curr->vertex;
            curr = curr->next;
        }
        qsort(adj, adjCount, sizeof(int), cmp);

        // 정렬된 인접 리스트 순서대로 방문
        for (int i = 0; i < adjCount; i++) {
            int nextVertex = adj[i];
            if (!visited[nextVertex]) {
                queue[rear++] = nextVertex;
                visited[nextVertex] = 1;
            }
        }
    }
}

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    Node** graph = (Node**)malloc((N + 1) * sizeof(Node*));
    for (int i = 0; i <= N; i++) {
        graph[i] = NULL;
    }

    int u, v;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int* visited = (int*)calloc(N + 1, sizeof(int));

    dfs(graph, V, visited);
    printf("\n");

    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }

    bfs(graph, V, visited, N);
    printf("\n");

    // 메모리 해제
    for (int i = 0; i <= N; i++) {
        Node* curr = graph[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph);
    free(visited);

    return 0;
}
