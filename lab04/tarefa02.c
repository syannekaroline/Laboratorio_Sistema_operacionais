#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define MAX_BUF 2024
void Fibonacci(int);
void Hanoi(int n, char fromTower, char toTower, char auxTower);
void fatorial(int);

void main(void) {
    int NumeroFixo = 19,termo_fibonacci= 100, N_Discos= 6;


    // fatorial( NumeroFixo);
    // Fibonacci(termo_fibonacci);
    // Hanoi(N_Discos, 'A', 'C', 'B');
    // printf("Torre de hanoi foi Resolvida \n");

    //declarando os tipos de variáveis pra armazenarem os PIDs dos processos
    pid_t pid_Fibonacci,pid_hanoi;

    //Criando o processo filho --> Fibonacci
    pid_Fibonacci = fork();

    if (pid_Fibonacci == 0){//se o processo filho estiver executando

        //Criando o processo neto --> Hanoi
        pid_hanoi = fork();

        if (pid_hanoi == 0){//se o processo neto estiver executando
            //PROCESSO NETO
            Hanoi(N_Discos, 'A', 'C', 'B');
            printf(" #### FIM NETO #### \n\n");
            exit(0);
        }
        else{
            //Processo FILHO
            Fibonacci(termo_fibonacci);
            exit(0);
        }
    }
    else{
        //Processo PAI
        fatorial(NumeroFixo);
        exit(0);
    }
    exit(0);
}

void fatorial(int NumeroFixo) {
    //a)Cálculo do fatorial de um número fixo < 20 --> 10
    
    int aux=1,fat;
    char Buffer[MAX_BUF];
    sprintf(Buffer,"Processo pai: Fatorial = ");
    for(fat = 1; NumeroFixo > 1; NumeroFixo = NumeroFixo - 1){
        fat = fat * NumeroFixo;
       
        sprintf(Buffer + strlen(Buffer),".%d",NumeroFixo);
        write(1, Buffer, strlen(Buffer));
        printf("!\n");

    }
    printf("Fatorial calculado: %d \n\n", fat);
    printf(" #### FIM PAI ###\n\n");
    exit(0);
}

void Fibonacci(int TermoFibonacci) {
    
    // initialize first and second terms
    double t1 = 0, t2 = 1,i;

    // initialize the next term (3rd term)
    double nextTerm = t1 + t2;

    // print the first two terms t1 and t2
    printf("Processo Filho: Fibonacci [termo 1] : %.0f \n", t1);
    printf("Processo Filho: Fibonacci [termo 2] : %.0f \n", t2);

    // print 3rd to nth terms
    for (i = 3; i <= TermoFibonacci; ++i) {
        printf("Processo Filho: Fibonacci[termo %.0f] : %.0f \n",i, nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    printf(" #### FIM FILHO #### \n\n");
    exit(0);
                         
}

void Hanoi(int n, char fromTower, char toTower, char auxTower){
    if (n == 1)
    {
        printf("Processo Neto :Mover disco 1 da torre %c para torre %c \n", fromTower, toTower);
        return;
    }

    Hanoi(n - 1, fromTower, auxTower, toTower);
    printf("Processo Neto : Mover disco %d da torre %c para torre %c \n", n, fromTower, toTower);
    Hanoi(n - 1, auxTower, toTower, fromTower);
}
