#include <stdio.h>
#include <stdlib.h>

/* Enunciado - Fa�a um programa que leia duas notas de um aluno em uma
 * �nica linha, separando cada valor com uma v�rgula. Verifique se as notas
 * s�o v�lidas e, caso sejam exiba a m�dia do aluno na tela. Para que a nota
 * seja v�lida, ela deve estar entre 0.0 e 10.0. Caso alguma das notas n�o seja
 * v�lida, o programa deve informar o usu�rio e encerrar sua opera��o.
 *
 * Exemplos:
 *
 * Notas: 5.0, 10.0
 * 7.5
 *
 * Notas: 5, 5.0
 * 5.0
 *
 * Notas: -1.0, 5.0
 * Nota invalida. Deve ser entre 0.0 e 10.0
 */

int main()
{
    float nota1, nota2;
    printf("Notas: ");
    scanf("%f, %f", &nota1, &nota2);

    if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10){
        printf("Nota invalida. Deve ser entre 0.0 e 10.0");
    }
    else{
        printf("%.2f", (nota1 + nota2) / 2);
    }
    return 0;
}
