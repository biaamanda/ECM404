#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Escreva um programa que leia um numero inteiro e depois o exiba na tela
 *
 * Ex:
 *      Digite um numero: 5
 *      5
 */

int main (int argc, char *argv[]){
  int n;
  printf("Digite um numero: ");
  scanf("%i",&n);
  printf("%i\n",n);

  return 0;
}
