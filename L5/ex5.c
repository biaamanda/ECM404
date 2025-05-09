/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma palavra digitada pelo usu�rio e,
 * a seguir, deve exibir uma string contendo os caracteres da palavra digitada
 * em ordem alfab�tica. Utilize o algoritmo de ordena��o que preferir.
 * O programa deve desconsiderar a diferen�a entre letras ma�usculas e
 * letras min�sculas.
 *
 * Exemplos:
 *
 *   Digite uma palavra: ola
 *   alo
 *
 *   Digite uma palavra: alo
 *   alo
 *
 *   Digite uma palavra: RaceCar
 *   aaccerr
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */

int main (int argc, char *argv[]){
  char word[MAX];
  int i, j, len;
  char temp;

  //pedir ao usuario uma palavra
  printf("Digite uma palavra: ");
  fgets(word, MAX, stdin);

  len = strlen(word);
  if(word[len - 1] == '\n') {
    word [len - 1] = '\0';
    len--;
  }

  //transformar tudo em minuscula
  for (i =0; i < len; i++) {
    word[i] = tolower(word[i]);
  }

  //retornar em ordem alfabetica
  for (i = 0; i < len; i++) {
    for(j = 0; j < len - 1 - i; j++) {
      if (word[j] > word[j + 1]) {
        temp = word[j];
        word[j] = word[j + 1];
        word[j + 1] = temp;
      }
    }
  }
  printf("%s", word);

  return 0;
}