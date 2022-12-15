#include <stdio.h>
#include <unistd.h>
#define BUFSIZE 80
//O exemplo abaixo cria um processo FILHO através da chamada de sistema fork() e cria um buffer para troca de informações entre os processos através da chamada de sistem pipe().
//FILHO escreve para o processo PAI através do pipe.

int main(void)
{
    int fd[2];
    int n=0;
    int i;
    char line[BUFSIZE];
    
    pipe(fd); /* fd[0] - leitura, fd[1] - escrita*/

    if (fork() == 0) {
        close(fd[0]);

        for (i=0; i < 10; i++) {
            sprintf(line,"%d",n);
            write(fd[1], line, BUFSIZE);
            printf("Processo FILHO escreve: %d\n",n);
            n++;
            sleep(2);
        }
    }

    else {
        close(fd[1]);
        for (i=0; i < 10; i++) {

            printf("\t\t\t Processo PAI realiza a leitura do pipe\n");

            read(fd[0], line, BUFSIZE);
            sscanf(line,"%d",&n);
            printf("\t\t\t Processo PAI lê: %d\n",n);
        }   
    }
}