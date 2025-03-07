#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que receba um valor inteiro de 6 digitos do usuario
 * e, em seguida, exiba uma versao binaria falsa desse numero. Para calcular
 * a versao binaria falsa, verifique cada um dos digitos do numero e, se o
 * digito for maior ou igual a 5, transforme-o em 1, se for menor, transforme-o
 * em 0.
 *
 *
 * Ex:
 *     Digite um numero: 123456
 *     000011
 *
 *     Digite um numero: 583910
 *     110100
 *
 *     Digite um numero: 830209
 *     100001
 *
 * DICA: Lembre-se das ferramentas de quebra de fluxo que tinhamos em Python.
 * Como usa-las em C? Pesquise!
 *
 */

int main (int argc, char *argv[])
{
  int six_digit_value;

  printf("Digite um numero: ");
  scanf("%i", &six_digit_value);

  int sixth_digit = six_digit_value / 100000;
  int sixth_digit_remain = (six_digit_value % 100000);

  int fith_digit = sixth_digit_remain / 10000;
  int fith_digit_remain = (sixth_digit_remain % 10000);

  int forth_digit = fith_digit_remain / 1000;
  int forth_digit_remain = fith_digit_remain % 1000;

  int third_digit = forth_digit_remain / 100;
  int third_digit_remain = forth_digit_remain % 100;

  int second_digit = third_digit_remain / 10;
  int second_digit_remain = third_digit_remain % 10;

  int first_digit = second_digit_remain / 1;

  printf("%i%i%i%i%i%i",
         (sixth_digit >= 5) ? 1 : 0,
         (fith_digit >= 5) ? 1 : 0,
         (forth_digit >= 5) ? 1 : 0,
         (third_digit >= 5) ? 1 : 0,
         (second_digit >= 5) ? 1 : 0,
         (first_digit >= 5) ? 1 : 0);

  return 0;
}
