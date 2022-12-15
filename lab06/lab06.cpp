#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include<math.h>

#define BUFSIZE 80
//O exemplo abaixo cria um processo FILHO através da chamada de sistema fork() e cria um buffer para troca de informações entre os processos através da chamada de sistem pipe().
//FILHO escreve para o processo PAI através do pipe.

using namespace std;


float determinant(float [][25], float);
void cofactor(float [][25], float, int fd);
void transpose(float [][25], float [][25], float, int fd);
int MultiplicacaoMatrizes( float MatrizA[25][25], float MatrizB[25][25], float n);
int CalculoInversaFilho(int fd);

int main(void)
{
  int fd[2];
  int n=0;
  int i;
  char inverse[25][25];
  
  pipe(fd); /* fd[0] - leitura, fd[1] - escrita*/

  if (fork() == 0) {
    close(fd[0]);

    printf("Processo FILHO escreve: %d\n",n);
    CalculoInversaFilho(fd[1]);
    sleep(2);
  
  }
  else {
    close(fd[1]);
    
    printf("\t\t\t Processo PAI realiza a leitura do pipe\n");

    read(fd[0], inverse, BUFSIZE);

    printf("\n\n\nThe inverse of matrix is : \n");
 
    for (int i = 0;i < 2; i++){
      for (int j = 0;j < 2; j++){
        printf("\t%.2f", inverse[i][j]);
      }

      printf("\n");
    }
    
    printf("\t\t\t Processo PAI lê:");


    
  }
}

int CalculoInversaFilho(int fd[1]){
  float a[25][25], k, d;
  int i, j;

  printf("Entre com a ordem da matriz : ");
  scanf("%f", &k);
  printf("Insira os elementos da matriz %.0fX%.0f : \n", k, k);
  for (i = 0;i < k; i++){
    for (j = 0;j < k; j++){
      scanf("%f", &a[i][j]);
    }
  }
  d = determinant(a, k);

  if (d == 0)
    printf("\nInverse of Entered Matrix is not possible\n");
  else
    cofactor(a, k, fd[1]);

}

/* inversa calculo -=-=-=-=-=-=-=*/

/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k){
float s = 1, det = 0, b[25][25];
int i, j, m, n, c;

if (k == 1){
  return (a[0][0]);
}
else{
  det = 0;
  for (c = 0; c < k; c++){
      m = 0;
      n = 0;
      for (i = 0;i < k; i++){
        for (j = 0 ;j < k; j++){
          b[i][j] = 0;

          if (i != 0 && j != c){
            b[m][n] = a[i][j];

            if (n < (k - 2))
              n++;
            else{
              n = 0;
              m++;
            }
          }
        }
      }

      det = det + s * (a[0][c] * determinant(b, k - 1));
      s = -1 * s;
    }
  }

  return (det);
}
 
void cofactor(float num[25][25], float f, int fd[1]){
  float b[25][25], fac[25][25];
  int p, q, m, n, i, j;
  for (q = 0;q < f; q++){
    for (p = 0;p < f; p++){
      m = 0;
      n = 0;
      for (i = 0;i < f; i++){
        for (j = 0;j < f; j++){
          if (i != q && j != p){
            b[m][n] = num[i][j];
            if (n < (f - 2))
              n++;
            else{
              n = 0;
              m++;
            }
          }
        }
      }

      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  transpose(num, fac, f, fd[1]);
}

/*Finding transpose of matrix*/ 
void transpose(float num[25][25], float fac[25][25], float r, int fd[1]){
  int i, j;
  float b[25][25], inverse[25][25], d;
 
  for (i = 0;i < r; i++){
    for (j = 0;j < r; j++){
      b[i][j] = fac[j][i];
    }
  }

  d = determinant(num, r);
  for (i = 0;i < r; i++){
    for (j = 0;j < r; j++){
      inverse[i][j] = b[i][j] / d;
    }
  }

  write(fd[1], inverse, BUFSIZE);
  
  // printf("\n\n\nThe inverse of matrix is : \n");
 
  // for (i = 0;i < r; i++){
  //   for (j = 0;j < r; j++){
  //     printf("\t%.2f", inverse[i][j]);
  //   }

  //   printf("\n");
  // }

  // MultiplicacaoMatrizes(inverse, inverse, r);
}

/* Multiplica calculo =-=-=-=-=-=-=-=-=-=*/

#define MAX 100
int MultiplicacaoMatrizes( float inverseA[25][25], float inverseB[25][25], float n)
{   
    int mult[25][25];

    // Initializing elements of matrix mult to 0.
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        mult[i][j]=0;
      }
    }
    // Multiplying matrix a and b and storing in array mult.
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        for(int k = 0; k < n; ++k){
          mult[i][j] += inverseA[i][k] * inverseB[k][j];
        }
      }
    }
    // Displaying the multiplication of two matrix.
    cout << endl << "Multiplicação das duas inversas : " << endl;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        cout << " " << mult[i][j];
        if(j == n-1)
        cout << endl;
      }
    }
    return 0;
}