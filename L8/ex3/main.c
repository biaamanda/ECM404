/*
 * Enunciado:
 *    Repita o exerc�cio anterior, mas agora o programa principal deve pedir
 *    ao usu�rio que digite um nome para ser buscado na lista de alunos.
 *    O programa deve implementar um algoritmo de busca na lista ligada para
 *    encontrar e exibir o aluno com o nome informado. Caso o aluno n�o seja
 *    encontrado, o usu�rio deve ser alertado.
 *
 * Exemplos:
 *
 *    Digite o aluno a ser buscado: Rodrigo
 *    Aluno encontrado: (Rodrigo | 2.50)
 *
 *    Digite o aluno a ser buscado: Alexandre
 *    Aluno encontrado: (Alexandre | 9.25)
 *
 *    Digite o aluno a ser buscado: Oi
 *    O aluno n�o foi encontrado...
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[MAX];
    float notas[4];
    float media;
} Aluno;

typedef struct SLista {
    Aluno aluno;
    struct SLista* prox;
} TLista;

Aluno ler_aluno(char linha[MAX]);
void exibe_aluno(Aluno a);
float calcula_media(float* notas);

int ler_alunos(TLista* alunos);

TLista* cria_lista();
TLista* destroi_lista(TLista* alunos);
void insere_no_fim(TLista *alunos, Aluno aluno);

int busca_aluno(TLista* alunos, char aluno[MAX]);

/* Funções extras */
void exibe_lista(TLista* alunos);
void ler_string(char* s);

int main (int argc, char *argv[]) {
    TLista* lista = cria_lista();

    int qtd = ler_alunos(lista);
    printf("Foram lidos %d alunos.\n", qtd);

    printf("\nLista ligada:\n");
    exibe_lista(lista);

    char nome_busca[MAX];
    printf("\nDigite o aluno a ser buscado: ");
    ler_string(nome_busca);

    if (!busca_aluno(lista, nome_busca)) {
        printf("O aluno nao foi encontrado...\n");
    }

    lista = destroi_lista(lista);
    return EXIT_SUCCESS;
}

int busca_aluno(TLista* alunos, char aluno[MAX]) {
    TLista *aux = alunos->prox;
    while (aux != NULL) {
        if (strcmp(aux->aluno.nome, aluno) == 0) {
            printf("Aluno encontrado: ");
            exibe_aluno(aux->aluno);
            printf("\n");
            return 1; 
        }
        aux = aux->prox;
    }
    return 0; 
}

int ler_alunos(TLista *alunos) {
    FILE *f = fopen("notas.csv", "r");
    if (!f) {
        perror("Erro ao abrir notas.csv");
        exit(1);
    }

    char linha[MAX];
    int count = 0;

    while (fgets(linha, MAX, f)) {
        linha[strcspn(linha, "\n")] = '\0'; 
        if (strlen(linha) == 0) continue;

        Aluno a = ler_aluno(linha);
        insere_no_fim(alunos, a);
        count++;
    }

    fclose(f);
    return count;
}

Aluno ler_aluno(char entrada[MAX]) {
    Aluno a;
    char *token;

    token = strtok(entrada, ",");
    strcpy(a.nome, token);

    for (int i = 0; i < 4; i++) {
        token = strtok(NULL, ",");
        if (token != NULL) {
            a.notas[i] = atof(token);
        } else {
            a.notas[i] = 0;
        }
    }

    a.media = calcula_media(a.notas);
    return a;
}

float calcula_media(float* notas) {
    float soma = 0;
    for (int i = 0; i < 4; i++) soma += notas[i];
    return soma / 4.0;
}

TLista* cria_lista() {
    TLista* cabeca = (TLista*) malloc(sizeof(TLista));
    cabeca->prox = NULL;
    return cabeca;
}

TLista* destroi_lista(TLista* alunos) {
    TLista *aux = alunos;
    while (aux != NULL) {
        TLista *tmp = aux;
        aux = aux->prox;
        free(tmp);
    }
    return NULL;
}

void insere_no_fim(TLista *alunos, Aluno aluno) {
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->aluno = aluno;
    novo->prox = NULL;

    TLista *aux = alunos;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
}

void exibe_aluno(Aluno a) {
    printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista* alunos) {
    TLista *aux = alunos->prox;
    while (aux != NULL) {
        exibe_aluno(aux->aluno);
        if (aux->prox != NULL) printf(" -> ");
        aux = aux->prox;
    }
    printf("\n");
}

void ler_string(char* s) {
    scanf(" %[^\n]", s);
}
