#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store item details
struct Item {
    int value;
    int weight;
};

// Global step counter
int stepCount = 0;

// Comparator function to sort by value/weight ratio
bool compare(Item a, Item b) {
    stepCount++;  // Counting comparison step
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    stepCount++; // Function call step

    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);
    stepCount++; // Sorting step

    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++) {
        stepCount++; // Loop iteration step

        if (capacity >= items[i].weight) {
            // Take whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
            stepCount += 3; // Counting operations
        } else {
            // Take fraction of item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            stepCount += 2; // Counting operations
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        stepCount++; // Counting input step
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value in knapsack = " << maxValue << endl;
    cout << "Total steps counted = " << stepCount << endl;

    return 0;
}

