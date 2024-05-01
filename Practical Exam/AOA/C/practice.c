#include<stdio.h>

int minimum(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

void printSol(int distance[], int v){
    for(int i = 0; i < v; i++){
        printf("For vertex %d: %d\n", i, distance[i]);
    }
}

void djikstra(int distance[], int cost[][100], int v){
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(cost[i][j] != 0){
                distance[j] = minimum(distance[j], (distance[i] + cost[i][j]));
            }
        }
    }
    printSol(distance, v);
}

void main(){
    int v;
    int cost[100][100];
    int distance[100];

    printf("Enter number of vertex: ");
    scanf("%d", &v);

    printf("Enter adj matrix:\n");
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            printf("For (%d,%d): ", i, j);
            scanf("%d", &cost[i][j]);
        }
    }

    distance[0] = 0;
    for(int i = 1; i < v; i++){
        distance[i] = 999;
    }

    djikstra(distance, cost, v);
}