#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int main(){

//     key_t key = ftok("shmfile",65);

//     int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

//     char *str = (char *) shmat(shmid, (void *)0, 0);

//     printf("write data: ");
//     gets(str);

//     printf("data written in memory\n%s", str);

// }
// int main()
// {
//     int i;
//     void *shared_memory;
//     char buff[100];
//     int shmid;
//     shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT); // creates shared memory segment with key>printf("Key of shared memory is %d\n",shmid);
//     shared_memory = shmat(shmid, NULL, 0);               // process attached to shared memory segment
//     printf("Process attached at %p\n", shared_memory);   // this prints the address where the seg>
//     printf("Enter some data to write to shared memory\n");
//     read(0, buff, 100);          // get some input from user
//     strcpy(shared_memory, buff); // data written to shared memory
//     printf("You wrote : %s\n", (char *)shared_memory);
// }

int main()
{
int i;
void *shared_memory;
char buff[100];
int shmid;
shmid=shmget((key_t)2345, 1024, 0666);
printf("Key of shared memory is %d\n",shmid);
shared_memory=shmat(shmid,NULL,0); //process attached to shared memory segment
printf("Process attached at %p\n",shared_memory);
printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}