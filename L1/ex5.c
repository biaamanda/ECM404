#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia um numero de 5 digitos e, em seguida, exiba
 * o numero digitado com os digitos invertidos.
 *
 * Ex:
 *      Digite um numero: 54321
 *      12345
 *
 *      Digite um numero: 38271
 *      17283
 *
 */

int main (int argc, char *argv[])
{
  int five_digit;
  printf("Digite um numero: ");
  scanf("%i", &five_digit);

  int fith_digit = five_digit / 10000;
  int fith_digit_remain = five_digit % 100000;

  int forth_digit = fith_digit_remain / 1000;
  int forth_digit_remain = fith_digit_remain % 1000;

  int third_digit = forth_digit_remain / 100;
  int third_digit_remain = forth_digit_remain % 100;

  int second_digit = third_digit_remain /10;
  int second_digit_remain = third_digit_remain % 10;

  int first_digit = second_digit_remain / 1;

  printf("%i%i%i%i%i\n", first_digit, second_digit, third_digit, forth_digit, fith_digit);

  return 0;
}
