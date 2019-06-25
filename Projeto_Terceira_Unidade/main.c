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
    char caminhoA[100], caminhoB[100], caminhoC[100];
    int tamlit1, tamlit2, tamlit3;

    // no comeco do programa precisamos digitar os caminhos dos arquivos da matriz A, da matriz B
    // e o caminho para a matriz C ser salva, respectivamente

    printf("Primeiro digite os aquivos que poderao ser acessessados durante o programa\n");

    printf("Digite o caminho para o arquivo da matriz A:\n");
    fgets(caminhoA,100,stdin);
    tamlit1=strlen(caminhoA);
    caminhoA[tamlit1-1]=0;

    printf("Digite o caminho para o arquivo da matriz B:\n");
    fgets(caminhoB,100,stdin);
    tamlit2=strlen(caminhoB);
    caminhoB[tamlit2-1]=0;

    printf("Digite um lugar para armazenar a matriz c em um arquivo\n");
    fgets(caminhoC,100,stdin);
    tamlit3=strlen(caminhoC);
    caminhoC[tamlit3-1]=0;

    // Utilizaremos o FILE para manipular as matrizes em arquivos da maquina

    FILE *d;

    // aqui o while serve para o menu aparecer toda vez que um comando for escolhido e o usuario
    // poder ver sempre as opcoes disponiveis

    do{
        menu();
        printf("Digite sua opcao: \n");
        scanf("%d", &opcao);

        // dentro do switch o usuario vai ficar escolhendo as opcoes que serao mostradas
        // no menu que aparece na tela

        switch (opcao) {
        case 1:
            // aqui o usuario vai digitar o numero de linhas e colunas da matriz A
            // assim como no case 2 vai ocorrer o mesmo para a matriz B

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
            // temos aqui a funcao que preenche a matriz com valores aleatorios
            // mas para os valores nao serem muito grandes, o usuario pode limitar o valor
            // dos numeros aleatorios que vao para a matriz

            printf("Digite o valor maximo dos numeros inseridos na matriz A: ");
            scanf("%d", &intervalo1);
            preenchemat(A, nlina, ncoluna, intervalo1);

            break;
        case 4:
            // mesmo coisa do caso anterior, esse intervalo serve para limitar os numeros aleatorios

            printf("Digite o valor maximo dos numeros inseridos na matriz B: ");
            scanf("%d", &intervalo2);
            preenchemat(B, nlinb, ncolunb, intervalo2);

            break;
        case 5:
            // Esse caso chama uma funcao que serve para o usuario digitar os valores manualmente
            // na matriz A. O caso seguinte eh a mesma coisa, mas para a matriz  B
            manualmat(A, nlina, ncoluna);

            break;
        case 6:
            manualmat(B, nlinb, ncolunb);

            break;
        case 7:
            // antes da funcao da soma de matrizes ser acionada, eh preciso testar se o
            // numero de linhas de A e B e o numero de colunas de A e B sao iguais para
            // realizar a soma das matrizes corretamente

            if((nlina==nlinb) && (ncoluna==ncolunb)){
                somamat(A, B, C, nlina, ncoluna);
            }
            else {
                printf("Tamanho das matrizes eh incompativel\n");
            }

            break;
        case 8:
            // Assim como o caso anterior, eh preciso testar se o tamanho das matrizes eh compativel

            if((nlina==nlinb) && (ncoluna==ncolunb)){
                subtraimat(A, B, C, nlina, ncoluna);
            }
            else {
                printf("Tamanho das matrizes eh incompativel\n");
            }

            break;
        case 9:
            // Parecido com os casos anteriores, aqui temos o teste para saber se as matrizes
            // sao compativeis para multiplicacao, testando a condicao dizendo que
            // o numero de colunas da matriz A precisa ser igual ao numero de linhas da matriz B

            if(ncoluna==nlinb){
                multmat(A, B, C, nlina, ncoluna, ncolunb);
            }
            else {
                printf("Tamanho das matrizes eh incompativel\n");
            }

            break;
        case 10:
            // Os tres casos seguintes chamam a funcao que imprime a matriz desejada, seja A, B ou C

            imprimemat(A, nlina, ncoluna);

            break;
        case 11:
            imprimemat(B, nlinb, ncolunb);

            break;
        case 12:
            imprimemat(C, nlina, ncolunb);

            break;
        case 13:
            // aqui ocorre a leitura de uma matriz que esta dentro de um arquivo
            // e eh salvo na matriz A
            // antes eh feito um teste com o literal que possui o "caminho" do arquivo dentro
            // se o caminho foi inválido, o arquivo nao sera aberto

            if(d=fopen(caminhoA, "r")== NULL){
                printf("Nao existe o arquivo\n");
            }
            else {
                d=fopen(caminhoA, "r");
                fscanf(d,"%d %d", &nlina, &ncoluna);
                lermat(A, nlina, ncoluna, caminhoA);
            }

            break;
        case 14:
            // aqui ocorre a mesma coisa do caso anterior
            // mas agora com a matriz B

            if(d=fopen(caminhoB, "r")== NULL){
                printf("Nao existe o arquivo\n");
            }
            else {
                d=fopen(caminhoB, "r");
                fscanf(d,"%d %d", &nlinb, &ncolunb);
                lermat(B, nlinb, ncolunb, caminhoB);
            }

            break;
        case 15:
            // o ultimo caso chama uma funcao que escreve a matriz C dentro de um arquivo
            // o caminho para o arquivo eh preenchido no comeco do programa
            escrevemat(C, nlina, ncolunb, caminhoC);

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
