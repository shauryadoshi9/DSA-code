#include <iostream>
using namespace std;

void createGraph(int graph[10][10], int n)
{
    int edges;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;

        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;   // For undirected graph
    }
}

void displayGraph(int graph[10][10], int n)
{
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[10][10] = {0};

    createGraph(graph, n);

    displayGraph(graph, n);

    return 0;
}