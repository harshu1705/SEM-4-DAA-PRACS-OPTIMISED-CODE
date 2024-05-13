#include <stdio.h>

int minCoins(int purchase_amount, int coins[], int num_coins) {
    int num_used_coins = 0;

    for (int i = num_coins - 1; i >= 0; i--) {
        while (purchase_amount >= coins[i]) {
            purchase_amount -= coins[i];
            num_used_coins++;
        }
    }

    return num_used_coins;
}

void printCombination(int purchase_amount, int coins[], int num_coins) {
    printf("Combination of coins for minimum number:\n");
    for (int i = num_coins - 1; i >= 0; i--) {
        while (purchase_amount >= coins[i]) {
            printf("%d ", coins[i]);
            purchase_amount -= coins[i];
        }
    }
    printf("\n");
}

int main() {
    int purchase_amount = 13;
    int coins[] = {1, 5, 12};  // Changed the coins array
    int num_coins = sizeof(coins) / sizeof(coins[0]);

    int min_num_coins = minCoins(purchase_amount, coins, num_coins);
    printf("Minimum number of coins needed: %d\n", min_num_coins);

    printCombination(purchase_amount, coins, num_coins);

    return 0;
}
