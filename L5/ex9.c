/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usu�rio e,
 * a seguir, ler um intervalo separado por v�rgula que deve ser utilizado para
 * gerar uma substring que come�a no come�o do intervalo digitado e termina no
 * �ndice final (intervalo fechado).
 *
 * Exemplos:
 *
 * Digite uma string: Oi, eu sou o Goku!
 * Intervalo: 0, 9
 * Oi, eu sou
 *
 * Digite uma string: 0123456789
 * Intervalo: 3,7
 * 34567
 *
 * Digite uma string: Estruturas de Dados
 * Intervalo: 3, 12
 * ruturas de
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */

int main (int argc, char *argv[]){
  char array[MAX];
  char range[MAX];
  int start, end;

  //ler string
  printf("Digite uma string: ");
  fgets(array, MAX, stdin);
  array[strcspn(array, "\n")] = 0;

  printf("Intervalo: ");
  fgets(range, MAX, stdin);
  range[strcspn(range, "\n")] = 0;

  //ler o intervalo
  char *token = strtok(range, ",");
  if (token != NULL){
    start = atoi(token);
    token = strtok(NULL, ",");
    if (token != NULL){
      end = atoi(token);
    }
  }

  //imprimir string
  for (int i = start; i <= end; i++){
    putchar(array[i]);
  }
  
  return 0;
}
