/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma lista de nomes separados por v�rgula
 * digitados por um usu�rio e, a seguir, armazen�-los em um array de strings,
 * que deve ser exibido utilizando o procedimento exibe_nomes fornecido.
 * A quantidade de nomes digitado deve ser sempre 5 (definido por MAX_NOMES).
 *
 * Dica: pesquise pela fun��o strtok
 *
 * Exemplo (**CUIDADO COM O ESPA�O AP�S A V�RGULA**):
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['Matheus', 'Ana Julia', 'Marco Antonio', 'Joao', 'Victoria']
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['Julio', 'Tiririca', 'Diego', 'Alexandre', 'Nicola']
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 5 // Valor m�ximo para o tamanho do array. N�o modifique.
#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */
void exibe_nomes(char nomes[MAX_NOMES][MAX]);

int main (int argc, char *argv[]){
  return 0;
}

void exibe_nomes(char nomes[MAX_NOMES][MAX]) {
  printf("[");
  for(int i = 0; i < MAX_NOMES; ++i) {
    printf("'%s'", nomes[i]);
    if( i != MAX_NOMES - 1 ) printf(", ");
  }
  printf("]\n");
}
