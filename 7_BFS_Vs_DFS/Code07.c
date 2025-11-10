#include <stdio.h>

int graph[10][10];
int visited[10];
int n = 9;   // 3x3 grid

void addEdge(int u, int v) {
    graph[u][v] = graph[v][u] = 1;
}

void BFS(int start) {
    int q[10], front = 0, rear = 0;
    for(int i=1;i<=n;i++) visited[i]=0;
    visited[start] = 1; q[rear++] = start;

    printf("\nBFS: ");
    while(front < rear) {
        int node = q[front++];
        printf("%d ", node);
        for(int i=1;i<=n;i++) {
            if(graph[node][i] && !visited[i]) {
                visited[i]=1;
                q[rear++]=i;
            }
        }
    }
}

void DFS(int start) {
    visited[start]=1;
    printf("%d ", start);
    for(int i=1;i<=n;i++) {
        if(graph[start][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    // 3x3 grid connections
    addEdge(1,2); addEdge(1,4);
    addEdge(2,3); addEdge(2,5);
    addEdge(3,6); addEdge(4,5);
    addEdge(4,7); addEdge(5,6);
    addEdge(5,8); addEdge(6,9);
    addEdge(7,8); addEdge(8,9);

    printf("Start from node 1");
    BFS(1);

    for(int i=1;i<=n;i++) visited[i]=0;
    printf("\nDFS: ");
    DFS(1);
    return 0;
}