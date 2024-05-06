#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared = 0;

pthread_mutex_t lock;



void * func1(){

    pthread_mutex_lock(&lock);
    int a = shared;
    a++;
    sleep(2);
    shared = a;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);

}

void * func2(){
    pthread_mutex_lock(&lock);
    int a = shared;
    a--;
    shared = a;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);


}


int main(){

    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);


    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread1, NULL);
    

    printf("The value of shared variable is %d", shared);

}