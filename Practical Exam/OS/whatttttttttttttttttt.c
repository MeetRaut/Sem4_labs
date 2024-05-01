#include<stdio.h>
#include<stdlib.h>

int full = 0, empty = 10, x = 0, mutex = 1;

void Producer(){
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces the item %d\n", x);
    ++mutex;
}

void Consumer(){
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes the item %d\n", x);
    x--;
    ++mutex;
}

int main(){
    int n;
    printf("\n1. Press 1 for Producer \n2. Press 2 for Consumer \n3. Exit");

    for (int i = 1; i > 0; i++){
        printf("\nEnter the choice: ");
        scanf("%d", &n);
        switch (n){
            case 1:
                if ((mutex == 1) && (empty != 0))
                    Producer();
                else
                    printf("Buffer is full\n");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    Consumer();
                else
                    printf("Buffer is empty\n");
                break;
            case 3:
                printf("Exiting......\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!!!!\n");
                break;
        }
    }
    return 0;
}