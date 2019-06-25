#include <stdio.h>

// Aqui temos o menu que ira mostrar as opcoes possiveis
// para o usuario escolher no programa de manupulacao de matrizes

void menu(void){
    printf("----PROGRAMA DE MANIPUULACAO DE MATRIZES----\n"
           " (1) Definir o tamanho da matriz A\n"
           " (2) Definir o tamanho da matriz B\n"
           " (3) Preencher matriz A com valores aleatorios\n"
           " (4) Preencher matriz B com valores aleatorios\n"
           " (5) Atribuir valores manualmente para os elementos da matriz A\n"
           " (6) Atribuir valores manualmente para os elementos da matriz B\n"
           " (7) Calcular A+B\n"
           " (8) Calcular A-B\n"
           " (9) Calcular A*B\n"
           "(10) Imprimir matriz A\n"
           "(11) Imprimir matriz B\n"
           "(12) Imprimir matriz C\n"
           "(13) Ler a matriz A de um arquivo\n"
           "(14) Ler a matriz B de um arquivo\n"
           "(15) Escrever a matriz C em um arquivo\n"
           "(16) Sair\n");
}
