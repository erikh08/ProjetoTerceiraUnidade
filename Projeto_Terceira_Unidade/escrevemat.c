#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void escrevemat(float m[50][50], int nl, int nc, char jonas[100])
{
    int i, j;
    FILE *f;

    f=fopen(jonas, "w");
    fprintf(f,"%d %d\n", nl, nc);
    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            fprintf(f,"%.2f ", m[i][j]);
        }
        fprintf(f, "\n");
    }

}
