#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Fa�a um programa que receba um n�mero inteiro e, a seguir,
 * exibe todos os seus poss�veis divisores separados apenas por um espa�o.
 *
 * Exemplos:
 *
 * Digite um numero: 7
 * 1 7
 *
 * Digite um numero: 12
 * 1 2 3 4 6 12
 */

int main()
{
    int num, i;
    printf("Digite um numero: ");
    scanf("%i", &num);

    for(i=1; 1<=num; i++){
        int result = num % i;

        if (result == 0){
            printf("%i ", i);
        };

    }
    return 0;
}
