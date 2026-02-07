#***How can we implement the undirected graph using adjacency matrix? Write a function that
implement the BFS and DFS technique to traverse through the graph. Demonstrate the
use of your program with example graph.***

* -->Initialize an array containing `V` linked lists or dynamic arrays where `V` represents the total number of vertices.
   ```
  struct Graph {
    int V;
    struct AdjListNode** array;
  };
  ```
* -->Insert the destination vertex into the list corresponding to the source vertex for every edge.
  ```
  struct AdjListNode {
    int dest;
    struct AdjListNode *next;
  };
  ```
* -->Append the source vertex back to the destination vertex list if the graph is undirected.
  ```
  struct AdjListNode *newAdjListNode(int dest){
    struct AdjListNode * newnode = malloc(sizeof(struct AdjListNode));
    newnode ->dest = dest ;
    newnode ->next = NULL ;
    return newnode;
  }
  
  ```
* -->Store a pair consisting of the destination vertex and the edge weight within the list elements for weighted graphs.
  ```
  struct graph* createGraph(int V){
    struct graph* Graph = malloc(sizeof(struct graph));
    Graph -> V=V;
    Graph -> array = calloc(V,sizeof(struct AdjListNode*));
    return Graph ;
  }
  ```
 
