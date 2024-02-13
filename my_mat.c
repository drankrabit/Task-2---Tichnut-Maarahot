#include <stdio.h>
#include "my_mat.h"
#include <string.h>
#include <limits.h>

#define ROWS 10
#define COLS 10


void A(int graph[10][10]){
    int row, col, weight;
    do{
        do{
            printf("Enter the first node to make the connection for:");
            scanf("%d", &row);
            if((row>=10) || (row <0)) {
                printf("incorrect Input Format\n");
            }
        }while((row>=10) || (row <0));
        do{
           printf("Enter the second node to make the connection for: ");
           scanf("%d", &col);
           if((col>=10) || (col <0)) {
               printf("incorrect Input Format\n");
           }
        }while((col>=10) || (col <0));
        if(row == col) {
            printf("Please use 2 Diffrent Nodes");
        }
    } while(row == col);
    do {
        printf("Enter the weight of passing between the 2 nodes: ");
        scanf("%d", &weight);
        if(weight<0) {
            printf("incorrect Input Format\n");
        }
    }while(weight<0);

    graph[row][col] = weight;
    graph[col][row] = weight;
}

int B(int graph[10][10]) {
    int i,j;
    do{
        do{
            printf("Enter the first node to check for a path from:");
            scanf("%d", &i);
            if((i>=10) || (i <0)) {
                printf("incorrect Input Format\n");
            }
        }while((i>=10) || (i <0));
        do{
           printf("Enter the second node to check for a path from: ");
           scanf("%d", &j);
           if((j>=10) || (j <0)) {
               printf("incorrect Input Format\n");
           }
        }while((j>=10) || (j <0));
    } while(i == j);
    if (ShortestPath(i,j,graph) != -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int C(int graph[10][10]) {
    int i, j;
    do {
        do {
            printf("Enter the first node to calculate a weight from:");
            scanf("%d", &i);
            if (i >= 10 || i < 0) {
                printf("Incorrect Input Format\n");
            }
        } while (i >= 10 || i < 0);
        do {
            printf("Enter the second node to calculate a weight from: ");
            scanf("%d", &j);
            if (j >= 10 || j < 0) {
                printf("Incorrect Input Format\n");
            }
        } while (j >= 10 || j < 0);
        if (i == j) {
            printf("Please use two different nodes\n");
        }
    } while (i == j);
    return ShortestPath(i, j, graph);
}


int ShortestPath(int i, int j, int graph[10][10]) {
    int dist[ROWS][COLS];
    int k, x, y;
    for (x = 0; x < ROWS; x++) {
        for (y = 0; y < COLS; y++) {
            dist[x][y] = graph[x][y];
        }
    }
    for (k = 0; k < COLS; k++) {
        for (x = 0; x < ROWS; x++) {
            for (y = 0; y < COLS; y++) {
                if (dist[x][k] != 0 && dist[k][y] != 0 && dist[x][k] + dist[k][y] < dist[x][y] && x != y) {
                    dist[x][y] = dist[x][k] + dist[k][y];
                }
            }
        }
    }
    if (dist[i][j] == INT_MAX || dist[i][j] == 0)
        return -1;
    else
        return dist[i][j];
}