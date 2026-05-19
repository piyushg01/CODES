#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int travellingSalesmanProblem(
    vector<vector<int>>& graph,
    int start) {

    int V = graph.size();

    vector<int> vertices;

    // Store all vertices except start
    for(int i = 0; i < V; i++) {

        if(i != start)
            vertices.push_back(i);
    }

    int minCost = INT_MAX;

    // Generate all permutations
    do {

        int currentCost = 0;

        int currentVertex = start;

        // Calculate path cost
        for(int vertex : vertices) {

            currentCost +=
            graph[currentVertex][vertex];

            currentVertex = vertex;
        }

        // Return to starting vertex
        currentCost +=
        graph[currentVertex][start];

        minCost =
        min(minCost, currentCost);

    } while(next_permutation(
            vertices.begin(),
            vertices.end()));

    return minCost;
}

int main() {

    vector<vector<int>> graph = {

        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0;

    int minCost =
    travellingSalesmanProblem(
        graph,
        start);

    cout << "Minimum Cost = "
         << minCost;

    return 0;
}