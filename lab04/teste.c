#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> //define uma coleção de símbolos e estruturas typedef id_t --> Identificador geral, pode conter um pid_t ou um gid_t.

#define MAX_COUNT 200
#define BUF_SIZE 100

int main(int argc, char* argv[]){
    int id = fork();
    char Buffer[BUF_SIZE];
    
    for (int i = 1; i <= 5; i++){
        printf("Hello world from id : %d\n", id);

        if  (id == 0 ){
            printf("hello world from child process\n");

            sprintf(Buffer,"Hello World");
            sprintf(Buffer + strlen(Buffer),"Good Morning");
            sprintf(Buffer + strlen(Buffer),"Good Afternoon");

            write(1, Buffer, strlen(Buffer));
        
        }
        else {
            printf("hello world from main process\n");
        }
    }
    return 0;
}