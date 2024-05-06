// #include <stdio.h>
// #include <pthread.h>
// #include <unistd.h>

// int shared =1;

// void *function1(){
//     int t1 = shared;
//     t1++;
//     sleep(1);
//     shared = t1;
// }

// void *function2(){
//     int t2 = shared;
//     t2--;
// sleep(1);
//     shared = t2;
// }


// int main(){

//     pthread_t thread1, thread2;

//     pthread_create(&thread1, NULL, function1, NULL);
//     pthread_create(&thread2, NULL, function2, NULL);

//     pthread_join(thread1,NULL);
//     pthread_join(thread2, NULL);

//     printf("The value of shared variable is: %d\n" , shared);
// }


// #include <stdio.h>
// #include <pthread.h>
// #include <unistd.h>

// int shared =1;

// pthread_mutex_t lock;


// void *function1();
// void *function2();


// int main(){

//     pthread_t thread1, thread2;
//     pthread_mutex_init(&lock, NULL);

//     pthread_create(&thread1, NULL, function1, NULL);
//     pthread_create(&thread2, NULL, function2, NULL);

//     pthread_join(thread1,NULL);
//     pthread_join(thread2, NULL);

//     printf("The value of shared variable is: %d\n" , shared);
// }

// void *function1(){
//     int t1;

//     printf("Thread 1 trying to azquire lock 1\n");
//     pthread_mutex_lock(&lock);
    
//     t1 = shared;
//     t1++;
//     sleep(1);
//     shared = t1;
//     printf("Value of shared value is updated\n");

//     pthread_mutex_unlock(&lock);
//     printf("Thread 1 released the lock\n");
// }

// void *function2(){
//     int t2;

//     printf("Thread 2 trying to azquire lock 1\n");
//     pthread_mutex_lock(&lock);
    
//     t2 = shared;
//     t2--;
//     sleep(1);
//     shared = t2;
//     printf("Value of shared value is updated\n");

//     pthread_mutex_unlock(&lock);
//     printf("Thread 2 released the lock\n");
// }

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int shared = 1;

sem_t lock;


void *function1();
void *function2();


int main(){

    pthread_t thread1, thread2;
    sem_init(&lock, 0, 1);

    pthread_create(&thread1, NULL, function1, NULL);
    pthread_create(&thread2, NULL, function2, NULL);

    pthread_join(thread1,NULL);
    pthread_join(thread2, NULL);

    printf("The value of shared variable is: %d\n" , shared);
}

void *function1(){
    int t1;

    printf("Thread 1 trying to azquire lock 1\n");
    sem_wait(&lock);
    
    t1 = shared;
    t1++;
    sleep(1);
    shared = t1;
    printf("Value of shared value is updated\n");

    sem_post(&lock);
    printf("Thread 1 released the lock\n");
}

void *function2(){
    int t2;

    printf("Thread 2 trying to azquire lock 1\n");
    sem_wait(&lock);
    
    t2 = shared;
    t2--;
    sleep(1);
    shared = t2;
    printf("Value of shared value is updated\n");

    sem_post(&lock);
    printf("Thread 2 released the lock\n");
}

