/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usu�rio e,
 * a seguir, exibir o maior pal�ndromo poss�vel dentro da string digitada.
 * Caso n�o haja nenhum pal�ndromo poss�vel, o programa deve alertar o usu�rio.
 * O programa deve desconsiderar diferen�as entre letras min�sculas e letras
 * mai�sculas.
 *
 * Exemplos:
 *
 *   Digite uma string: tiririca
 *   iriri
 *
 *   Digite uma string: I have a racecar
 *   racecar
 *
 *   Digite uma string: Cuidado com o Diego
 *   dad
 *
 *   Digite uma string: Alexandre
 *   N�o existe nenhum pal�ndromo poss�vel
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a fun��o tolower. Busque documenta��o.

#define MAX 100 // Valor m�ximo para o tamanho do array. N�o modifique.

/* Prot�tipos */
void read_string(char s[MAX]);
void reverse_string(char s[MAX], char s_inv[MAX]);
void substring(char destino[MAX], char origem[MAX], int comeco, int fim);
int check_palindrome(char s[MAX]);
void biggest_palindrome(char s[MAX], char s2[MAX]);
void to_lower_string(char s[MAX]);

int main (int argc, char *argv[]){
  char s[MAX];
  char result[MAX];

  read_string(s);
  to_lower_string(s);
  biggest_palindrome(s, result);

  if(strlen(result) > 0){
    printf("%s\n", result);
  }
  else {
    printf("Nao existe nenhum palindromo possivel\n");
  }
  return 0;
}

void read_string(char s[MAX]) {
  printf("Digite uma string: ");
  fgets(s, MAX, stdin);
  s[strcspn(s, "\n")] = 0;
}

void reverse_string(char s[MAX], char s_inv[MAX]) {
  int len = strlen(s);
  for (int i = 0; i < len; i++){
    s_inv[i] = s[len - 1 - i];
  }
  s_inv[len] = '\0';
}

void substring(char destino[MAX], char origem[MAX], int comeco, int fim){
  int j = 0;
  for (int i = comeco; i <= fim && origem[i] != '\0'; i++){
    destino[j++] = origem[i];
  }
  destino[j] = '\0';
}

int check_palindrome(char s[MAX]){
  char inversa[MAX];
  reverse_string(s, inversa);
  return strcmp(s, inversa) == 0;
}

void biggest_palindrome(char s[MAX], char s2[MAX]){
  int len = strlen(s);
  char temp[MAX];
  s2[0] = '\0';

  for (int i = 0; i < len; i++){
    for (int j = i + 1; j < len; j++){
      substring(temp, s, i , j);
      if (check_palindrome(temp)){
        if (strlen (temp) > strlen(s2)){
          strcpy(s2, temp);
        }
      }
    }
  }
}

void to_lower_string(char s[MAX]){
  for (int i = 0; s[i]; i++)
  s[i] = tolower(s[i]);
}