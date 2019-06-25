#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A funcao le uma matriz que esta dentro de um arquivo
// o usuario deve digitar o caminho do arquivo na funcao principal

void lermat(float m[50][50], int nl, int nc, char CaminhoArquivo[100])
{
    int i, j;
    FILE *f;

    f=fopen(CaminhoArquivo, "r");
    fscanf(f,"%d %d", &nl, &nc);
    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            fscanf(f,"%f", &m[i][j]);
        }
    }
}
