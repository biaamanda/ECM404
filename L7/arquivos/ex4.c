#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 4 - Arquivos
 * Faça um programa que receba do usuário um arquivo texto, crie outro arquivo contendo o 
 * texto do arquivo de entrada, mas com as vogais substituídas por ‘*’.
 */

int main() {
    char filename[100];
    FILE *file, *file2;
    int c;

    printf("Qual o nome do seu arquivo: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL){
        perror("Erro em encontrar o arquivo.");
        return 1;
    }

    file2 = fopen("saida.txt", "w");

    if (file2 == NULL) {
        perror("Erro ao criar o arquivo de saída");
        fclose(file);
        return 1;
    }

    while ((c = fgetc(file)) != EOF){
        if (c == 'a' || c == 'e' ||c == 'i' ||c == 'o' ||c == 'u' || c == 'A' || c == 'E' ||c == 'I' ||c == 'O' ||c == 'U') {
            fputc('*', file2);
        } else {
            fputc(c, file2);
        }
    }

    fclose(file);
    fclose(file2);

    printf("Arquivo criado com vogais substituídas.\n");

    return 0;
}
