/* Enunciado:
 * Desenvolva um programa capaz de ler os valores inteiros de duas matriz 3x3
 * e, a seguir, exiba a matriz resultante da multiplica��o entre elas.
 *
 * Exemplos:
 *
 *    Digite a linha 0: 1 0 0
 *    Digite a linha 1: 0 1 0
 *    Digite a linha 2: 0 0 1
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[1, 1, 1],
 *    [2, 2, 2],
 *    [3, 3, 3]]
 *
 *    Digite a linha 0: 1 2 3
 *    Digite a linha 1: 4 5 6
 *    Digite a linha 2: 7 8 9
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[14, 14, 14],
 *    [32, 32, 32],
 *    [50, 50, 50]]
 *
 *    Digite a linha 0: 2 0 0
 *    Digite a linha 1: 0 2 0
 *    Digite a linha 2: 0 0 2
 *    Digite a linha 0: 1 1 1
 *    Digite a linha 1: 2 2 2
 *    Digite a linha 2: 3 3 3
 *    [[2, 2, 2],
 *    [4, 4, 4],
 *    [6, 6, 6]]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 3 // Valor m�ximo para o tamanho do array. N�o modifique.

void displayMatrix(int matrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int rowsCount, int columnsCount)
{
    printf("[");
    for (int displayRow = 0; displayRow < rowsCount; displayRow++)
    {
        printf("[");
        for (int displayColumn = 0; displayColumn < columnsCount; displayColumn++)
        {
            printf((displayColumn == columnsCount - 1 ? "%i" : "%i, "), matrix[displayRow][displayColumn]);
        }
        printf(displayRow == rowsCount - 1 ? "]" : "],\n");
    }
    printf("]");
}

void multiplyMatrices(int firstMatrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int secondMatrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int resultMatrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE])
{
    // Initialize result matrix to zero
    for (int row = 0; row < ARRAY_MAX_SIZE; row++) {
        for (int col = 0; col < ARRAY_MAX_SIZE; col++) {
            resultMatrix[row][col] = 0;
        }
    }

    // Perform matrix multiplication
    for (int resultRow = 0; resultRow < ARRAY_MAX_SIZE; resultRow++) {
        for (int resultCol = 0; resultCol < ARRAY_MAX_SIZE; resultCol++) {
            for (int element = 0; element < ARRAY_MAX_SIZE; element++) {
                resultMatrix[resultRow][resultCol] += firstMatrix[resultRow][element] * secondMatrix[element][resultCol];
            }
        }
    }
}

void main()
{
    int firstMatrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];
    int secondMatrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];
    int resultMatrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];

    for (int inputMatrix = 0; inputMatrix < 2; inputMatrix++)
    {
        for (int currentRow = 0; currentRow < ARRAY_MAX_SIZE; currentRow++)
        {
            printf("Digite a linha %i: ", currentRow);

            for (int currentColumn = 0; currentColumn < ARRAY_MAX_SIZE; currentColumn++)
            {
                scanf("%i", inputMatrix == 0 ? &firstMatrix[currentRow][currentColumn] : &secondMatrix[currentRow][currentColumn]);
            }
        }
    }

    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix);

    displayMatrix(resultMatrix, ARRAY_MAX_SIZE, ARRAY_MAX_SIZE);
}