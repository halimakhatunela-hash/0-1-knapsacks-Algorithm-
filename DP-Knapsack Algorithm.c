#include <stdio.h>

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n + 1], weight[n + 1];

    for (int i = 1; i <= n; i++) {
        printf("Enter profit and weight of item %d: ", i);
        scanf("%d %d", &profit[i], &weight[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i] <= w) {
                int include = profit[i] + dp[i - 1][w - weight[i]];
                int exclude = dp[i - 1][w];
                dp[i][w] = (include > exclude) ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    printf("Selected Items: ");
    int w = W;

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= weight[i];
        }
    }

    printf("\n");

    return 0;
}
