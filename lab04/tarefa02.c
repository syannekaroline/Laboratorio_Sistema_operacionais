#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define MAX_BUF 2024
void Fibonacci(void);
void Hanoi(void);
void fatorial(void);

void main(void) {
    fatorial();
    // pid_t pid_Fibonacci,pid_hanoi;
    // pid_Fibonacci = fork();

    // if (pid_Fibonacci == 0){
        
    //     pid_hanoi = fork();

    //     if (pid_hanoi == 0){
    //         hanoi();
    //     }
    //     else{
    //         Fibonacci();
    //     }
    // }
    // else{
    //     fatorial();
    // }
       
    // exit(0);
}

void fatorial(void) {
    //a)Cálculo do fatorial de um número fixo < 20 --> 10
    
    int numero_fixo=10,aux=1,i;
    int caracteres_escritos = 0;
    char buf_update[MAX_BUF],buf_resultado[MAX_BUF];

    for (i <= numero_fixo;i=1;i--){
        aux *= i;

        caracteres_escritos += sprintf(buf_update+caracteres_escritos, "%d." ,i);
        caracteres_escritos += sprintf(buf_resultado+caracteres_escritos, "= %d" ,aux);
        write(1, buf_update, strlen(buf_update));
        write(1, buf_resultado, strlen(buf_resultado));
    }
    exit(0);
}

void Fibonacci(void) {
    int i;
    for (i = 1; i <= MAX_BUF; i++){
        printf("Processo PAI, value = %d\n", i);
        printf("*** Processo PAI finalizado ***\n");

    }
    exit(0);
}

void Hanoi(void){
    int i;
    for (i = 1; i <= MAX_BUF; i++){
        printf("Processo PAI, value = %d\n", i);
        printf("*** Processo PAI finalizado ***\n");
    }
    exit(0);
}
