#include <stdio.h>

// essa funcao serve para o usuario digitar os elementos da matriz manualmente
// cada numero digitado deve ser guardado na posicao da matriz correspondente

void manualmat(float mat[50][50], int nl, int nc){
    int i, j;
    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            printf("Digite o numero na posicao %d, %d da matriz\n", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
}
