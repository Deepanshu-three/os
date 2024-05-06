#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>

int main(){

    DIR *dp;
    struct dirent *direntPt;
    dp = opendir("dir1");
    if(dp == NULL){
        printf("Error\n");
    }  

    while((direntPt=readdir(dp)) != NULL){
        printf("%s\n", direntPt -> d_name);
        // printf("%ld\n", direntPt -> d_ino);
    } 
    closedir(dp);
    return 0;
}