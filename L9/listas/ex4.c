#include <stdio.h>
#include <stdlib.h>

/*
 * Exercício 4 - Listas
 * Considerando uma lista previamente preenchida, faça uma função que retorne a média dos valores da lista.
 */

 typedef struct {
  int product;
  char productName[10];
  float value;
  int stockQuantity;
} Data;

float average(Data list[], int size) {
    float sum = 0;
    int i; 
    for (i = 0; i < size; i++) {
        sum += list[i].value;
    }
    return sum / size;
}
int main() {
    Data list[] = {
      {1, "Arroz", 25.0, 10},
      {2, "Feijao", 12.0, 20},
      {3, "Macarrao", 7.5, 15},
      {4, "Acucar", 9.0, 30}
    };

    int size = sizeof(list) / sizeof(list[0]);
    int avg = average(list, size);

    printf("Média dos valores da lista: %d \n", avg);

    return 0;
}