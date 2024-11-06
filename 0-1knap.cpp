#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0-1 Knapsack problem using dynamic programming
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];  // Maximum value for the given capacity W
}

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<int> weights(n), values(n);
    cout << "Enter weights and values of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    int maxProfit = knapsack(W, weights, values, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}