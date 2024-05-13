#include <stdio.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0-1 Knapsack Problem using Dynamic Programming
int knapsack(int knapsackCapacity, int weights[], int values[], int numberOfItems) {
    int dp[numberOfItems + 1][knapsackCapacity + 1];

    // Initialize DP table
    for (int i = 0; i <= numberOfItems; i++) {
        for (int w = 0; w <= knapsackCapacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Return the maximum value that can be put in the knapsack
    return dp[numberOfItems][knapsackCapacity];
}

int main() {
    // Example items
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int knapsackCapacity = 50;
    int numberOfItems = sizeof(values) / sizeof(values[0]);

    // Calculate maximum value that can be obtained
    int maxValue = knapsack(knapsackCapacity, weights, values, numberOfItems);

    // Print the result
    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}
