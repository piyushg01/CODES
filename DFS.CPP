#include<iostream>
#include<vector>

using namespace std;

class Graph {

    int V;
    vector<vector<int>> adj;

public:

    Graph(int vertices) {

        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int vertex,
             vector<bool>& visited) {

        visited[vertex] = true;

        cout << vertex << " ";

        for(int neighbor : adj[vertex]) {

            if(!visited[neighbor]) {

                DFS(neighbor, visited);
            }
        }
    }
};

int main() {

    int V = 5;

    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    vector<bool> visited(V, false);

    int startVertex = 0;

    cout << "DFS Traversal:\n";

    g.DFS(startVertex, visited);

    return 0;
}