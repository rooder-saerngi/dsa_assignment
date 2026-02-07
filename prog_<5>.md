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
 
  #***BFS***
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
  
  #***DFS***

  
 * DFS is split into two parts:
   * a setup function `*(dfs)*`
   * a recursive worker function `*(dfsUtil)*`.
 
 * As soon as the while loop finds a neighbor that hasn't been visited, it stops what it's doing and calls dfsUtil on that neighbor.
 
 * This is "recursive." The computer remembers where it left off. Once the code hits a dead end (a node with no unvisited neighbors), it backtracks to the previous function call and continues the while loop to check the next neighbor.
 
 * f 0 is connected to 1 and 4, it goes 0 ***to*** 4. At 4, it sees a neighbor (like 3) and goes 4 ***to*** 3 before it ever goes back to check 1.


#***output of my code***
```
Adjacency list of vertex 0
 head -> 4-> 1

 Adjacency list of vertex 1
 head -> 4-> 3-> 2-> 0

 Adjacency list of vertex 2
 head -> 3-> 1

 Adjacency list of vertex 3
 head -> 4-> 2-> 1

 Adjacency list of vertex 4
 head -> 3-> 1-> 0

BFS traversal: 0 4 1 3 2 
DFS traversal: 0 4 3 2 1
```






 
