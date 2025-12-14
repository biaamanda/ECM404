#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Elabore um programa que leia um numero inteiro e exiba-o na tela como um numero flutuante e, logo em seguida, exiba o mesmo numero mas com apenas duas casas apos a virgula
 *
 * Ex:
 *  Digite um numero: 5
 *  5.000000 5.00
 */

 int main(int argc, char *argv[])
 {
    int number; 
    printf("Digite um numero: ");
    scanf("%i", &number);
 
    float floatNumber = number * 1.0;
    printf("%f %.2f\n", floatNumber, floatNumber);
 
     return 0;
 }