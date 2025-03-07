#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia os valores de duas resistencias eletricas (int)
 * e, em seguida, exiba o resultado da sua resistencia equivalente em serie
 * e em paralelo. O formato da saida deve ser:
 *
 * S: **Req_Serie** P: **Req_Paralelo**
 *
 *
 * Ex:
 *      R1: 3
 *      R2: 3
 *      S: 6 P: 1.50
 *
 *      R1: 5
 *      R2: 12
 *      S: 17 P: 3.53
 *
 * OBS: Utilize duas casas decimais para representar valores flutuantes.
 */

int main (int argc, char *argv[])
{
  int R1, R2;

  printf("R1: ");
  scanf("%i", &R1);

  prinft("R2: ");
  scanf("%i", &R2);

  int s = R1 + R2;

  float R1_f = R1 * 1.0;
  float R2_f = R2 * 1.0;
  float p = (R1_f * R2_f) / (R1_f + R2_f);

  printf("S: %i P: %.2f\n", s, p);

  return 0;
}
