#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stepCount = 0;   // Global step counter

// Structure for edge
struct Edge {
    int src, dest, weight;
};

// Comparator for sorting
bool compare(Edge a, Edge b) {
    stepCount++;   // comparison step
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
class DisjointSet {
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            stepCount++;  // initialization step
        }
    }

    int find(int x) {
        stepCount++;  // find call
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        stepCount++;  // union call
        int px = find(x);
        int py = find(y);

        if (px != py) {
            parent[py] = px;
            stepCount++;  // union operation
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter source, destination and weight:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        stepCount++;   // input step
    }

    // Sort edges
    sort(edges.begin(), edges.end(), compare);
    stepCount++;   // sorting step

    DisjointSet ds(V);

    int totalWeight = 0;

    cout << "\nEdges in MST:\n";

    for (int i = 0; i < E; i++) {
        stepCount++;  // loop step
        int u = edges[i].src;
        int v = edges[i].dest;

        if (ds.find(u) != ds.find(v)) {
            cout << u << " - " << v << " : " << edges[i].weight << endl;
            totalWeight += edges[i].weight;
            stepCount++;  // adding edge step
            ds.unionSets(u, v);
        }
    }

    cout << "Total Weight: " << totalWeight << endl;
    cout << "Total Steps Counted: " << stepCount << endl;

    return 0;
}

