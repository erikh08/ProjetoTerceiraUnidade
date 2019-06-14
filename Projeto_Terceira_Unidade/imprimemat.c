#include <stdio.h>

void imprimemat(float mat[50][50], int linhas, int colunas){
    int i, j;
    for (i=0;i<linhas;i++) {
        for (j=0;j<colunas;j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}
