#include <stdio.h>

// A funcao faz a multiplicacao de duas matrizes
// onde os elementos da linha da matriz A sao multiplicados com
// os elementos da coluna da matriz B e sao somados para cada posicao da matriz

void multmat(float m1[50][50], float m2[50][50], float m3[50][50], int nl1, int nc1, int nc2){
    int i, j, k;
    float soma=0;
    for(i=0;i<nl1;i++){
        for(j=0;j<nc2;j++){
            soma=0;
            for(k=0;k<nc1;k++){
                soma=soma+(m1[i][k]*m2[k][j]);
            }
            m3[i][j]= soma;
        }
    }
}
