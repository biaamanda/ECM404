#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Enunciado:
 *
 * Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e
 * armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados
 * da estrutura lida. Utilize, obrigatoriamente, uma função para realizar a leitura
 * da estrutura e outra função para realizar sua exibição.
 */

#define ARRAY_MAX_SIZE 100

typedef struct
{
  char name[ARRAY_MAX_SIZE];
  int age;
  char address[ARRAY_MAX_SIZE];
} Person;

Person readPerson()
{
  Person p;

  printf("Digite o nome: ");
  fgets(p.name, sizeof(p.name), stdin);
  p.name[strcspn(p.name, "\n")] = '\0'; // remove o \n do final

  printf("Digite a idade: ");
  scanf("%i", &p.age);
  getchar();

  printf("Digite o endereco: ");
  fgets(p.address, sizeof(p.address), stdin);
  p.address[strcspn(p.address, "\n")] = '\0';

  return p;
}

void displayPerson(Person p)
{
  printf("\n-- Dados da Pessoa --\n");
  printf("Nome: %s\n", p.name);
  printf("Idade: %i\n", p.age);
  printf("Endereco: %s\n", p.address);
}

int main(int argc, char *argv[])
{
  Person personData = readPerson();
  displayPerson(personData);

  return 0;
}
