#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

void removeEmptyFiles(char *dirpath){

    DIR *dir;
    struct stat fileStat;
    struct dirent *entry;
    char filePath[1024];

    dir = opendir(dirpath);

    if(dir==NULL){
        perror("dir");
        exit(EXIT_FAILURE);
    }

    while((entry=readdir(dir))!=NULL){
        snprintf(filePath, sizeof(filePath), "%s/%s",dirpath, entry->d_name);

        //status error
        if(stat(filePath, &fileStat)==-1){
            perror("stat");
            exit(EXIT_FAILURE);
        }


        if(S_ISREG(fileStat.st_mode) && fileStat.st_size == 0){
            if(unlink(filePath)==0)
                printf("Removed empty file: %s\n", entry->d_name);
            else
                perror("Err removing file");
        }

    }
    closedir(dir);
}


int main(int argc, char *argv[]){
        if(argc!=2){
            fprintf(stderr, "Usage: %s<directory>\n",argv[0]);
            exit(EXIT_FAILURE);
        }

        removeEmptyFiles(argv[1]);
        return 0;
}