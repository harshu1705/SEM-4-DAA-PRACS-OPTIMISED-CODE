#include <stdio.h>
#include <limits.h>

// Number of cities in the problem
#define N 4

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the minimum cost to travel to all cities starting from the first city
int tsp(int graph[N][N], int visited, int current) {
    // If all cities have been visited, return the cost of returning to the first city
    if (visited == (1 << N) - 1) {
        return graph[current][0];
    }

    int minCost = INT_MAX;

    // Try all unvisited cities as the next city to visit
    for (int next = 0; next < N; next++) {
        if (!(visited & (1 << next))) {
            // Calculate the cost of visiting the next city and recurse
            int cost = graph[current][next] + tsp(graph, visited | (1 << next), next);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

// Driver function
int main() {
    // Example graph representing the cost of traveling between cities
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Start from the first city (index 0) and mark it as visited
    int startCity = 0;
    int visited = 1 << startCity;

    // Calculate the minimum cost of traveling to all cities
    int minCost = tsp(graph, visited, startCity);

    printf("Minimum cost of traveling salesman problem: %d\n", minCost);

    return 0;
}