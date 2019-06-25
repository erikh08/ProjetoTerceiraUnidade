#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// aqui temos uma funcao que vai preencher a matriz com elementos aleatorios
// usando o rand e o srand em funcao do tempo
// para os numeros serem aleatorios

void preenchemat(float m[50][50], int nl, int nc, int max){
    int i, j;
    srand(time(0));
    for (i=0;i<nl;i++) {
        for (j=0;j<nc;j++) {
            m[i][j]=rand()%(max+1);
        }
    }
}
