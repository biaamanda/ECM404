/*
 * Enunciado:
 * Desenvolva um programa capaz de ler duas palavras digitadas pelo usu�rio e,
 * a seguir, deve inform�-lo se as palavras formam um anagrama. O programa deve
 * desconsiderar a diferen�a entre letras ma�usculas e letras min�sculas.
 *
 * Exemplos:
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robed
 * bored � anagrama de robed
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robbed
 * bored n�o � anagrama de robbed
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: oii
 * ooi n�o � anagrama de oii
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: ioo
 * ooi � anagrama de ioo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */

void ordenarString(char str[]) {
  int len = strlen(str);
  char temp;
  for (int i = 0; i < len - 1; i++) {
      for (int j = 0; j < len - 1 - i; j++) {
          if (str[j] > str[j + 1]) {
              temp = str[j];
              str[j] = str[j + 1];
              str[j + 1] = temp;
          }
      }
  }
}

int main (int argc, char *argv[]){
  char word1[MAX], word2[MAX];
  char word1_original[MAX], word2_original[MAX]; //salvar a palavra original para nao printar a reeordenada
  int i;

  //pedir ao usuario uma palavra
  printf("Digite uma palavra: ");
  fgets(word1, MAX, stdin);
  printf("Digite uma palavra: ");
  fgets(word2, MAX, stdin);

  if(word1[strlen(word1) - 1] == '\n')
    word1[strlen(word1) - 1] = '\0';
  if(word2[strlen(word2) - 1] == '\n')
    word2[strlen(word2) - 1] = '\0';

  strcpy(word1_original, word1);
  strcpy(word2_original, word2);

  //transformar tudo em minuscula
  for (i = 0; i < strlen(word1); i++) 
    word1[i] = tolower(word1[i]);
  for (i = 0; i < strlen(word2); i++)
    word2[i] = tolower(word2[i]);

  ordenarString(word1);
  ordenarString(word2);

  if (strcmp(word1, word2) == 0) {
    printf("%s e anagrama de %s\n", word1_original, word2_original);
  }
  else {
    printf("%s nao e anagrama de %s\n", word1_original, word2_original);
  }
  return 0;
}