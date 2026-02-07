#***How can we implement the undirected graph using adjacency matrix? Write a function that
implement the BFS and DFS technique to traverse through the graph. Demonstrate the
use of your program with example graph.***

* -->Initialize an array containing `V` linked lists or dynamic arrays where `V` represents the total number of vertices.
* -->Insert the destination vertex into the list corresponding to the source vertex for every edge.
* -->Append the source vertex back to the destination vertex list if the graph is undirected.
* -->Store a pair consisting of the destination vertex and the edge weight within the list elements for weighted graphs.
  ```
  struct Graph {
    int V;
    struct AdjListNode** array;
  };
  ```
