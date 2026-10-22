/*
================================================================================
EXPERIMENT - 7
Aim: Find the Shortest Path using Dijkstra’s Algo.
Tools / Apparatus: O.S.: Microsoft Windows (any) / Linux / DOS
Packages: Turbo/Borland/GNU - C/C++

Procedure:
1. Assign to every node a distance value. Set it to zero for our initial node
   and to infinity for all other nodes.
2. Mark all nodes as unvisited. Set initial node as current.
3. For current node, consider all its unvisited neighbors and calculate their
   tentative distance (from the initial node). For example, if current node (A)
   has distance of 6, and an edge connecting it with another node (B) is 2,
   the distance to B through A will be 6+2=8. If this distance is less than the
   previously recorded distance (infinity in the beginning, zero for the initial
   node), overwrite the distance.
4. When we are done considering all neighbors of the current node, mark it as
   visited. A visited node will not be checked ever again; its distance recorded
   now is final and minimal.
5. If all nodes have been visited, finish. Otherwise, set the unvisited node with
   the smallest distance (from the initial node) as the next "current node" and
   continue from step 3.
================================================================================
*/

#include <iostream>
using namespace std;

const int INF = 999999;

// Function to find the unvisited node with the minimum tentative distance
int minDistance(int dist[], bool visited[], int V) {
    int minVal = INF;
    int minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print reconstructed path from source to target
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        cout << j;
        return;
    }
    printPath(parent, parent[j]);
    cout << " -> " << j;
}

// Dijkstra's Shortest Path Algorithm
void dijkstra(int **graph, int V, int src) {
    int *dist = new int[V];       // Shortest distance from src to each node
    bool *visited = new bool[V];  // true if node is visited (final distance known)
    int *parent = new int[V];     // Array to reconstruct shortest path

    // Step 1: Assign distance 0 for initial node and infinity for all other nodes
    // Step 2: Mark all nodes as unvisited
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Step 5: Pick unvisited node with smallest distance
        int u = minDistance(dist, visited, V);
        if (u == -1 || dist[u] == INF) break;

        // Step 4: Mark the picked node as visited
        visited[u] = true;

        // Step 3: For current node u, consider all unvisited neighbors and update tentative distance
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Display shortest paths and distances
    cout << "\n===========================================================\n";
    cout << "  SHORTEST PATH RESULTS FROM SOURCE NODE " << src << "\n";
    cout << "===========================================================\n";
    cout << "Vertex\tDistance\tPath\n";
    cout << "-----------------------------------------------------------\n";

    for (int i = 0; i < V; i++) {
        cout << i << "\t";
        if (dist[i] == INF) {
            cout << "INF\t\tNo Path\n";
        } else {
            cout << dist[i] << "\t\t";
            printPath(parent, i);
            cout << "\n";
        }
    }
    cout << "-----------------------------------------------------------\n";

    delete[] dist;
    delete[] visited;
    delete[] parent;
}

int main() {
    int V;

    cout << "========================================\n";
    cout << "      DIJKSTRA'S SHORTEST PATH\n";
    cout << "========================================\n";

    cout << "Enter the number of vertices in the graph: ";
    cin >> V;

    // Dynamically allocate 2D Adjacency Matrix
    int **graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    int choice;
    cout << "\nChoose input method:\n";
    cout << "1. Enter Adjacency Matrix (" << V << " x " << V << ")\n";
    cout << "2. Enter number of edges and edge details (u, v, weight)\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter the " << V << " x " << V << " adjacency matrix (0 if no edge):\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cin >> graph[i][j];
            }
        }
    } else {
        int edges;
        cout << "Enter total number of edges: ";
        cin >> edges;
        cout << "Enter each edge as (source destination weight):\n";
        for (int i = 0; i < edges; i++) {
            int u, v, w;
            cout << "  Edge " << i + 1 << ": ";
            cin >> u >> v >> w;
            if (u >= 0 && u < V && v >= 0 && v < V) {
                graph[u][v] = w;
            }
        }
    }

    int src;
    cout << "\nEnter the source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    dijkstra(graph, V, src);

    for (int i = 0; i < V; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
