#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Fa�a um programa que receba dois n�meros e mostre qual deles
 * � o maior. Caso os n�meros sejam iguais, o programa deve informar o usu�rio.
 * Os n�meros devem ser sempre exibidos com apenas duas casas ap�s a v�rgula.
 * Exemplos:
 *
 * Digite um numero: 5
 * Digite um numero: 7.5
 * 7.50 > 5.00
 *
 * Digite um numero: 5
 * Digite um numero: 5
 * Numeros iguais!
 */

int main (){

  float a,b;
  printf("Digite um numero: ");
  scanf("%f", &a);
  printf("Digite um numero: ");
  scanf("%f", &b);

  if(a > b){
    printf("%.2f > %.2f", a,b);
  }
  else{
    if (a < b){
      printf("%.2f > %.2f", b,a);
    }
    else {
      printf("Numeros iguais");
    }
  }
  return 0;
}
