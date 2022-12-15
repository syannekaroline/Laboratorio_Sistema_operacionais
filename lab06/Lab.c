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
    
    
}