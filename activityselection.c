#include <stdio.h>

// Function to perform activity selection
void activitySelection(int start[], int finish[], int n) {
    // The first activity is always selected
    int i = 0;
    printf("Selected activities:\n");
    printf("(%d, %d)\n", start[i], finish[i]);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity has a start time greater than or equal to the finish time of the previously selected activity,
        // then select it
        if (start[j] >= finish[i]) {
            printf("(%d, %d)\n", start[j], finish[j]);
            i = j;
        }
    }
}

int main() {
    // Example activities
    int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finish[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n = sizeof(start) / sizeof(start[0]);

    // Perform activity selection
    activitySelection(start, finish, n);

    return 0;
}
