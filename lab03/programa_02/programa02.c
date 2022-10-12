#include <stdio.h>//blioteca de funções padrão que necessárias pra realizar operações de entrada e saída
#include <stdlib.h>//blioteca de funções envolvendo alocação de memória, controle de processos, conversões e outras.
#include <dirent.h>//biblioteca contendo funções e definições de tipos para manipulação de diretórios de arquivos
#include <sys/types.h> 

int main(){
    char d[10];//Variável do tipo vetor de tamanho 10 que armazenará o nome de um diretórios
    DIR *p;//ponteiro do tipo DIR (apontará papa um diretório)
    struct dirent *d1; //Estrutura dirent contém o ponteiro d1, que aponta para uma string que dá o nome de um arquivo no diretório

    //Recebe o o Nome do diretório
    printf("Entre com um nome de um diretório:\n");
    scanf("%s",d);
    
    /*
    opendit() --> abrir um fluxo de diretório correspondente ao diretório nomeado pelo argumento d
    retorna um ponteiro para um objeto do tipo DIR (d). 
    */
    p = opendir(d);
    if( p==NULL ){//Caso contrário, um ponteiro nulo deve ser retornado e erro definido.

        perror("Diretório não encontrado");//Imprime uma mensagem descrevendo o significado do valor de errno.
        exit(-1);//encerra o programa
    }
    while( d1 = readdir(p) )//retorna um ponteiro para uma estrutura que representa a entrada de diretório na posição atual no fluxo de diretório especificado pelo argumento
        //abre o diretorio e imprime o conteúdo dele --> parecido com o ls -a  - lista todos os arquivos do diretório (inclusive os arquivos ocultos).
        printf("> %s\n",d1-> d_name);
}
