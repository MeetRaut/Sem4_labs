#include <stdio.h>
#include <stdlib.h>

void sort(int req[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (req[j] > req[j + 1]){
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }     
        }
    }
}

void FCFS(int req[], int head, int n){
    int ans = abs(head - req[0]);
    printf("seek sequence:%d ",head);
    for (int i = 0; i < n - 1; i++){
        printf("%d ", req[i]);
        ans += abs(req[i] - req[i + 1]);
    }
    printf("\n%d\n",ans);
}

void SCAN(int req[], int head, int trackMin, int trackMax, int n){
    int temp[20 + 1];
    int ptr = 0;
    for (int i = 0; i < n; i++){
        if (req[i] >= head)
            temp[ptr++] = req[i];
    }
    temp[ptr++] = (trackMax);
    for (int i = n - 1; i >= 0; i--){
        if (req[i] < head)
            temp[ptr++] = (req[i]);
    }
    FCFS(temp, head, n + 1);
}

void C_SCAN(int req[], int head, int trackMin, int trackMax, int n){
    int temp[20 + 2], ptr = 0;
    for (int i = 0; i < n; i++){
        if (req[i] >= head)
            temp[ptr++] = req[i];
    }
    temp[ptr++] = (trackMax);
    temp[ptr++] = (trackMin);
    for (int i = 0; i < n; i++){
        if (req[i] < head)
            temp[ptr++] = (req[i]);
    }
    FCFS(temp, head, n + 2);
}

int main(){
    int trackMin, trackMax,n, head;
    printf("enter trackmin and trackmax:");
    scanf("%d%d", &trackMin, &trackMax);
    printf("enter number of tracks:");
    scanf("%d", &n);
    printf("enter current track position:");
    scanf("%d",&head);
    int req[20];
    printf("enter sequence:");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("\nFCFS:\n");
    FCFS(req, head, n);
    sort(req,n);
    printf("\nSCAN:\n");
    SCAN(req, head, trackMin, trackMax, n);
    printf("\nC_SCAN:\n");
    C_SCAN(req, head, trackMin, trackMax, n);
    return 0;}