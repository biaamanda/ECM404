/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usu�rio e,
 * a seguir, implemente a estrat�gia de criptografia ZENIT - POLAR.
 * A estrat�gia em quest�o consiste em substituir os caracteres da string
 * da seguinte maneira:
 *
 *            Z <-> P
 *            E <-> O
 *            N <-> L
 *            I <-> A
 *            T <-> R
 *
 * O programa deve desconsiderar a diferen�a entre letras ma�usculas e
 * letras min�sculas.
 *
 * Exemplos:
 *
 *   Digite uma string: polar
 *   zenit
 *
 *   Digite uma string: zenit
 *   polar
 *
 *   Digite uma string: ZeNit
 *   polar
 *
 *   Digite uma string: seu ou, e ratataci!
 *   sou eu, o tiririca!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */

int main (int argc, char *argv[]){
  char string[MAX];
  int i, len;
  
  //string desejada
  printf("Digite uma string: ");
  fgets(string, MAX, stdin);

  len = strlen(string);
  if (string[len - 1] == '\n'){
    string[len -1] = '\0';
    len--;
  }
  //implementar criptografia
for (i = 0; i < len; i++) {
  char c = tolower(string[i]);
  switch (c) {
    case 'z': string[i] = 'p'; break;
    case 'e': string[i] = 'o'; break;
    case 'n': string[i] = 'l'; break;
    case 'i': string[i] = 'a'; break;
    case 't': string[i] = 'r'; break;
    case 'p': string[i] = 'z'; break;
    case 'o': string[i] = 'e'; break;
    case 'l': string[i] = 'n'; break;
    case 'a': string[i] = 'i'; break;
    case 'r': string[i] = 't'; break;
    default: break;
  }
}
  printf("%s", string);
  return 0;
}
