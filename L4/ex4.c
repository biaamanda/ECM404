/**
 * Enunciado | Exercício 4
 *
 * Desenvolva um programa capaz de ler os valores de uma matriz m x n.
 * A leitura deve ser feita em uma linha para cada linha da matriz (ver ex1).
 * A condição de parada para a leitura das linhas é uma linha vazia
 * (apenas com -100). O programa deve assumir que a quantidade de colunas
 * da primeira linha define a dimensão da matriz, ou seja, qualquer linha
 * subsequente que não tenha a mesma quantidade de linhas da linha inicial
 * deve causar um erro e o encerramento do programa. Após a leitura da matriz,
 * ela deve ser exibida seguindo o padrão mostrado nos exemplos a seguir.
 *
 * Linha 0: 1 1 1 -100
 * Linha 1: 2 2 2 -100
 * Linha 2: 3 3 3 -100
 * Linha 3: -100
 * [[1, 1, 1],
 * [2, 2, 2],
 * [3, 3, 3]]
 *
 * Linha 0: 1 1 1 1 1 -100
 * Linha 1: 1 2 3 -100
 * Número de colunas incompatível. Saindo...
 *
 * Linha 0: 1 2 3 4 5 6 7 8 -100
 * Linha 1: 8 7 6 5 4 3 2 1 -100
 * Linha 2: -100
 * [[1, 2, 3, 4, 5, 6, 7, 8],
 * [8, 7, 6, 5, 4, 3, 2, 1]]
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 #define ARRAY_MAX_SIZE 100
 #define INPUT_STOP_VALUE -100
 
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
 
 void main()
 {
     int matrix[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];
     int rowsCount, columnsCount, isError = 0;
 
     for (int currentRow = 0; currentRow < ARRAY_MAX_SIZE; currentRow++)
     {
         printf("Linha %i: ", currentRow);
 
         for (int currentColumn = 0; currentColumn < ARRAY_MAX_SIZE; currentColumn++)
         {
             scanf("%i", &matrix[currentRow][currentColumn]);
 
             if (matrix[currentRow][currentColumn] == INPUT_STOP_VALUE)
             {
                 if (currentRow == 0)
                 {
                     columnsCount = currentColumn;
                 }
                 else if (currentColumn > 0 && currentColumn != columnsCount)
                 {
                     printf("Numero de colunas incompativel. Saindo...");
                     isError = 1;
                 }
 
                 break;
             }
         }
 
         rowsCount = currentRow;
 
         if (isError == 1)
         {
             break;
         }
 
         if (matrix[currentRow][0] == INPUT_STOP_VALUE)
         {
             break;
         }
     }
 
     if (!isError)
     {
         displayMatrix(matrix, rowsCount, columnsCount);
     }
 }