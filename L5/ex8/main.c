/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma lista de nomes separados por v�rgula
 * digitados por um usu�rio e, a seguir, armazen�-los em um array de strings.
 * O array deve ser ordenado alfab�ticamente e, a seguir, exibido utilizando o
 * procedimento exibe_nomes fornecido. A quantidade de nomes digitado deve ser
 * sempre 5 (definido por MAX_NOMES). O programa deve desconsiderar a diferen�a
 * entre letras mai�sculas e min�sculas.
 *
 * Dica: pesquise pela fun��o strtok
 *
 * Exemplo (**CUIDADO COM O ESPA�O AP�S A V�RGULA**):
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['alexandre', 'diego', 'julio', 'nicola', 'tiririca']
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['ana julia', 'joao', 'marco antonio', 'matheus', 'victoria']
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
