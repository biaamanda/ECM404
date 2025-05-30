#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 3 - Arquivos
 * Faça um programa que receba do usuário um arquivo texto e um caractere e mostre na tela 
 * quantas vezes aquele caractere ocorre dentro do arquivo.
 */

int main() {
    char filename[100];
    FILE *file;
    char searchCaracter;
    int c;
    int count = 0;

    printf("Qual o nome do seu arquivo: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL){
        perror("Erro em encontrar o arquivo: ");
        return 1;
    }

    printf("Qual o caracter que deseja procurar: ");
    scanf(" %c", &searchCaracter);

    while((c = fgetc(file)) != EOF){
        if(c == searchCaracter){
            count++;
        }
    }

    fclose(file);

    printf("O caracter %c foi encontrado %d vezes.", searchCaracter, count);

    return 0;
}
