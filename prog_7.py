
def dijkstra(graph,start):
    distances = {vertex : float("inf") for vertex in graph}
    distances[start] = 0
    visited = []

    nodes = list(graph.keys())

    while len(visited)< len(nodes):
        currentnode = None
        mindist = float('inf')

        for node in nodes :
            if node not in visited and distances[node] < mindist:
                mindist= distances[node]
                currentnode = node

        if currentnode is None :
            break

        visited.append(currentnode)

        for neighbor , weight in graph[currentnode]:
            if neighbor not in visited :
                new_path = distances[currentnode] + weight
                if new_path < distances[neighbor]:
                    distances[neighbor] = new_path
    return distances

if __name__ == "__main__":
    example = {
        'A': [('B',15),('C',3)],
        'B': [('C', 1), ('D', 2)],
        'C': [('B', 4), ('D', 8), ('E', 2)],
        'D': [('E', 7)],
        'E': [('D', 19)]
    }
    output = dijkstra(example,'A')
    print("shortest path from A:",output)
