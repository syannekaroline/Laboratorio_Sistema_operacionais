//Criação de processo ”pai” e processo “filho”
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h> //define uma coleção de símbolos e estruturas typedef id_t --> Identificador geral, pode conter um pid_t ou um gid_t.

#define MAX_COUNT 200
#define BUF_SIZE 100

void main(void){

    pid_t pid;
    int i, teste;
    char buf[BUF_SIZE];

    teste = fork(); /*Clone o processo de chamada, criando uma cópia exata.
            Retorna -1 para erros, 0 para o novo processo,
            e o ID do processo do novo processo para o processo antigo*/

    pid = getpid(); 

    for (i = 1; i <= 4; i++) {
        sprintf(buf, "PID = %d, valor = %d\n", pid, i);
        write(1, buf, strlen(buf));

        if (teste == 0 ){
            printf("From child process\n");
        }
        else{
            printf("From main process\n");
        }
    }
    exit(0);
}