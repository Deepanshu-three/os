#include <stdio.h>
#include <pthread.h>
#include <string.h>

// void *func(){

//     printf("In thread function\n");
//     pthread_exit("Exit thread function\n");

// }

// int main(){

//     pthread_t thread1;
//     void * a;
//     printf("In main thread\n");
//     pthread_create(&thread1, NULL, func, NULL);
//     pthread_join(thread1, &a);
//     printf("%s\n",(char *) a);
//     return 0;

// }


// void * func(void * a){


//     printf("%s\n" , (char *) a);

//     pthread_exit(NULL);

// }


// int main(){

//     pthread_t thread;
//     char * a = "Hello world";
//     pthread_create(&thread, NULL, func,(void*)a);
//     pthread_join(thread, NULL);

// }


// void * fact(void * a){
//     int * n = (int *) a;
//     int *facto = malloc(sizeof(int));
//     *facto = 1;
//     for(int i =1 ; i<= *n; i++){
//         *facto *= i;
//     }

//     pthread_exit(facto);
// }

// int main(){

//     pthread_t thread1, thread2;

//     int a = 5;
//     int *factAns;
//     pthread_create(&thread1, NULL, fact, (void *)&a);
//     pthread_join(thread1, (void **)&factAns);

//     printf("%d\n",*factAns);

// }

void * fact(void * a){
    int * n = (int *) a;
    int size = sizeof(n);

    printf("%d\n", size);
    for(int i =0 ; i< size; i++){
        printf("%d\n", n[i]);
    }

    pthread_exit(NULL);
}

int main(){

    pthread_t thread1, thread2;

    int a[5] = {1,2,3,4,5};

    pthread_create(&thread1, NULL, fact, (void *)a);
    pthread_join(thread1, NULL);



}