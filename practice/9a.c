#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
    if(argc!=3){
        fprintf(stderr, "Usage %s <source_file> <destination>", argv[0]); 
        exit(EXIT_FAILURE); 
    }

    char buffer[BUFFER_SIZE]; 
    size_t bytesRead;
    FILE *source, *destination; 

    source = fopen(argv[1], "rb"); 

    if(source==NULL){
        perror("err in opening src file"); 
        exit(EXIT_FAILURE); 
    }

    destination = fopen(argv[2], "wb"); 

    if(destination==NULL){
        perror("err writing destination file"); 
        fclose(source); 
        exit(EXIT_FAILURE);
    }

    while((bytesRead=fread(buffer,1,BUFFER_SIZE,source))>0){
        fwrite(buffer,1,bytesRead,destination); 
    }

    fclose(source);
    fclose(destination);

    printf("Files copied successfully\n");  
}