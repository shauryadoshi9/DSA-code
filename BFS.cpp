#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph{

    vector<vector<int>> adj;
    int numVertices;
    int numEdges;
    vector<bool> visited; //for BFS traversal
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

     void BFS_Traversal(int vertex) {

        queue<int> bfsQueue;

        visited[vertex] = true;
        bfsQueue.push(vertex);

        while (!bfsQueue.empty()) {
            // Dequeue a vertex from the queue and print it
            int currentVertex = bfsQueue.front();
            cout << currentVertex << " ";
            bfsQueue.pop();

            // Visit all adjacent vertices of the dequeued vertex that have not been visited
            for (int i=0; i<numVertices; i++) {
                if (adj[currentVertex][i] == 1 && visited[i] == false) {
                    visited[i] = true;
                    bfsQueue.push(i);
                }
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
    g.BFS_Traversal(m);

    return 0;
}