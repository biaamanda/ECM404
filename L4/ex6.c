/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de uma matriz 3x3
 * e, a seguir, exiba a sua forma transposta
 *
 * Exemplos:
 *
 *
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    [[1, 4, 7],
 *    [2, 5, 8],
 *    [3, 6, 9]]
 *
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    [[1, 0, 0],
 *    [0, 1, 0],
 *    [0, 0, 1]]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 3 // Valor m�ximo para o tamanho do array. N�o modifique.

void display_matrix(int matrix[ARRAY_MAX][ARRAY_MAX], int rows, int columns) {
    printf("[");
    for (int display_row = 0; display_row < rows; display_row++) {
        printf("[");
        for (int display_column = 0; display_column < columns; display_column++) {
            printf((display_column == columns -1 ? "%i" : "%i, "), matrix[display_row][display_column]);
        }
        printf(display_row == rows - 1 ? "]" : "],\n");
    }
    printf("]");
}

int main()
{
    int matrix[ARRAY_MAX][ARRAY_MAX];

    for(int line = 0; line < ARRAY_MAX; line++) {
        printf("Digite a linha %i: ", line);
        for(int column = 0; column < ARRAY_MAX; column++) {
            scanf("%i", &matrix[line][column]);
        }
    }
    display_matrix(matrix, ARRAY_MAX, ARRAY_MAX);
    return 0;
}