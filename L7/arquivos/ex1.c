#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 1 - Arquivos
 * Escreva um programa que:
  a. Crie/abra um arquivo texto de nome “arq.txt”
  b. Permita que o usuário grave diversos caracteres nesse arquivo, até que o usuário entre com o caractere ‘0’
  c. Feche o arquivo
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados.
 */

int main() {
  FILE *file;
  char c;

  file = fopen("arq.txt", "w");

  if (file == NULL) {
    perror("Erro ao abrir o arquivo!");
    return 1;
  }


  while(1){
    c = getchar();
    if (c == '0'){
      break;
    }
    fputc(c, file);
  }

  fclose(file);

  file = fopen("arq.txt", "r");
  if (file == NULL){
    perror("Erro ao abrir o arquivo!");
    return 1;
  }

  while((c = fgetc(file)) != EOF){
    putchar(c);
  }
  fclose(file);

  return 0;
}
