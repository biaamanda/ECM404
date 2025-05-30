#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 5 - Ponteiros
 * Implemente um programa que leia dois valores inteiros (A e B). 
 * A seguir, troque os seus valores utilizando a subrotina troca_valores. 
 * A subrotina deve receber dois ponteiros para inteiros e trocar os seus valores de lugar.
 */

int main() {
    int *value1, *value2, temp;

    printf("Digite dois valores: ");
    scanf("%d %d", &value1, &value2);

    printf("%d, %d", value2, value1);

    return 0;
}
