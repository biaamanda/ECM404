#include <stdio.h>
#include <stdlib.h>

/*
 * Exercício 1 - Listas
 * Considerando uma lista previamente preenchida, faça uma função para buscar o produto de menor valor. A função deve retornar se a operação foi possível ou não e, se encontrado, os valores retornam por referência. Faça a alteração na estrutura Dados:
 */

 typedef struct {
  int product;
  char productName[10];
  float value;
  int stockQuantity;
} Data;

int lowerPrice(Data list[], int size, Data *lower) {
  if (size <= 0) {
    return 0;
  }

  *lower = list[0];
  for(int i = 1; i < size; i++) {
    if(list[i].value < lower->value) {
      *lower = list[i];
    }
  }
  return 1;
}

int main() {
    Data list[] = {
      {1, "Arroz", 25.5, 10},
      {2, "Feijao", 12.0, 20},
      {3, "Macarrao", 7.5, 15},
      {4, "Acucar", 9.0, 30}
    };
    int size = sizeof(list) / sizeof(list[0]);

    Data lower;
    if(lowerPrice(list, size, &lower)) {
      printf("Produto mais barato: \n");
      printf("Code: %d\n", lower.product);
      printf("Nome: %s\n", lower.productName);
      printf("Valor: %.2f\n", lower.value);
      printf("Estoque: %d\n", lower.stockQuantity);
    }
    else {
      printf("Lista vazia\n");
    }

    return 0;
}