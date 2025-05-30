#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 * Exercício 1 - Ponteiros
 * Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores
 * de entrada e retorne o maior valor na primeira variável e o menor valor na segunda variável.
 * Escreva o conteúdo das 2 variáveis na tela.
 */

int main() {
    int *value1, *value2;

    printf("Valores: ");
    scanf(" %d %d", &value1, &value2);

    if(value1 > value2){
        printf("%d, %d", value1, value2);
    } else{
        printf(" %d, %d", value2, value1);
    }

    return 0;
}
