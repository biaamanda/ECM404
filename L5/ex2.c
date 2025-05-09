/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usu�rio e,
 * a seguir, informe-o se o valor digitado se trata de um pal�ndromo ou n�o.
 * O programa deve descosiderar diferen�a entre ma�usculas e min�sculas.
 *
 * Exemplos:
 *
 *  Digite uma string: racecar
 *  � pal�ndromo
 *
 *  Digite uma string: oi
 *  N�o � pal�ndromo
 *
 *  Digite uma string: RaceCar
 *  � pal�ndromo
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */

int main (int argc, char *argv[]){
  char string[MAX];
  char backward[MAX];
  int i, len;

  printf("Digite uma string: ");
  fgets(string, 100, stdin);

  len = strlen(string);
  if (string[len - 1] == '\n') {
      string[len - 1] = '\0';
      len--;
  }
  
  //converter todos os caracteres para minusculas
  for (i = 0; i < len; i++){
    string[i] = tolower(string[i]);
  }
  
  //inverter a string
  for (i=0; i < len; i++){
    backward[i] = string[len - 1 - i];
  }

  //verificar se a string original e a invertida sao iguais
  if(strcmp(string, backward) == 0){
    printf("É palíndromo");
  }
  else{
    printf("Não é palíndromo");
  }
  return 0;
}
