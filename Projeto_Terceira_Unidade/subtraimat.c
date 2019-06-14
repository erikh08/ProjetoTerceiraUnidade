#include <stdio.h>

void subtraimat(float m1[50][50], float m2[50][50], float m3[50][50], int nla, int nca){
    int i, j;
        for(i=0;i<=nla;i++){
            for(j=0;j<=nca;j++){
                m3[i][j]=m1[i][j]-m2[i][j];
            }
        }
    }
