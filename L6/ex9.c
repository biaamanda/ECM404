#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Crie uma estrutura representando um item de lista de compras (nome e preço).
 * Use um vetor de tamanho 100. Permita ao usuário adicionar itens e, ao final,
 * exiba o valor total da lista.
 */

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
  char name[MAX_NAME_LENGTH];
  float price;
} ShoppingItem;

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char *argv[])
{
  ShoppingItem items[MAX_ITEMS];
  int itemCount = 0;
  char choice;

  printf("=== LISTA DE COMPRAS ===\n\n");

  do {
    printf("Digite o nome do item %i: ", itemCount + 1);
    scanf("%49s", items[itemCount].name);
    clearInputBuffer();

    printf("Digite o preço do item: R$ ");
    scanf("%f", &items[itemCount].price);
    clearInputBuffer();

    itemCount++;

    if (itemCount < MAX_ITEMS) {
      printf("Deseja adicionar mais um item? (s/n): ");
      scanf("%c", &choice);
      clearInputBuffer();
      printf("\n");
    }
    else{
      printf("Lista cheia! Máximo de %i itens atingido.\n\n", MAX_ITEMS);
      break;
    }

  } while (choice == 's' || choice == 'S');

  printf("=== RESUMO DA LISTA ===\n");
  printf("Itens adicionados:\n");

  float total = 0.0;
  for (int i = 0; i < itemCount; i++) {
    printf("%i. %s - R$ %.2f\n", i + 1, items[i].name, items[i].price);
    total += items[i].price;
  }

  printf("\nValor total da lista: R$ %.2f\n", total);

  return 0;
}