#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>

void list_dir(const char *dirpath){
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirpath);

    if(dir==NULL){
        perror("err in opening dir");
        exit(EXIT_FAILURE);
    }

    while((entry=readdir(dir))!=NULL){

        if(entry->d_name[0] =='.'){
            continue;
        }

        printf("%s\n",entry->d_name);
    }

    closedir(dir);
}

int main(){
    const char *cur_dir = ".";

    list_dir(cur_dir);

    return 0;
}