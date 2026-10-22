/*#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph,
         vector<bool>& visited)
{
    visited[node] = true;

    cout << node << " ";

    for (int neighbour : graph[node])
    {
        if (!visited[neighbour])
        {
            DFS(neighbour, graph, visited);
        }
    }
}

int main()
{
    int V = 6;

    vector<vector<int>> graph(V);

    graph[0] = {1, 2};       // A
    graph[1] = {0, 3, 4};    // B
    graph[2] = {0, 5};       // C
    graph[3] = {1};          // D
    graph[4] = {1};          // E
    graph[5] = {2};          // F

    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    DFS(0, graph, visited);

    return 0;
}*/


#include<iostream>
#include<vector>
using namespace std;

class Graph{

    vector<vector<int>> adj;
    int numVertices;
    int numEdges;
    vector<bool> visited; //for DFS traversal
    public:

    Graph(int data){
        numVertices = data; 
        //initializing all elements to false
        visited.resize(numVertices,false); 
        //initializing all elements to 0
        adj.resize(numVertices,vector<int>(numVertices,0)); 
    }

    void addEdge (int v, int u){  //for undirected graph
        adj[v][u] = 1;
        adj[u][v] = 1;
    }

    void DFS_Traversal (int vertex){

        if (visited[vertex] == true){
            return;
        }
        else{
            cout<<vertex<<" ";
            visited[vertex] = true;
        }

        for (int i=0; i<numVertices; i++){
            if(adj[vertex][i] == 1){
                DFS_Traversal(i); //recurssion for DFS_Traversal
            }
        }
    }
};

int main (){
    
    cout<<"Enter total number of vertices and edges respectively"<<endl;
    int x,y;
    cin>>x>>y;

    Graph g (x);

    cout<<"Enter the pair vertices having an edge between them"<<endl;
    for(int i=0; i<y; i++){
        int v,u;
        cin>>v>>u;
        g.addEdge(v,u);
    }  

    cout<<"Enter the vertex from where you want to start TRAVERSAL:"<<endl;
    int m;
    cin>>m;
    g.DFS_Traversal(m);

    return 0;
}
