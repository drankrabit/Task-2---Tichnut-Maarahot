#include <stdio.h>
#include "my_mat.c"

#define ROWS 10
#define COLS 10

void main() {
    int finish = 0, weight;
    char func;
    int graph[ROWS][COLS] = {INT_MAX};
    for(int i = 0; i < ROWS; i++) {
        graph[i][i] = 0;
    }
    while (!finish) {
        printf("What function would you like to run?");
        scanf(" %c", &func);
        if ((func == 'A') || (func == 'a')) {
            A(graph);
        }
        else if ((func == 'B') || (func == 'b')) {
            if (B(graph) == 1) {
                printf("True\n");
            }
            else {
                printf("False\n");
            }
        }
        else if ((func == 'C') || (func == 'c')) {
            weight = C(graph);
            if (weight == 0) {
                weight = -1;
            }
            printf("%d\n", weight);
        }
        else if ((func == 'D') || (func == 'd')) {
            finish = 1;
        }
    }
}
