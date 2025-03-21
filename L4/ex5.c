/* Enunciado:
 *   Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3
 *   e, a seguir, calcule e exiba sua determinante. O c�lculo da determinante
 *   deve ser feito pela fun��o determinante, que recebe por refer�ncia uma
 *   matriz 3x3 e retorna o valor inteiro referente � determinante.
 *
 *   Exemplos:
 *     Digite a linha 0: 2 3 4
 *     Digite a linha 1: 1 3 4
 *     Digite a linha 2: 5 6 7
 *     -3
 *
 *     Digite a linha 0: 1 0 0
 *     Digite a linha 1: 0 1 0
 *     Digite a linha 2: 0 0 1
 *     1
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3 // Valor m�ximo para o tamanho do array. N�o modifique.

int determinante(int matriz[ARRAY_MAX][ARRAY_MAX]) {
    int det;
    det = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + 
          (matriz[0][1] * matriz[1][2] * matriz[2][0]) + 
          (matriz[0][2] * matriz[1][0] * matriz[2][1]) - 
          (matriz[0][2] * matriz[1][1] * matriz[2][0]) - 
          (matriz[0][1] * matriz[1][0] * matriz[2][2]) - 
          (matriz[0][0] * matriz[1][2] * matriz[2][1]);
    return det;
}


int main()
{
    int matrix[ARRAY_MAX][ARRAY_MAX];
    // printf("Digite a linha 0: ");
    // scanf("%i %i %i", &matrix[0][0], &matrix[0][1], &matrix[0][2]);
    // printf("Digite a linha 1: ");
    // scanf("%i %i %i", &matrix[1][0], &matrix[1][1], &matrix[1][2]);
    // printf("Digite a linha 2: ");
    // scanf("%i %i %i", &matrix[2][0], &matrix[2][1], &matrix[2][2]);

    for(int line = 0; line < ARRAY_MAX; line++) {
        printf("Digite a linha %i: ", line);
        for(int column = 0; column < ARRAY_MAX; column++) {
            scanf("%i", &matrix[line][column]);
        }
    }
    printf("%i", determinante(matrix));
    return 0;
}