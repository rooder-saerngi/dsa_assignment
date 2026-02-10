#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Graph {
    int V;
    int **matrix;
    int *visited;
};

int minDistance(int dist[],bool sptSet[], int V){
    int min = 1e9, min_index;
    for (int v = 0 ; v < V ; v++){
        if (sptSet[v]== false && dist[v]<= min){
            min = dist[v], min_index =v;
        }
    }return min_index;

}
void dijkstra(struct Graph *G , int src){
    int V = G->V;
    int dist[V];
    bool sptSet[V];

    for (int i = 0 ; i < V ; i++){
        dist[i]= 1e9;
        sptSet[i]= false;
    }
    dist[src] = 0;
    for (int count = 0; count < V-1; count ++){
        int u = minDistance(dist, sptSet ,V );
        sptSet[u] = true;

        for (int v = 0 ; v<V ;v++){
            if (!sptSet[v] && G->matrix[u][v] && dist[u] != 1e9 && dist[u] + G->matrix[u][v]<dist[v]){
                dist[v]= dist[u] + G->matrix[u][v]; 
            }
        }
    }
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);

}

int main() {
    int v_count = 5;
    struct Graph G;
    G.V = v_count;

    G.matrix = malloc(v_count * sizeof(int *));
    for (int i = 0; i < v_count; i++) {
        
        G.matrix[i] = calloc(v_count, sizeof(int));
    }

    G.matrix[0][1] = 10;
    G.matrix[0][3] = 30;
    G.matrix[1][2] = 50;
    

    dijkstra(&G, 0);

    return 0;
}
