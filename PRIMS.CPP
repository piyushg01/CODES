#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

void primMST(int V,
             vector<vector<pii>>& adj) {

    priority_queue<
    pii,
    vector<pii>,
    greater<pii>> pq;

    vector<bool> visited(V, false);

    pq.push({0, 0});

    int totalCost = 0;

    cout << "Edges in MST:\n";

    while(!pq.empty()) {

        int weight = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if(visited[u])
            continue;

        visited[u] = true;

        totalCost += weight;

        cout << "Visited Vertex: "
             << u
             << " Weight: "
             << weight << endl;

        for(auto edge : adj[u]) {

            int v = edge.first;
            int w = edge.second;

            if(!visited[v]) {

                pq.push({w, v});
            }
        }
    }

    cout << "\nTotal Minimum Cost = "
         << totalCost << endl;
}

int main() {

    int V = 5;

    vector<vector<pii>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    primMST(V, adj);

    return 0;
}