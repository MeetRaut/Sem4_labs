#include <stdio.h>
void ip(int arr[][10],int p, int r){
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++)
            scanf("%d",&arr[i][j]);
    }
}

int main() {
    int p, r, count = 0, i, j, alloc[10][10], max[10][10], need[10][10], safeseq[10], avail[10], finish[10], terminate = 0;
    
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &p, &r);
    
    for (i = 0; i < p; i++)
        finish[i] = 0;
    
    printf("Enter allocation of resources:\n");
    ip(alloc,p,r);
    printf("Enter the maximum:\n");
    ip(max,p,r);
    
    printf("Enter the available:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);
    
    printf("\nNeed resources matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
}
    while (count < p) {
        for (i = 0; i < p; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }
                if (j == r) {
                    safeseq[count] = i;
                    finish[i] = 1;
                    for (j = 0; j < r; j++) 
                        avail[j] += alloc[i][j];
                    count++;
                    terminate = 0;
                } 
                else 
                    terminate++;
            }
        }
        if (terminate == (p - 1)) {
            printf("safe sequence does not exist.\n");
            break;
        }
    }
    
    if (terminate != (p - 1)) {
        printf("\n\navail resource after completion:\n");
        for (j = 0; j < r; j++) 
            printf("%d\t", avail[j]);
        
        printf("\nsafeseq sequence:\n");
        for (i = 0; i < p; i++) 
            printf("p%d\t", safeseq[i]);
    }
    return 0;}