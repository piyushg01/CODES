#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Edge {

    int source;
    int destination;
    int weight;
};

void bellmanFord(int V,
                 int E,
                 vector<Edge>& edges,
                 int source) {

    vector<int> dist(V, INT_MAX);

    dist[source] = 0;

    // Relax edges V-1 times
    for(int i = 1; i <= V - 1; i++) {

        for(int j = 0; j < E; j++) {

            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if(dist[u] != INT_MAX &&
               dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    // Check Negative Cycle
    for(int j = 0; j < E; j++) {

        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;

        if(dist[u] != INT_MAX &&
           dist[u] + w < dist[v]) {

            cout << "Negative Weight Cycle Detected\n";

            return;
        }
    }

    cout << "\nShortest Distances:\n";

    for(int i = 0; i < V; i++) {

        cout << "Vertex "
             << i
             << " -> "
             << dist[i]
             << endl;
    }
}

int main() {

    int V = 5;
    int E = 8;

    vector<Edge> edges = {

        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    int source = 0;

    bellmanFord(V, E, edges, source);

    return 0;
}