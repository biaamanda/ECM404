#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 4 - Ponteiros
 * Escreva uma função que receba um array de inteiros V e os endereços de duas variáveis inteiras,
 * min e max, e armazene nessas variáveis o valor mínimo e máximo do array.
 */

int main() {
    int V[10];
    int min, max;

    printf("Digite sua array: ");

    for(int i = 0; i < 10; i++){
        printf("V[%d]", i);
        scanf("%d", &V[i]);
    }

    min = V[0];
    max = V[0];

    for (int i = 0; i < 10; i++){
        if(V[i] < min){
            min = V[i];
        }
        if(V[i] > max){
            max = V[i];
        }
    }

    printf("Valor minimo e maximo, respectivamente: %d, %d", min, max);

    return 0;
}
