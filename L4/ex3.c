/* Enunciado:
 *  Desenvolva um programa capaz de ler dois vetores com tr�s elementos
 *  inteiros cada. A leitura deve ser feita em uma �nica linha para cada vetor,
 *  com os elementos separados por espa�os. Ap�s a leitura, o programa
 *  deve exibir o produto escalar entre os vetores digitados no formato
 *  exemplificado abaixo. O c�lculo do produto escalar deve obrigatoriamente
 *  ser feito pela fun��o produto_escalar, que recebe como refer�ncia os
 *  dois arrays e retorna um valor inteiro referente ao resultado do produto
 *  escalar.
 *
 *  Exemplos:
 *      Digite o primeiro array: 1 2 3
 *      Digite o segundo array: 3 2 1
 *      [1, 2, 3] . [3, 2, 1] = 10
 *
 *      Digite o primeiro array: 10 20 30
 *      Digite o segundo array: -10 2 5
 *      [10, 20, 30] . [-10, 2, 5] = 90
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */
int produto_escalar(int array[], int array2[]);

int main()
{
    int array[ARRAY_MAX];
    int array2[ARRAY_MAX];
    int i;

    for (i = 0; i < ARRAY_MAX; i++) {
        printf("Digite o primeiro array: ", i);
        scanf("%i", &array[i]);
    }

    for (i = 0; i < ARRAY_MAX; i++) {
    printf("Digite o segundo array: ", i);
    scanf("%i", &array2[i]);
    }

    int produto = produto_escalar(array, array2);
    printf("%i", produto);
    return 0;
}

/* Implementa��o das Fun��es */
int produto_escalar(int array[], int array2[]) {
    int produto = 0;

    for (int i = 0; i < ARRAY_MAX; i ++) {
        produto += array[i] * array2[i];
    }
return produto;
}
