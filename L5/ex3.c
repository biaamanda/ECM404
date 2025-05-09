/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usu�rio e,
 * a seguir, solicite ao usu�rio que digite um caractere a ser buscado na
 * string digitada. O programa deve informar ao usu�rio se o caractere foi
 * encontrado ou n�o. O programa deve desconsiderar a difere�a entre ma�usculas
 * e min�sculas. Utilize o algoritmo de busca que achar melhor.
 *
 * Exemplos:
 *
 *   Digite uma string: teste!
 *   Digite a chave: !
 *   Caractere ! encontrado na posi��o 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: M
 *   Caractere m encontrado na posi��o 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: m
 *   Caractere m encontrado na posi��o 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: b
 *   Caractere b n�o foi encontrado.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */

int main (int argc, char *argv[]){
  char string[MAX];
  char search_char;
  int i, len, found = 0;
  
  //pedir para o usuario digitar uma string
  printf("Digite uma string: ");
  fgets(string, MAX, stdin);

  len = strlen(string);
  if (string[len - 1] == '\n') {
    string[len - 1] = '\0';
    len--;
  }

  //pedir para o usuario digitar um caractere
  printf("Digite a chave: ");
  search_char = getchar();

  //transformar tudo em minuscula
  search_char = tolower(search_char);
  for (i = 0; i < len; i++){
    string[i] = tolower(string[i]);
  }
  //procurar um caracter
  for (i = 0; i < len; i++){
    if(string[i] == search_char){
      printf("Caractere %c encontrado na posição %d. \n", search_char, i);
      found = 1;
      break;
    }
  }
  //se nao for encontrado
  if(!found){
    printf("Caractere %c não foi encontrado. \n", search_char);
  }

  return 0;
}
