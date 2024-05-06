#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


//pid > 0 parent , pid == 0 child process
// int main(){

//     pid_t pid = getpid();
//     printf("Current process PID is %d\n", pid);
//     printf("Forking a child process...\n");

//     pid_t child_pid = fork();

//     if(child_pid == -1){
//         printf("Failed to fork the child.\n");
//         return 1;
//     }
//     else if(child_pid == 0){
//         printf("Child process id: %d\nParent process id: %d\n", getpid(), getppid());
//         fork();
//     }
//     else{
//         printf("Patrent process id: %d\nChild process id: %d\n", getpid(), getppid());

//     }
// }


// int main(){

//     pid_t pid;

//     int status;

//     pid = fork();
//     if(pid == -1){
//         printf("Error Occured\n");
//     }
//     else if(pid == 0){
//         printf("Child process running\n");
//         sleep(2);
//         printf("Child process exiting\n");
//     }
//     else{
//         printf("Parent Process waiting for child process\n");
//         wait(&status);
//         printf("Child process with the status: %d\n", status);    }

// }

//orphan process
// int main(){

//     pid_t pid;

//     pid= fork();

//     if(pid == -1){
//         printf("Error occured\n");
//     }
//     else if(pid ==0){
//         printf("Child Process is running\n");
//         printf("The parent id of child is %d and id of child is %d\n", getppid(), getpid());
//         sleep(10);
//         printf("Child Process is running\n parent id %d", getppid());


//     }
//     else{
//         printf("Patent Proces is exiting\n");
//         printf("The id of parent is %d\n", getpid());
//         printf("The parent id of parent is %d\n", getppid());
//     }

// }


//zombai process

int main(){

    pid_t pid;

    pid = fork();

    if(pid > 0){
        wait(NULL);
        sleep(20);
        printf("The process ID of the parent is: %d\n", getpid());

    }
    else if(pid == 0){
        printf("The process id of the child is: %d\n", getpid());
    }
    else{
        printf("Forking failed\n");
    }

    return 0;

}