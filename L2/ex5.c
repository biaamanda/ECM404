#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Enunciado - Fa�a um programa que leia uma data no seguinte formato:
 * D/M/A. O programa deve determinar se a data digitada v�lida ou n�o.
 * Lembre-se que Fevereiro tem 29 dias em anos bissextos e 28 dias em anos n�o
 * bissextos.
 *
 * Exemplos:
 *
 * Data: 22/02/2022
 * Data valida!
 *
 * Data: 29/02/2020
 * Data valida!
 *
 * Data: 29/02/2022
 * Data invalida!
 *
 * Data: 31/06/2022
 * Data invalida!
 *
 * Data: 31/13/2022
 * Data invalida!
 */

void main() {
    // 1) Receber dados
    int dia, mes, ano;

    printf("Data: ");
    scanf("%i/%i/%i", &dia, &mes, &ano);

    // 2) Validar data
    // 2.1) Ver se dados sao maiores que zero
    if (dia < 0 || mes < 0 || ano < 0) {
        printf("Data invalida!");
        return;
    }

    // 2.2 Ver se mes menor ou igual a 12
    if(mes > 12) {
        printf("Data invalida!");
        return;
    }
    // 2.3) Ver se e ano bi
    int bissexto = false;

    if((ano % 4) == 0) {
        bissexto = true;
    }

    // 2.4) ver o maximo de dias possiveis com base no mes da data
    // 2.4.1) Fevereiro
    if(mes == 2){
        if(bissexto){
            if(dia > 29){
                printf("Data invalida!");
                return;
            }

        } else {
            if(dia > 28){
                printf("Data invalida!");
                return;
            }
        }
    }


    // 2.4.2) meses com 31 dias
    if (mes == 1 || mes == 3 || mes == 5|| mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if(dia > 31){
            printf("Data invalida!");
            return;
        }
    } else {           
        if(dia > 30){
            printf("Data invalida!");
            return;
        }

    }

    // 3) Retornar resposta
    printf("Data valida!");
    }