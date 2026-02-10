# Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a source node to all other nodes.

The process starts by creating a `distances` dictionary. Every node is assigned a distance of infinity to represent that it hasn't been reached yet, except for the `start` node, which is set to **0**. A `visited` list is also created to keep track of completed nodes.

```
def dijkstra(graph,start): 
distances = {vertex : float("inf") for vertex in graph}
distances[start] = 0 visited = [] nodes = list(graph.keys())
```

**Finding the Next Node**
This loop runs until every node is visited. It searches through all nodes to find the one with the smallest known distance that has not been processed yet. This "greedy" choice ensures the algorithm always expands the most promising path first.
```
while len(visited)< len(nodes):
        currentnode = None
        mindist = float('inf')

        for node in nodes :
            if node not in visited and distances[node] < mindist:
                mindist= distances[node]
                currentnode = node
 ```
**Handling unreachable nodes**
If `currentnode` remains `None`, it means the remaining nodes cannot be reached from the starting point. Otherwise, the chosen node is added to the `visited` list so the algorithm does not process the same node twice.
```
if currentnode is None : 
      break 
visited.append(currentnode)
```
**Relaxation of Edges**

The algorithm looks at every neighbor of the `currentnode`. It calculates a `new_path` by adding the current node's distance to the edge weight. If this new total is lower than the neighbor's previously stored distance, the neighbor's distance is updated.

```
for neighbor , weight in graph[currentnode]:
            if neighbor not in visited :
                new_path = distances[currentnode] + weight
                if new_path < distances[neighbor]:
                    distances[neighbor] = new_path```
