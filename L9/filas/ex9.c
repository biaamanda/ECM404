#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
/*
 * Exercício 9 - Filas
 * Para as partidas de videogame, o pessoal resolveu formar dois times, cada qual armazenado em uma fila com o nickname dos jogadores. Após cadastrar todos os jogadores, o programa deve exibir os primeiros de cada fila e iniciar um laço onde o usuário digita o número do time vencedor (1 ou 2). O jogador vencedor sai da frente e vai para o final da própria fila. O programa encerra quando o valor 0 for digitado.
 */

typedef struct No {
    char name[MAX_NAME];
    struct No* next;
} No;

// Ponteiros para início e fim da fila
typedef struct {
    No* start;
    No* end;
} Queues;

// Inicializa fila
void inicializarFila(Queues* q) {
    q->start = NULL;
    q->end = NULL;
}

// Insere no final da fila
void enfileirar(Queues* q, char name[]) {
    No* new = (No*)malloc(sizeof(No));
    strcpy(new->name, name);
    new->next = NULL;
    if (q->end == NULL) {
        q->start = new;
    } else {
        q->end->next = new;
    }
    q->end = new;
}

// Remove do início da fila
char* desenfileirar(Queues* q) {
    if (q->start == NULL) return NULL;
    No* temp = q->start;
    char* name = (char*)malloc(MAX_NAME * sizeof(char));
    strcpy(name, temp->name);
    q->start = q->start->next;
    if (q->start == NULL) q->end = NULL;
    free(temp);
    return name;
}

// Verifica se a fila está vazia
int filaVazia(Queues* q) {
    return q->start == NULL;
}

// Retorna o primeiro da fila
char* frente(Queues* q) {
    if (q->start == NULL) return NULL;
    return q->start->name;
}

int main() {
    Queues time1, time2;
    inicializarFila(&time1);
    inicializarFila(&time2);

    int n1, n2;
    char name[MAX_NAME];

    printf("Quantos jogadores no Time 1? ");
    scanf("%d", &n1);
    getchar();
    for (int i = 0; i < n1; i++) {
        printf("Nome do jogador %d do Time 1: ", i + 1);
        fgets(name, MAX_NAME, stdin);
        name[strcspn(name, "\n")] = '\0';
        enfileirar(&time1, name);
    }

    printf("\nQuantos jogadores no Time 2? ");
    scanf("%d", &n2);
    getchar();
    for (int i = 0; i < n2; i++) {
        printf("Nome do jogador %d do Time 2: ", i + 1);
        fgets(name, MAX_NAME, stdin);
        name[strcspn(name, "\n")] = '\0';
        enfileirar(&time2, name);
    }

    printf("\n--- Início das Partidas ---\n");

    int vencedor;
    while (1) {
        if (filaVazia(&time1) || filaVazia(&time2)) {
            printf("Um dos times ficou sem jogadores! Encerrando...\n");
            break;
        }

        printf("\nFrente do Time 1: %s", frente(&time1));
        printf("\nFrente do Time 2: %s\n", frente(&time2));

        printf("Digite o número do time vencedor (1 ou 2) ou 0 para sair: ");
        scanf("%d", &vencedor);

        if (vencedor == 0) {
            printf("Encerrando o jogo!\n");
            break;
        }

        if (vencedor == 1) {
            char* nameV = desenfileirar(&time1);
            enfileirar(&time1, nameV);
            free(nameV);
        } else if (vencedor == 2) {
            char* nameV = desenfileirar(&time2);
            enfileirar(&time2, nameV);
            free(nameV);
        } else {
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
