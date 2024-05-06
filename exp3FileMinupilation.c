#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/stat.h>

// int main(){

//     int fd;
//     char buff[10];
//     fd = open("sample.txt", O_RDONLY);

//     if(fd < 0){
        
//         perror("open");
//         return 1;

//     }

//     if(read(fd, buff, 10) != 10){
//         perror("read");
//         return 1;
//     }

//     buff[9] = '\0';
//     printf("read: %s\n" , buff);
//     close(fd);
//     return 0;

// }

// int main(){

//     int fd;
//     char buf[] = "Hello world";

//     fd = open("sample.txt", O_RDWR | O_CREAT, 0666);

//     if(fd < 0){

//     }

//     write(fd, buf, 11);

//     close(fd);
//     return 0;

// }

// int main(){

//     char buf[10];
//     read(0, buf, 10);
//     write(1, buf, 10);

// }


// int main(){

//     int fd;
//     char buf[10];
//     fd = open("sample.txt", O_RDONLY);

//     read(fd, buf, 10);

//     int fd1;
//     fd1 = open("file.txt", O_RDWR | O_CREAT , 0666);

//     write(fd1, buf, 10);

//     lseek(fd,-10, SEEK_END);
//     char a[10]; 
//     read(fd, a, 2);

//     write(1, a, 2);    

// }

// lseek returns the locatio of the file based on its size, so if you want know the size of the file just get the value of last chatacter

// int main(int argc, char *argv[]){
//     int fd;

//     fd = open(argv[1], O_RDONLY);

//     int fileSize = lseek(fd, 0, SEEK_END);

//     printf("%d" , fileSize);
// }


//make dir

int main(int argc, char * argv[]){

    int retValue;
    retValue = mkdir(argv[1], S_IRWXU | S_IRWXG);

}