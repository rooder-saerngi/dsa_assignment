#***How can we implement the undirected graph using adjacency matrix? Write a function that
implement the BFS and DFS technique to traverse through the graph. Demonstrate the
use of your program with example graph.***

* -->Initialize an array containing `V` linked lists or dynamic arrays where `V` represents the total number of vertices.
   ```
   struct graph* createGraph(int V){
    struct graph* Graph = malloc(sizeof(struct graph));
    Graph -> V=V;
    Graph -> array = calloc(V,sizeof(struct AdjListNode*));
    return Graph ;
  }
  
   ```
* -->Insert the destination vertex into the list corresponding to the source vertex for every edge.
  ```
  struct AdjListNode *newAdjListNode(int dest){
    struct AdjListNode * newnode = malloc(sizeof(struct AdjListNode));
    newnode ->dest = dest ;
    newnode ->next = NULL ;
    return newnode;
  }
  ```
* -->Append the source vertex back to the destination vertex list if the graph is undirected.
  ```
  node = newAdjListNode(src);
  node->next = Graph ->array[dest];
  Graph ->array[dest] = node;
  ```
* -->Store a pair consisting of the destination vertex and the edge weight within the list elements for weighted graphs.
  ```
  struct AdjListNode {
    int dest;
    int weight; // Added for weighted graphs
    struct AdjListNode *next;
  };
  ```
 #***explanation of BFS and DFS in the code***
 ***BFS***
  * BFS uses a Queue and a visited array to explore neighbors layer by layer.
    ```
    void bfs(struct graph* Graph, int startVertex) {
    int* visited = calloc(Graph->V, sizeof(int));
    int* queue = malloc(Graph->V * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    ```
    * When you visit a vertex, you look at its linked list `(Graph->array[currentVertex]).`
    * You loop through that list. If a neighbor isn't marked in the visited array, you add it to the `queue`
    * Because it's a queue (First-In, First-Out), vertex 0's immediate neighbors (1 and 4) are processed completely before the code moves on to neighbors of 1 or 4
***DFS***
 * DFS is split into two parts:
  * a setup function `*(dfs)*`
  * a recursive worker function `*(dfsUtil)*`.




 
