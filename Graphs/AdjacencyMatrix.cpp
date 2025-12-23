#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;   // adjacency matrix

public:
    // Constructor
    Graph(int v) {
        V = v;
        adj.resize(V, vector<int>(V, 0));  // V x V matrix with 0
    }

    // Add edge (undirected)
    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Display matrix
    void display() {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.display();

    return 0;
}
