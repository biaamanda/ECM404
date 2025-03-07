#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia um valor monetario (int) a ser pago e retorne
 * a solucao otimizada para quantas notas de 50, 10 e 2 sao necessarias para
 * compor aquele valor monetario, alem do troco necessario.
 *
 * Formato da saida:
 *  N50: **qtd_50** N10: **qtd_10** N2: **qtd_2** T: **troco**
 *
 *
 * Ex:
 *      Total: 60
 *      N50: 1 N10: 1 N2: 0 T: 0
 *
 *      Total: 85
 *      N50: 1 N10: 3 N2: 2 T: 1
 *
 *      Total: 171
 *      N50: 3 N10: 2 N2: 0 T: 1
 *
 */

int main (int argc, char *argv[])
{
  int bill_value;
  printf("Total: ");
  scanf("%i", &bill_value);

  int fity_bill_amount = bill_value / 50;
  int fity_bill_amount_remain = bill_value % 50;

  int ten_bill_amount = fity_bill_amount_remain / 10;
  int ten_bill_amount_remain = fity_bill_amount_remain % 10;

  int two_bill_amount = ten_bill_amount_remain / 2;
  int two_bill_amount_remain = ten_bill_amount_remain % 2;

  int one_bill_amount = two_bill_amount_remain;

  printf("N50: %i N10: %i N2: %i T: %i", fity_bill_amount, ten_bill_amount, two_bill_amount, one_bill_amount);

  return 0;
}
