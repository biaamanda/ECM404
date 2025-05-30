#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 5 - Arquivos
 * Faça um programa que receba dois arquivos do usuário e crie um terceiro arquivo com o conteúdo
 * dos dois arquivos recebidos juntos (o conteúdo do primeiro seguido do conteúdo do segundo).
 */

int main() {
    char filename[100], filename2[100];
    FILE *file, *file2, *file3;
    int c;

    printf("Qual o nome do seu primeiro arquivo: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Qual o nome do seu segundo arquivo: ");
    fgets(filename2, 100, stdin);
    filename2[strcspn(filename2, "\n")] = '\0';

    file = fopen(filename, "r");
    file2 = fopen(filename2, "r");
    file3 = fopen("uniaodearquivos.txt", "w");

    if (file == NULL){
        perror("Erro em encontrar o arquivo.");
        return 1;
    }
    if (file2 == NULL){
        perror("Erro em encontrar o arquivo.");
        return 1;
    }
    if (file3 == NULL) {
        perror("Erro ao criar o arquivo de saída.");
        fclose(file);
        fclose(file2);
        return 1;
    }

    while((c = fgetc(file)) != EOF){
        fputc(c, file3);
    }

    while((c = fgetc(file2)) != EOF){
        fputc(c, file3);
    }

    fclose(file);
    fclose(file2);
    fclose(file3);

    printf("Uniao de arquivos realizada.");

    return 0;
}
