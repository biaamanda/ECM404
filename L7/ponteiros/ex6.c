#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 6 - Ponteiros
 * Implemente um programa que permita a entrada de valores de um array cujo tamanho máximo
 * é definido pela constante MAX. A quantidade de valores armazenado no vetor será definida 
 * pelo usuário (quando digitar -100, a leitura para). É obrigatório o uso da subrotina 
 * ler_vetor, que recebe como parâmetros um ponteiro que aponta para o início do vetor e 
 * um ponteiro para um valor inteiro que representa o tamanho real do vetor.
 */

 #define MAX 100

void readVector(int *vector, int *realSize) {
    int value;
    *realSize = 0;

    printf("Digite os valores do vetor (quando digitar -100 a leitura para):\n");

    while (*realSize < MAX) {
        printf("Valor %d: ", *realSize + 1);
        scanf("%d", &value);

        if (value == -100) {
            break;
        }

        vector[*realSize] = value;
        (*realSize)++;
    }
}

int main() {
    int vector[MAX];
    int realSize;

    readVector(vector, &realSize);

    printf("\nVetor lido (%d elementos):\n", realSize);
    for (int i = 0; i < realSize; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}