#include <stdio.h>

// Function to calculate maximum value using Fractional Knapsack
double fractionalKnapsack(int capacity, int values[], int weights[], int n) {
    double totalValue = 0.0;
    // Iterate through items
    for (int i = 0; i < n; i++) {
        // If the entire item can fit into the knapsack
        if (weights[i] <= capacity) {
            totalValue += values[i]; // Add the value of the entire item
            capacity -= weights[i]; // Decrease the knapsack capacity
        } else {
            // If only a fraction of the item can fit into the knapsack
            totalValue += (double) capacity / weights[i] * values[i]; // Add fraction of item's value
            break; // Knapsack is full, exit the loop
        }
    }
    return totalValue;
}

int main() {
    // Example items
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);

    // Knapsack capacity
    int capacity = 50;

    // Calculate maximum value
    double maxValue = fractionalKnapsack(capacity, values, weights, n);

    // Print the result
    printf("Maximum value in the knapsack: %.2lf\n", maxValue);

    return 0;
}
