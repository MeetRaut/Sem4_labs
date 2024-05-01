#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t mutexlock;
int value = 0;

void *producer() {
    sem_wait(&mutexlock);
    printf("\nProducer allowed to enter critical section");

    // CRITICAL SECTION
    for (int i = 0; i < 10; i++) {
        printf("\nvalue: %d", ++value);
    }

    sem_post(&mutexlock);
    printf("\nProducer has set semaphore...");
}

void *consumer() {
    sem_wait(&mutexlock);
    printf("\nConsumer allowed to enter critical section");

    // CRITICAL SECTION
    for (int i = 0; i < 10; i++) {
        printf("\nvalue: %d", value--);
    }

    sem_post(&mutexlock);
    printf("\nConsumer has set semaphore...");
}

int main() {
    sem_init(&mutexlock, 0, 1);
    pthread_t p1, p2;
    pthread_create(&p1, NULL, &producer, NULL);
    pthread_create(&p2, NULL, &consumer, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    sem_destroy(&mutexlock);
    return 0;
}