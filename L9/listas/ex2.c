#include <stdio.h>
#include <stdlib.h>

/*
 * Exercício 2 - Listas
 * Considerando uma lista previamente preenchida, faça uma função que retorne quantos números pares existem na lista.
 */

 typedef struct {
  int product;
  char productName[10];
  float value;
  int stockQuantity;
} Data;

int evenCount(Data list[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (list[i].product % 2 == 0) {
            count++;
        }
    }
    return count;
  }

int main() {
    Data list[] = {
      {1, "Arroz", 25.5, 10},
      {2, "Feijao", 12.0, 20},
      {3, "Macarrao", 7.5, 15},
      {4, "Acucar", 9.0, 30}
    };

    int size = sizeof(list) / sizeof(list[0]);
    int quantity = evenCount(list, size);

    printf("Quantidade de produtos pares: %d\n", quantity);

    return 0;
}