#include <stdio.h>
#include <stdlib.h>

/*
 * Exercício 5 - Listas
 * Considerando uma lista previamente preenchida, faça uma função que retorne o número de elementos da lista que possuem um número primo armazenado.
 */

 typedef struct {
  int product;
  char productName[10];
  float value;
  int stockQuantity;
} Data;

int primeNumber(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int countPrime(Data list[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (primeNumber(list[i].product)) {
            count++;
        }
    }
    return count;
}

int main() {
    Data list[] = {
      {1, "Arroz", 25.0, 10},
      {2, "Feijao", 12.0, 20},
      {3, "Macarrao", 7.5, 15},
      {4, "Acucar", 9.0, 30}
    };

    int size = sizeof(list) / sizeof(list[0]);
    int primeCount = countPrime(list, size);

    printf("Quantidade de números primos: %d \n", primeCount);

    return 0;
}