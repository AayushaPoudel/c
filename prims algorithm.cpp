#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int stepCount = 0;   // Global step counter

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    stepCount++;

    int graph[MAX][MAX];

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            stepCount++;   // input step
        }
    }

    int parent[MAX];   // Stores MST
    int key[MAX];      // Minimum weight
    bool mstSet[MAX];  // Included in MST

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
        stepCount += 2;
    }

    key[0] = 0;      // Start from vertex 0
    parent[0] = -1;
    stepCount += 2;

    // MST will have n-1 edges
    for (int count = 0; count < n - 1; count++) {
        stepCount++;   // outer loop step

        int min = INT_MAX, u;

        // Find minimum key vertex not in MST
        for (int v = 0; v < n; v++) {
            stepCount++;   // inner loop step
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
                stepCount += 2;
            }
        }

        mstSet[u] = true;
        stepCount++;

        // Update adjacent vertices
        for (int v = 0; v < n; v++) {
            stepCount++;
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
                stepCount += 2;
            }
        }
    }

    int totalWeight = 0;

    cout << "\nEdges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;
        totalWeight += graph[i][parent[i]];
        stepCount++;
    }

    cout << "Total Weight: " << totalWeight << endl;
    cout << "Total Steps Counted: " << stepCount << endl;

    return 0;
}

