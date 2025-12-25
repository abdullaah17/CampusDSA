#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

// DFS visits a node, then keeps going deeper using a stack before coming back.

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

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s; // using stack for dfs

        s.push(start);  // start from here

        while(!s.empty()) { // keep going
            int v = s.top(); // take a node
            s.pop();

            if(visited[v]) continue; // skip if already seen

            visited[v] = true; // mark visited
            cout << v << " "; // show visit

            for(int u : adj[v]) // go to neighbors
                s.push(u);
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS Traversal: ";
    g.DFS(0);

    return 0;
}
