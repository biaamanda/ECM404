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
  char input[MAX];
  char names[MAX_NOMES][MAX];
  char *token;
  int i = 0;
   
  printf("Nomes: ");
  fgets(input, MAX, stdin);
  input[strcspn(input, "\n")] = 0;

  token = strtok(input, ",");
  while (token != NULL && i < MAX_NOMES) {
    while(*token == ' ') token ++;

    strncpy(names[i], token, MAX - 1);
    names[i][MAX - 1] = '\0';

    for (int j = 0; names[i][j]; j++){
      names[i][j] = tolower(names[i][j]);
  }
  i++;
  token = strtok(NULL, ",");
}

  for (int j = 0; j < MAX_NOMES - 1; j++) {
    for(int k = 0; k < MAX_NOMES - 1 - j; k++) {
      if (strcmp(names[k], names[k + 1]) > 0) {
        char temp[MAX];
        strcpy(temp, names[k]);
        strcpy(names[k], names[k + 1]);
        strcpy(names[k + 1], temp);
      }
    }
  }
  exibe_nomes(names);
   
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
