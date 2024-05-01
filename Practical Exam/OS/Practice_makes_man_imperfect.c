#include<stdio.h>
#include<stdlib.h>

int Full = 0;
int Empty = 10;
int x = 0;
int Mutex = 1;

void producer(){
    --Mutex;
    ++Full;
    --Empty;
    ++x;
    printf("The producer produces item %d.\n", x);
    ++Mutex;
}

void consumer(){
    --Mutex;
    --Full;
    ++Empty;
    printf("The producer produces item %d.\n", x);
    --x;
    ++Mutex;

}

void main(){
    int n;
    printf("1. Producer    2. Consumer    3. Exit\n");

    for(int i = 1; i > 0; i++){
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch(n){
            case 1: 
                if(Mutex == 1 && Empty != 0){
                    producer();
                    break;
                }else{
                    printf("Buffer is full\n");
                    break;
                }
            case 2: 
                if(Mutex == 1 && Full != 0){
                    consumer();
                    break;
                }else{
                    printf("Buffer is Empty\n");
                    break;
                }
            case 3: 
                printf("Exiting ...\n");
                exit(1);
        }
    }
}