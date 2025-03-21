/* Enunciado:
 *  Desenvolva um programa capaz de ler os valores de uma matriz m x n.
 *  A leitura deve ser feita em uma linha para cada linha da matriz (ver ex1).
 *  A condi��o de parada para a leitura das linhas � uma linha vazia
 *  (apenas com -100). O programa deve assumir que a quantidade de colunas
 *  da primeira linha define a dimens�o da matriz, ou seja, qualquer linha
 *  subsequente que n�o tenha a mesma quantidade de linhas da linha inicial
 *  deve causar um erro e o encerramento do programa. Ap�s a leitura da matriz,
 *  ela deve ser exibida seguindo o padr�o mostrado nos exemplos a seguir.
 *
 *  Exemplos:
 *
 *   Linha 0: 1 1 1 -100
 *   Linha 1: 2 2 2 -100
 *   Linha 2: 3 3 3 -100
 *   Linha 3: -100
 *   [[1, 1, 1],
 *   [2, 2, 2],
 *   [3, 3, 3]]
 *
 *   Linha 0: 1 1 1 1 1 -100
 *   Linha 1: 1 2 3 -100
 *   N�mero de colunas incompat�vel. Saindo...
 *
 *   Linha 0: 1 2 3 4 5 6 7 8 -100
 *   Linha 1: 8 7 6 5 4 3 2 1 -100
 *   Linha 2: -100
 *   [[1, 2, 3, 4, 5, 6, 7, 8],
 *   [8, 7, 6, 5, 4, 3, 2, 1]]
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

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

int main() {
    int matrix[ARRAY_MAX][ARRAY_MAX];
    int rows, columns, is_error = 0;

    for (int current_row = 0; current_row < ARRAY_MAX; current_row++) {
        printf("Linha %i: ", current_row, i++);
        for(int current_column = 0; current_column < ARRAY_MAX; current_column++) {
            scanf("%i", &matrix[current_row][current_column]);

            if (matrix[current_row][current_column] == -100) {
                if(current_row == 0) {
                    columns = current_column;
                }
                else if(current_column > 0 && current_column != columns) {
                    printf("Numero de colunas incompativel. Saindo...");
                    is_error = 1;
                }
                break;
            }
        }
        rows = current_row;
        if(is_error == 1) {
            break;
        }
        if(matrix[current_row][0] == -100) {
            break;
        }
    }
    if(!is_error) {
        display_matrix(matrix, rows, columns);
    }
    
}