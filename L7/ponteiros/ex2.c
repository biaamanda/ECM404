#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
 * Exercício 2 - Ponteiros
 * Crie um programa que contenha um array de float contendo 10 elementos.
 * Imprima o endereço de cada posição desse array.
 */

int main() {
    float array[10];
    int i;

    for(i=0; i < 10; i++){
        printf("Endereco de array[%d]: %p\n", i);
    }
    return 0;
}
