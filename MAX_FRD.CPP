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

    void addFriend(int u, int v) {

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void displayFriends() {

        for(int i = 0; i < V; i++) {

            cout << "User " << i << " -> ";

            for(int friendNode : adj[i]) {

                cout << friendNode << " ";
            }

            cout << endl;
        }
    }

    void maxFriends() {

        int maxDegree = -1;
        int user = -1;

        for(int i = 0; i < V; i++) {

            int degree = adj[i].size();

            if(degree > maxDegree) {

                maxDegree = degree;
                user = i;
            }
        }

        cout << "\nUser with Maximum Friends: "
             << user << endl;

        cout << "Total Friends: "
             << maxDegree << endl;
    }
};

int main() {

    int V = 5;

    Graph g(V);

    g.addFriend(0, 1);
    g.addFriend(0, 2);
    g.addFriend(1, 2);
    g.addFriend(1, 3);
    g.addFriend(1, 4);

    cout << "Social Network:\n";

    g.displayFriends();

    g.maxFriends();

    return 0;
}