//fractional knapsack using greedy method
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure for an item with weight and value
struct Item {
    int weight;
    int value;

    // Constructor
    Item(int w, int v)
    {
        weight=w;
        value=v;
    }
};

// Comparison function to sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum profit in the fractional knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    double maxProfit = 0.0;

    // Traverse through all sorted items
    for (auto& item : items) {
        if (W == 0) break;

        // If the item can fit in the knapsack completely
        if (item.weight <= W) {
            W -= item.weight;
            maxProfit += item.value;
        } 
        // If only a fraction of the item can fit
        else {
            maxProfit += item.value * ((double)W / item.weight);
            W = 0;  // Knapsack is full
        }
    }

    return maxProfit;
}

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<Item> items;
    cout << "Enter weight and value for each item:\n";
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    double maxProfit = fractionalKnapsack(W, items);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}