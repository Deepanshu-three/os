 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


//  int main(){

//     int pipeFd[2];

//     char buff[10];

//     pid_t pid;

//     pipe(pipeFd);

//     pid = fork();

//     if(pid < 0){
//         printf("Error occured\n");
//     }

//     if(pid > 0){

//         close(pipeFd[0]);

//         write(pipeFd[1], "Hello hii", 10);

//         close(pipeFd[1]);

//     }
//     else{

//         close(pipeFd[1]);

//         read(pipeFd[0], buff, 10);

//         printf("%s", buff);

//         close(pipeFd[0]);

//     }
// }

//named pipe

int main(){

    int pid, fd1, fd2;
    char buff[11];
    mkfifo("namedPipe", 0666);
    // system("ls -l namedPipe");

    pid = fork();

    if(pid >0 ){

        fd1 = open("namedPipe", O_WRONLY);
        write(fd1, "hello child", 11);
    }

    if(pid == 0){

        fd2 = open("namedPipe", O_RDONLY);
        read(fd2, buff, 11);
        printf("%s", buff);
    }

}