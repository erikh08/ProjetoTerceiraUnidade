#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A funcao escreve a matriz dentro do arquivo selecionado
// o usuario deve digitar o caminho do arquivo na funcao principal


void escrevemat(float m[50][50], int nl, int nc, char caminhoArquivo[100])
{
    int i, j;
    FILE *f;

    f=fopen(caminhoArquivo, "w");
    fprintf(f,"%d %d\n", nl, nc);
    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            fprintf(f,"%.2f ", m[i][j]);
        }
        fprintf(f, "\n");
    }

}
