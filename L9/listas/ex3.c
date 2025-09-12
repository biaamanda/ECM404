#include <stdio.h>
#include <stdlib.h>

/*
 * Exercício 3 - Listas
 * Considerando uma lista previamente preenchida, faça uma função que retorne uma nova lista contendo apenas os números pares da lista.
 */

 typedef struct {
  int product;
  char productName[10];
  float value;
  int stockQuantity;
} Data;

int evenCountList(Data original[], int size, Data newList[]) {
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (original[i].product % 2 == 0) {
            newList[j] = original[i];
            j++;
        }
    }
    return j;
  }

int main() {
    Data list[] = {
      {1, "Arroz", 25.5, 10},
      {2, "Feijao", 12.0, 20},
      {3, "Macarrao", 7.5, 15},
      {4, "Acucar", 9.0, 30}
    };

    int size = sizeof(list) / sizeof(list[0]);

    Data newList[size];
    int newSize = evenCountList(list, size, newList);

    printf("Nova lista com produtos pares:\n");
    
    for (int i = 0; i < newSize; i++) {
        printf("Code: %d\n Produto: %s\n Valor: %.2f\n Estoque: %d\n", newList[i].product, newList[i].productName, newList[i].value, newList[i].stockQuantity);
    }

    return 0;
}