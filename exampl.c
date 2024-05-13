#include <stdio.h>

int minCoins(int purchase_amount, int coins[], int num_coins, int dp[]) {
    dp[0] = 0; // Base case
    
    for (int i = 1; i <= purchase_amount; i++) {
        dp[i] = purchase_amount + 1; // Initialize to a large value
        
        // Try each coin denomination
        for (int j = 0; j < num_coins; j++) {
            if (coins[j] <= i) {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }
    
    return dp[purchase_amount];
}

void printCombination(int purchase_amount, int coins[], int num_coins, int dp[]) {
    if (dp[purchase_amount] == purchase_amount + 1) {
        printf("No combination found.\n");
        return;
    }
    
    printf("Combination of coins for minimum number:\n");
    int amount_left = purchase_amount;
    while (amount_left > 0) {
        for (int i = 0; i < num_coins; i++) {
            if (coins[i] <= amount_left && dp[amount_left] == dp[amount_left - coins[i]] + 1) {
                printf("%d ", coins[i]);
                amount_left -= coins[i];
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int purchase_amount = 13;
    int coins[] = {1, 5, 12};
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int dp[purchase_amount + 1];
    
    int min_num_coins = minCoins(purchase_amount, coins, num_coins, dp);
    printf("Minimum number of coins needed: %d\n", min_num_coins);
    
    printCombination(purchase_amount, coins, num_coins, dp);
    
    return 0;
}

