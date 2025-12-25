#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

// BFS visits all nearby nodes first using a queue before going deeper.

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int v) {
        V = v;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q; // using queue for bfs

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            cout << v << " ";

            for(int u : adj[v]) {
                if(!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS Traversal: ";
    g.BFS(0);

    return 0;
}
