#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main(){
    int n; 
    printf("Enter the no. of characters to be appended: "); 
    scanf("%d",&n); 

    char buffer[100];
    int new_fd,fd;
    char filename[] = "file.txt";
    ssize_t bytesRead; 

    fd = open(filename, O_RDWR); 

    if(fd==-1){
        perror("err in opening file");
        exit(EXIT_FAILURE); 
    }

    lseek(fd,0,SEEK_END); 

    new_fd = dup(fd); 

    if(new_fd==-1){
        perror("err in duplicating fd");
        close(fd);
        exit(EXIT_FAILURE);
    }

    lseek(fd,-n,SEEK_END); 

    bytesRead = read(fd,buffer,n); 

    if(bytesRead==-1){
        perror("error in readin bytes"); 
        close(fd);
        close(new_fd); 
        exit(EXIT_FAILURE); 
    }

    if(write(new_fd,buffer,bytesRead)!=bytesRead){
        perror("err in writing the bytes");
        close(fd);
        close(new_fd); 
        exit(EXIT_FAILURE); 
    }

    close(fd);
    close(new_fd); 

    printf("%d characters read from the and appended successfully\n",(int)bytesRead); 
    return 0; 

}