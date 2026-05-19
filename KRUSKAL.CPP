#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {

    int u, v, weight;
};

bool compare(Edge a, Edge b) {

    return a.weight < b.weight;
}

class DisjointSet {

    vector<int> parent;

public:

    DisjointSet(int n) {

        parent.resize(n);

        for(int i = 0; i < n; i++) {

            parent[i] = i;
        }
    }

    int find(int x) {

        if(parent[x] == x)
            return x;

        return parent[x] =
               find(parent[x]);
    }

    void unionSets(int a, int b) {

        parent[find(a)] = find(b);
    }
};

void kruskalMST(int V,
                vector<Edge>& edges) {

    sort(edges.begin(),
         edges.end(),
         compare);

    DisjointSet ds(V);

    int minCost = 0;

    cout << "Selected Edges in MST:\n";

    for(Edge e : edges) {

        int u = e.u;
        int v = e.v;
        int w = e.weight;

        if(ds.find(u) != ds.find(v)) {

            ds.unionSets(u, v);

            cout << u
                 << " -- "
                 << v
                 << " == "
                 << w << endl;

            minCost += w;
        }
    }

    cout << "\nMinimum Cost = "
         << minCost << endl;
}

int main() {

    int V = 5;

    vector<Edge> edges = {

        {0,1,2},
        {0,3,6},
        {1,2,3},
        {1,3,8},
        {1,4,5},
        {2,4,7}
    };

    kruskalMST(V, edges);

    return 0;
}