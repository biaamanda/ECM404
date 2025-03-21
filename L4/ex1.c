/* Enunciado: Desenvolva um programa capaz de ler n valores inteiros e os
 *  insira em um array. A leitura deve ser feita em uma �nica linha, separando
 *  os valores por espa�o. A leitura deve ser encerrada quando um
 *  valor -100 � lido. Ap�s a leitura ser realizada, o programa deve utilizar
 *  o procedimento exibe_array para exibir o array em uma �nica linha
 *  e entre colchetes.
 *
 *  Exemplos:
 *    Digite os valores para o array: 1 2 3 4 5 6 7 8 -100
 *    [1, 2, 3, 4, 5, 6, 7, 8]
 *
 *    Digite os valores para o array: 1 2 3 4 -100
 *    [1, 2, 3, 4]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

void exibe_array(int array[], int size_array) {
    printf("[");
    for (int i = 0; i < size_array; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("]\n");
}

int main() {
    int array[100], value, i = 0;
    
    printf("Digite os valores para o array: ");
    
    while (1) {
        scanf("%d", &value);
        if (value == -100) {
            break;
        }
        array[i++] = value;
    }
    
    exibe_array(array, i);
    
    return 0;
}