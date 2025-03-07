#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Em matem�tica, o n�mero harm�nico designado por H(n) define-se
 * como sendo a soma da s�rie harm�nica:
 *
 *                         H(n) = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
 *
 * Fa�a um programa que leia um valor n inteiro e positivo e
 * apresente o valor de H(n) com duas casas decimais
 *
 * Exemplos:
 *
 * Digite um valor para n: 10
 * 2.93
 *
 * Digite um valor para n: -1
 * Erro, n menor que 0!
 */

int main()
{
    int n, i;
    float result;

    printf("Digite um valor para n: ");
    scanf("%i", &n);

    if(n <= 0){
        printf("Erro, nao pode ser menor que 0!");
    }
    else{
        for(i=1; i<n; i++){
            result += 1.0/i;
        }
    }
    printf("%.2f", result);
    
    return 0;
}
