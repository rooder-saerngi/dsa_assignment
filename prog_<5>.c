#include <stdio.h>
#include <stdlib.h>

void bfs();
void dfs();

struct AdjListNode {
    int dest;
    struct AdjListNode *next;
};

struct graph{
    int V;
    struct AdjListNode **array;
};

struct AdjListNode *newAdjListNode(int dest){
    struct AdjListNode * newnode = malloc(sizeof(struct AdjListNode));
    newnode ->dest = dest ;
    newnode ->next = NULL ;
    return newnode;
}

struct graph* createGraph(int V){
    struct graph* Graph = malloc(sizeof(struct graph));
    Graph -> V=V;
    Graph -> array = calloc(V,sizeof(struct AdjListNode*));
    return Graph ;
}

void addEdge(struct graph* Graph , int src , int dest){
    struct AdjListNode* node = newAdjListNode(dest);
    node->next = Graph -> array[src];
    Graph -> array[src] = node ;

    node = newAdjListNode(src);
    node->next = Graph ->array[dest];
    Graph ->array[dest] = node;
}

void printGraph(struct graph* Graph){
    for (int i = 0; i < Graph->V; i++){
        struct AdjListNode* temp = Graph->array[i];
        printf("\n Adjacency list of vertex %d\n head ", i);
        while (temp) {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void bfs(struct graph* Graph, int startVertex) {
    int* visited = calloc(Graph->V, sizeof(int));
    int* queue = malloc(Graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS traversal: ");
    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct AdjListNode* temp = Graph->array[currentVertex];
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

void dfsUtil(struct graph* Graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct AdjListNode* temp = Graph->array[vertex];
    while (temp) {
        int connectedVertex = temp->dest;
        if (!visited[connectedVertex]) {
            dfsUtil(Graph, connectedVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(struct graph* Graph, int startVertex) {
    int* visited = calloc(Graph->V, sizeof(int));
    printf("DFS traversal: ");
    dfsUtil(Graph, startVertex, visited);
    printf("\n");
    free(visited);
}

int main() {
    int V = 5;
    struct graph* Graph = createGraph(V);
    addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 4);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 4);

    printGraph(Graph);
    bfs(Graph, 0);
    dfs(Graph, 0);

    return 0;
}
