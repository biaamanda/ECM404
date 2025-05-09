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
 void exibe_nomes(char names[MAX_NOMES][MAX]);
 
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
    i++;
    token = strtok(NULL, ",");
  }
   if (i == MAX_NOMES) {
    exibe_nomes(names);
  }
   
   return 0;
}
 
 void exibe_nomes(char names[MAX_NOMES][MAX]) {
   printf("[");
   for(int i = 0; i < MAX_NOMES; ++i) {
     printf("'%s'", names[i]);
     if( i != MAX_NOMES - 1 ) printf(", ");
   }
   printf("]\n");
 }
 