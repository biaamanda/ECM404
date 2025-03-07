#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Fa�a um programa que leia um numero inteiro positivo par e,
 * a seguir, exiba todos os numeros pares de 0 ate o numero digitado em ordem
 * crescente, separados apenas por um espaco.
 *
 * Exemplos:
 *
 * Numero: 5
 * Digite um numero par!
 *
 * Numero: -5
 * Digite um numero positivo!
 *
 * Numero: 6
 * 0 2 4 6
 *
 * Numero: 14
 * 0 2 4 6 8 10 12 14
 */

int main()
{
    int number;
    int i;
    printf("Digite um numero: ");
    scanf("%i", &number);

    if (number % 2 == 0 && number >=0){
        printf("0 ");
        for(i=2; i <= number; i+=2){
            int result = number % i;
            printf("%i ", i);
        }
    }
    else {
        printf("Digite um numero par");
    }
    return 0;
}
