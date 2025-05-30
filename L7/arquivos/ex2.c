#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 2 - Arquivos
 * Faça um programa que receba do usuário um arquivo texto e mostra na tela quantas
 * linhas esse arquivo possui.
 */

int main() {
    char filename[100];
    FILE *file;
    int lineCount = 1;
    char c;

    printf("Qual o nome do arquivo que deseja: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    
    file = fopen(filename, "r");

    if (file == NULL){
        perror("Erro em abrir o arquivo");
        return 1;
    }

    
  while((c = fgetc(file)) != EOF){
    if (c == '\n'){
        //lineCount = lineCount+1;
        lineCount++;
    }
  }
  fclose(file);
  printf("Quantidade de linhas: %i", lineCount);
  
  return 0;
}