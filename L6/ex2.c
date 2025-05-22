#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Enunciado:
 *
 * Crie uma estrutura representando uma hora (hora, minuto, segundo). Escreva um
 * programa que leia um vetor de 5 posições dessa estrutura e imprima a maior hora.
 * Ajuste valores excedentes (segundos para minutos, minutos para horas).
 * Utilize funções para:
 * - leitura de cada estrutura (com ajuste);
 * - leitura do vetor;
 * - encontrar maior hora;
 * - comparar duas horas;
 * - exibir hora no formato hh:mm:ss.
 */

typedef struct {
  int hour;
  int minute;
  int second;
} Time;

// Função para ler e ajustar uma hora
Time readTime() {
  Time t;

  if (t.second >= 60) {
    t.minute += t.second / 60;
    t.second %= 60;
  }
  if (t.minute >= 60) {
    t.hour += t.minute / 60;
    t.minute %= 60;
  }

  return t;
}

int main(int main(int argc, char *argv[])) {

  return 0;
}
