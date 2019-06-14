#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lermat(float m[50][50], int nl, int nc, char jonas[100])
{
    int i, j;
    FILE *f;

    f=fopen(jonas, "r");
    fscanf(f,"%d %d", &nl, &nc);
    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            fscanf(f,"%f", &m[i][j]);
        }
    }
}
