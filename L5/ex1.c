/*
 * Enunciado:
 *  Desenvolva um programa capaz de ler uma string digitada pelo usu�rio e,
 *  a seguir, exiba essa string invertida.
 *
 *  Exemplo:
 *    Digite uma string: ola
 *    alo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */

int main (int argc, char *argv[]){
  char string[MAX];
  int i, len;

  printf("Digite uma string: ");
  fgets(string, 100, stdin);

  len = strlen(string);
  if (string[len - 1] == '\n') {
      string[len - 1] = '\0';
      len--;
  }

  for (i = len - 1; i >= 0; i--) {
      putchar(string[i]);
  }
  putchar('\n');
  
  return 0;
}
