#include<iostream>
#include<list>
using namespace std;

class graph{
    int V;
    list<int>* l;

public:
    graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){ //undirected
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void display(){
        for(int i = 0; i < V; i++){
            cout << i << ": ";
            for(int neigh : l[i]){
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    ~graph(){
        delete[] l;
    }
};

int main(){
    // Create a graph with 5 vertices (0 to 4)
    graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Display adjacency list
    g.display();

    return 0;
}
