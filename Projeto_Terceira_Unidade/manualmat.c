#include <stdio.h>

void manualmat(float mat[50][50], int nl, int nc){
    int i, j;
    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            printf("Digite o elemento %d, %d da matriz\n", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
}
