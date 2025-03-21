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
int ScalarProduct(int firstArray[], int secondArray[])
{
    int scalarProduct = 0;

    for (int i = 0; i < ARRAY_MAX; i++)
    {
        scalarProduct += firstArray[i] * secondArray[i];
    }

    return scalarProduct;
}

int main()
{
    int firstArray[ARRAY_MAX], secondArray[ARRAY_MAX];
    
    printf("Digite o primeiro array: ");
    scanf("%i %i %i", &firstArray[0], &firstArray[1], &firstArray[2]);
    
    printf("Digite o segundo array: ");
    scanf("%i %i %i", &secondArray[0], &secondArray[1], &secondArray[2]);
    
    printf("[%i %i %i] . ", firstArray[0], firstArray[1], firstArray[2]);
    printf("[%i %i %i] = ", secondArray[0], secondArray[1], secondArray[2]);
    printf("%i", ScalarProduct(firstArray, secondArray));
    }
