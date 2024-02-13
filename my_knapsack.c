#include <stdio.h>

int max(int a, int b);
int knapsack(int weights[], int values[], int selected_bool[]);

#define MAX_ITEMS 5
#define MAX_WEIGHT 20

int main() {
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];
    int selected_bool[MAX_ITEMS] = {0};
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Enter the weight of the %d item: ", i + 1);
        scanf("%d", &weights[i]);
    }
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Enter the value of the %d item: ", i + 1);
        scanf("%d", &values[i]);
    }
    int max_profit = knapsack(weights, values, selected_bool);
    printf("Maximum profit: %d\n", max_profit);
    printf("Selected items: ");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (selected_bool[i] == 1) {
            printf("%c ", 'A' + i);
        }
    }
    printf("\n");

    return 0;
}

int knapsack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int dp[MAX_WEIGHT + 1] = {0};
    for (w = 0; w <= MAX_WEIGHT; w++) {
        for (i = 0; i < MAX_ITEMS; i++) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }
    w = MAX_WEIGHT;
    for (i = MAX_ITEMS - 1; i >= 0; i--) {
        while (w >= weights[i] && dp[w] == dp[w - weights[i]] + values[i]) {
            selected_bool[i] = 1;
            w -= weights[i];
        }
    }
    return dp[MAX_WEIGHT];
}

int max(int a, int b) {
    if(a>b) {
        return a;
    }
    else {
        return b;
    }
}