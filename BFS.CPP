#include<iostream>
#include<vector>
#include<queue>

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

    void BFS(int startVertex) {

        vector<bool> visited(V, false);

        queue<int> q;

        visited[startVertex] = true;

        q.push(startVertex);

        while(!q.empty()) {

            int vertex = q.front();
            q.pop();

            cout << vertex << " ";

            for(int neighbor : adj[vertex]) {

                if(!visited[neighbor]) {

                    visited[neighbor] = true;

                    q.push(neighbor);
                }
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

    int startVertex = 0;

    cout << "BFS Traversal:\n";

    g.BFS(startVertex);

    return 0;
}