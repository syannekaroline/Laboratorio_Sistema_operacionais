#include <iostream>

using namespace std;
#define MAX 100
int MultiplicacaoMatrizes( float MatrizA[MAX][MAX], float MatrizB[10][10], float n)
{   
    int mult[10][10];

    // Initializing elements of matrix mult to 0.
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
        {
            mult[i][j]=0;
        }
    }
    // Multiplying matrix a and b and storing in array mult.
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
            {
                mult[i][j] += MatrizA[i][k] * MatrizB[k][j];
            }
    }
    // Displaying the multiplication of two matrix.
    cout << endl << "Output Matrix: " << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << " " << mult[i][j];
            if(j == n-1)
            cout << endl;
        }
    }
    return 0;
}