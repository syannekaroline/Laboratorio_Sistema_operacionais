#include <stdio.h> //blioteca de funções padrão que necessárias pra realizar operações de entrada e saída
#include <fcntl.h> // blioteca de funções pra controle de arquivo
#include <string.h> //biblioteca de funções padrão pra uso de strings

//funções adicionais --> necessárias pro uso das chamadas de sistema
/*define constantes e tipos simbólicos diversos e declara funções diversas.
  O conteúdo deste cabeçalho é mostrado abaixo.*/
#include <unistd.h> 

int main(){

     /* Declaração da variável buff(vetor de 99 caracteres) que armazenará a mensagem do arquivo
        e declaração do vetor fn(file name) de 9 caracteres que armazenará o nome do arquivo criado*/
    char buff[100], fn[10];

    /*declara 2 variáveis inteiras 
    - fd(file_descriptor)
    - n -> retorno da função write (número de bytes escritos)*/
    int fd, n; 

    //Recebe o nome do arquivo que será criado
    printf("Entre com o nome de um arquivo novo:\n");
    fgets(fn,10,stdin);/*Função fgets recebe 3 parâmetros 
                        1.nome do vetor que salvará a string lida
                        2.a quantidade max de caracteres a serem lidos
                        3. de onde será lido,neste caso ,do buffer do teclado)*/

    //Recebe o conteúdo do arquivo
    printf("\nEntre com um texto qualquer: ");
    fgets(buff,100,stdin);
    printf("buff: %s",buff);
   
    /*descritor de arquivo 
    índice pra um registro de uma estrutura de dados do núcleo que contém detalhes de todos os arquivos abertos
    é armazenado na variável fd (indicador abstrato pra acessar um arquivo)*/

    fd = open(fn,O_CREAT|O_WRONLY);//retorna um inteiro não negativo com o arquivo descritor | em caso de erro -1 é retornado
     /*a função open abre o arquivo fn, especificado no primeiro parâmetro,
     se o arquivo não existe ele será criado graças ao parâmetro O_CREAT - sinalizador de criação de arquivo). 
     Além disso, o argumento inclui o modo de acesso O_WRONLY (somente de gravação) */
    printf("file descritor: %d",fd);
    if (fd==-1){
        printf("Error opening file descriptor ):");
    }
   
    /*A função write grava informações em um descritor de arquivos
    recebe como primeiro parâmetro o descritor de arquivo onde será feita a escrita. 
    Recebe como segundo parâmetro o buffer contendo o conteúdo que será escrito, 
    e como último o número de caracteres da mensagem escrita (usa-se a função strlen pra retornar o tamanho max do buff)
    A função guarda o retorno na variável n --> em caso de sucesso, o número de bytes gravados é retornado, em caso de erro retorna -1*/
    n = write(fd,buff,strlen(buff));
    
    close(fd);//função que fecha um descritor de arquivo, para que ele não se refira mais a qualquer arquivo.

    printf("\n\n Veja o conteúdo do arquivo criado \n");
    printf("\n Número de bytes escritos : %d \n",n);
    
}
