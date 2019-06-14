#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <menu.h>
#include <somamat.h>
#include <subtraimat.h>
#include <multmat.h>
#include <imprimemat.h>
#include <lermat.h>
#include <preenchemat.h>
#include <manualmat.h>
#include <escrevemat.h>


int main(){
    int opcao, nlina=50, nlinb=50, ncoluna=50, ncolunb=50;
    float A[50][50], B[50][50], C[50][50];
    int intervalo1, intervalo2;
    char caminho1[100], caminho2[100], caminho3[100];
    int tamlit1, tamlit2, tamlit3;
    printf("Primeiro digite os aquivos que poderao ser acessessados durante o programa\n");

    printf("Digite o caminho para o arquivo da matriz A:\n");
    fgets(caminho1,100,stdin);
    tamlit1=strlen(caminho1);
    caminho1[tamlit1-1]=0;

    printf("Digite o caminho para o arquivo da matriz B:\n");
    fgets(caminho2,100,stdin);
    tamlit2=strlen(caminho2);
    caminho2[tamlit2-1]=0;

    printf("Digite um lugar para armazenar a matriz c em um arquivo\n");
    fgets(caminho3,100,stdin);
    tamlit3=strlen(caminho3);
    caminho3[tamlit3-1]=0;

    FILE *d;

    do{
    menu();
    printf("Digite sua opcao: \n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        printf("Digite o numero de linhas de A: \n");
        scanf("%d", &nlina);
        printf("Digite o numero de colunas de A: \n");
        scanf("%d", &ncoluna);
        break;
    case 2:
        printf("Digite o numero de linhas de B: \n");
        scanf("%d", &nlinb);
        printf("Digite o numero de colunas de B: \n");
        scanf("%d", &ncolunb);
        break;
    case 3:
        printf("Digite o valor maximo dos numeros inseridos na matriz A: ");
        scanf("%d", &intervalo1);
        preenchemat(A, nlina, ncoluna, intervalo1);

        break;
    case 4:
        printf("Digite o valor maximo dos numeros inseridos na matriz B: ");
        scanf("%d", &intervalo2);
        preenchemat(B, nlinb, ncolunb, intervalo2);

        break;
    case 5:
        manualmat(A, nlina, ncoluna);

        break;
    case 6:
        manualmat(B, nlinb, ncolunb);

        break;
    case 7:
        if((nlina==nlinb) && (ncoluna==ncolunb)){
            somamat(A, B, C, nlina, ncoluna);
        }
        else {
            printf("Tamanho das matrizes eh incompativel\n");
        }

        break;
    case 8:
        if((nlina==nlinb) && (ncoluna==ncolunb)){
            subtraimat(A, B, C, nlina, ncoluna);
        }
        else {
            printf("Tamanho das matrizes eh incompativel\n");
        }


        break;
    case 9:
        if(ncoluna==nlinb){
            multmat(A, B, C, nlina, ncoluna, ncolunb);
        }
        else {
            printf("Tamanho das matrizes eh incompativel\n");
        }

        break;
    case 10:
        imprimemat(A, nlina, ncoluna);

        break;
    case 11:
        imprimemat(B, nlinb, ncolunb);

        break;
    case 12:
        imprimemat(C, nlina, ncolunb);

        break;
    case 13:
        if(d=fopen(caminho1, "r")== NULL){
            printf("Nao existe o arquivo\n");
        }
        else {
            d=fopen(caminho1, "r");
            fscanf(d,"%d %d", &nlina, &ncoluna);
            lermat(A, nlina, ncoluna, caminho1);
        }

        break;
    case 14:
        if(d=fopen(caminho2, "r")== NULL){
            printf("Nao existe o arquivo\n");
        }
        else {
            d=fopen(caminho2, "r");
            fscanf(d,"%d %d", &nlinb, &ncolunb);
        lermat(B, nlinb, ncolunb, caminho2);
        }

        break;
    case 15:
        escrevemat(C, nlina, ncolunb, caminho3);

        break;
    case 16:
        printf("Esoclheu sair\n");

        break;
    default:
        printf("Nao existe essa opcao\n");
        break;
    }
    }while (opcao != 16);

    return 0;
}
