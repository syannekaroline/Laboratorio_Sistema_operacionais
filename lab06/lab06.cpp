#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include<math.h>
#define TAM 2504

typedef struct{
    float A[25][25];
    int ordem;
}Matriz;

float determinant(float [][25], float);
Matriz cofactor(float [][25], float);
Matriz transpose(float [][25], float [][25], float);
Matriz Inversa();
int MultiplicacaoMatrizes(float MatrizA[25][25], float MatrizB[25][25], int ordem);


using namespace std;

int main(void)
{
    int fd[2];
    Matriz InversaFilho;
    Matriz InversaPai;


    pipe(fd); /* fd[0] - leitura, fd[1] - escrita*/

    if (fork() == 0) {
        close(fd[0]);

        printf("Gerando a inversa do processo Filho\n");
        InversaFilho = Inversa();
        write(fd[1], InversaFilho.A, sizeof(InversaFilho.A));
    }
    else {
        close(fd[1]);

        printf("\t\t\t Processo PAI realiza a leitura do pipe -- Comunicação com o filho \n");
        read(fd[0], InversaFilho.A, sizeof(InversaFilho.A));
        printf("\t\t\t Criando a inversa do Pai \n");
        InversaPai = Inversa();

        MultiplicacaoMatrizes(InversaFilho.A, InversaPai.A, InversaFilho.ordem);   
    }
}


Matriz Inversa()
{
  float a[25][25], k, d;
  int i, j;
  Matriz inversa;

  printf("Enter the order of the Matrix '': ");
  scanf("%f", &k);
  inversa.ordem = k;
  printf("Enter the elements of %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &a[i][j]);
        }
    }
  d = determinant(a, k);
  if (d == 0)
   printf("\nInverse of Entered Matrix is not possible\n");
  else
   inversa = cofactor(a, k);

   return inversa;
}
 
/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
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
 
Matriz cofactor(float num[25][25], float f)
{

 float b[25][25], fac[25][25];
 int p, q, m, n, i, j;
 Matriz inverse;
 
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }
  inverse = transpose(num, fac, f);

  return inverse;
}

/*Finding transpose of matrix*/ 
Matriz transpose(float num[25][25], float fac[25][25], float r){
    int i, j;
    float b[25][25], d;
    Matriz  inverse;

    for (i = 0;i < r; i++){
        for (j = 0;j < r; j++){
            b[i][j] = fac[j][i];
        }
    }

    d = determinant(num, r);
    for (i = 0;i < r; i++){
        for (j = 0;j < r; j++){
            inverse.A[i][j] = b[i][j] / d;
        }
    }

    
       printf("\n\n\nThe inverse of matrix is : \n");

       for (i = 0;i < r; i++)
        {
         for (j = 0;j < r; j++)
           {
             printf("\t%.2f", inverse.A[i][j]);
            }
        printf("\n");
         }

    return inverse;
}

int MultiplicacaoMatrizes( float MatrizA[25][25], float MatrizB[25][25], int n){  
    int mult[10][10], i, j, k;

    // If column of first matrix in not equal to row of second matrix,
    // ask the user to enter the size of matrix again.

    // Initializing elements of matrix mult to 0.
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
        {
            mult[i][j]=0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            for(k = 0; k < n; ++k)
            {
                mult[i][j] += MatrizA[i][k] * MatrizB[k][j];
            }

    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
    {
        cout << " " << mult[i][j];
        if(j == n-1)
            cout << endl;
    }

    return 0;
}