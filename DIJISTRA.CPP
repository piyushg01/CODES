#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

typedef pair<int, int> pii;

void dijkstra(int V,
              vector<vector<pii>>& adj,
              int source) {

    priority_queue<
    pii,
    vector<pii>,
    greater<pii>> pq;

    vector<int> dist(V, INT_MAX);

    dist[source] = 0;

    pq.push({0, source});

    while(!pq.empty()) {

        int currentDist = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        for(auto edge : adj[u]) {

            int v = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[v]) {

                dist[v] =
                dist[u] + weight;

                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest Distances from Source "
         << source << ":\n";

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

    vector<vector<pii>> adj(V);

    adj[0].push_back({1,10});
    adj[0].push_back({4,5});

    adj[1].push_back({2,1});
    adj[1].push_back({4,2});

    adj[2].push_back({3,4});

    adj[3].push_back({0,7});
    adj[3].push_back({2,6});

    adj[4].push_back({1,3});
    adj[4].push_back({2,9});
    adj[4].push_back({3,2});

    int source = 0;

    dijkstra(V, adj, source);

    return 0;
}