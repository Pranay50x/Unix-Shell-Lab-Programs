#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

void list_directory(const char *dirpath, int show_hidden){
    DIR *dir; 
    struct dirent *entry; 

    dir = opendir(dirpath); 

    if(dir==NULL){
        perror("dir"); 
        exit(EXIT_FAILURE); 
    }

    while((entry=readdir(dir))!=NULL){
        if(!show_hidden && entry->d_name[0]=='.')
            continue;
        printf("%s\n", entry->d_name);
    }
}

int main(int argc, char *argv[]){
    const char *dirpath = ".";
    int show_hidden = 0; 

    for(int i =1;i<argc;i++){
        if(strcmp(argv[i], "-a")==0)
            show_hidden =1; 
        else
            dirpath = argv[i]; 
    }

    list_directory(dirpath,show_hidden); 
    return 0;

}