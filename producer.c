#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t mutex, full, empty;

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100; // generate a random item
        sem_wait(&empty);    // wait until buffer is not full
        sem_wait(&mutex);    // acquire the lock
        
        buffer[in] = item;   // add item to the buffer
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE; // increment in index
        
        sem_post(&mutex);    // release the lock
        sem_post(&full);     // signal that buffer is not empty
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full);     // wait until buffer is not empty
        sem_wait(&mutex);    // acquire the lock
        
        item = buffer[out];  // consume item from the buffer
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE; // increment out index
        
        sem_post(&mutex);    // release the lock
        sem_post(&empty);    // signal that buffer is not full
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;
    
    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);
    
    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    
    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    
    return 0;
}