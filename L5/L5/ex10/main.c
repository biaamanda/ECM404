/*
 * Enunciado:
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 * a seguir, exibir o maior palíndromo possível dentro da string digitada.
 * Caso não haja nenhum palíndromo possível, o programa deve alertar o usuário.
 * O programa deve desconsiderar diferenças entre letras minúsculas e letras
 * maiúsculas.
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
 *   Não existe nenhum palíndromo possível
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void ler_string(char s[MAX]);
void inverte_string(char s[MAX], char s_inv[MAX]);
void substring(char destino[MAX], char origem[MAX], int comeco, int fim);
int verifica_palindromo(char s[MAX]);
void maior_palindromo(char s[MAX], char s2[MAX]);
void to_lower_string(char s[MAX]);

int main (int argc, char *argv[]){


  return 0;
}

