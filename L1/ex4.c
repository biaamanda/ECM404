#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia dois numero inteiros troque os valores entre as vari�veis e os imprima
 *
 * Ex:
 *      Digite um numero: 5
 *      Digite um numero: 7
 *      7 5
 */

int main (int argc, char *argv[])
{
  int firstNumber, secondNumber;
  printf("Digite um numero: ");
  scanf("%i", &firstNumber);

  printf("Digite um numero: ");
  scanf("%i",&secondNumber);

  // int temp = firstNumber;
  // firstNumber = secondNumber;
  // secondNumber = temp;

  // printf("%i %i", firstNumber, secondNumber);
  
  printf("%i %i", secondNumber, firstNumber);

  return 0;
}
