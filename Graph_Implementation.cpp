#include<iostream>
#include<vector>
using namespace std;

class Graph{

    vector<vector<int>> adj;
    int numVertices;
    int numEdges;

    public:

    Graph(int data){
        numVertices = data;  
        //initializing all elements to 0
        adj.resize(numVertices,vector<int>(numVertices,0)); 
    }

    void addEdge (int v, int u){  //for undirected graph
        adj[v][u] = 1;
        adj[u][v] = 1;
    }

    void display_Matrix (){
        for (int i=0; i<numVertices; i++){
            for (int j=0; j<numVertices; j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
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

    g.display_Matrix();

    return 0;
}