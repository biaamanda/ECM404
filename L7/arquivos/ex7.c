#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 7 - Arquivos
 * Faça um programa gerenciar uma agenda de contatos. Para cada contato armazene o nome, 
 * o telefone e o aniversário (dia e mês). O programa deve permitir:
  a. inserir contato
  b. remover contato
  c. pesquisar um contato pelo nome
  d. listar todos os contatos
  e. listar os contatos cujo nome inicia com uma dada letra
  f. imprimir os aniversariantes do mês.
Sempre que o programa for encerrado, os contatos devem ser armazenados em um arquivo.
Quando o programa iniciar, os contatos devem ser inicializados com os dados contidos neste arquivo.
 */

int main() {
    char name[50];
    char phoneNumber[20];
    int day, month;

    printf("Digite o nome: ");
    fgets(name, 50, stdin);

    printf("Digite seu numero: ");
    fgets(phoneNumber, 20, stdin);

    printf("Digite o dia do seu aniversario: ");
    scanf("%d", &day);

    printf("Digite o mes do seu aniversario: ");
    scanf("%d", &month);

    printf("\nContato:\n");
    printf("Nome: %s\n", name);
    printf("Telefone: %s\n", phoneNumber);
    printf("Aniversario: %02d/%02d\n", day, month);

    return 0;
}
