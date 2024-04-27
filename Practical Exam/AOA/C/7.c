// Floyd Warshall

#include<stdio.h>
#include<stdlib.h>
int cost[10][10], dist[10][10], n;

int minimum(int a, int b){
    return (a<b) ? a:b;
}

void path(){
    int i, j, k;
    for(k=0; k<n; k++){
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                dist[i][j]=minimum(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}

void main(){
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the allocation matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &cost[i][j]);
            dist[i][j]=cost[i][j];
        }
    }

    path();

    printf("\nThe final Distance matrix showing the shortest distances between every pair of vertices is:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%d	", dist[i][j]);
        }
        printf("\n");
    }
}