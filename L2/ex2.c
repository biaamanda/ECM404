#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Fa�a um programa que receba um n�mero inteiro digitado pelo
 * usu�rio e retorna se o n�mero � par ou �mpar.
 *
 * Exemplos:
 *
 * Digite um numero: 5
 * Impar
 *
 * Digite um numero: 4
 * Par
 */

int main ()
{
  int num;
  printf("Digite um numero: ");
  scanf("%i", &num);
  if (num % 2 == 0){
    printf("Par");
  }
  else{
    printf("Impar");
  }
  return 0;
}
