#include <iostream>
#include <algorithm>
using namespace std;

int stepCount = 0;   // Global step counter

struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator to sort by descending profit
bool compare(Job a, Job b) {
    stepCount++;   // comparison step
    return a.profit > b.profit;
}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    stepCount++;

    Job jobs[n];

    cout << "Enter job id, deadline and profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
        stepCount++;   // input step
    }

    // Sort jobs by profit
    sort(jobs, jobs + n, compare);
    stepCount++;   // sorting step

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        stepCount++;
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
            stepCount++;
        }
    }

    // Create slot array
    int slot[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) {
        slot[i] = -1;
        stepCount++;
    }

    int totalProfit = 0;

    // Assign jobs to slots
    for (int i = 0; i < n; i++) {
        stepCount++;   // outer loop step

        for (int j = jobs[i].deadline; j > 0; j--) {
            stepCount++;   // inner loop step

            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                stepCount += 2;   // assignment + addition
                break;
            }
        }
    }

    cout << "\nSelected Jobs:\n";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1) {
            cout << jobs[slot[i]].id << " ";
            stepCount++;
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
    cout << "Total Steps Counted: " << stepCount << endl;

    return 0;
}

