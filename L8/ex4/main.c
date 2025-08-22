/*
 * Enunciado:
 *    Repita o exerc�cio 2, mas agora o seu programa deve implementar um
 *    algoritmo de ordena��o para ordenar e exibir a lista de alunos em ordem
 *    crescente de m�dia.
 *
 *
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

void ordena_lista(TLista* alunos);
void troca_alunos(Aluno* a, Aluno* b);

void exibe_lista(TLista* alunos);
void ler_string(char* s);

int main (int argc, char *argv[]) {
  TLista* lista = cria_lista();

  if(ler_alunos(lista)) {
    printf("Lista original:\n");
    exibe_lista(lista);

    ordena_lista(lista);

    printf("\nLista ordenada por média:\n");
    exibe_lista(lista);
  }

  destroi_lista(lista);
  return EXIT_SUCCESS;
}

void troca_alunos(Aluno *a, Aluno *b) {
  Aluno temp = *a;
  *a = *b;
  *b = temp;
}

void ordena_lista(TLista* alunos) {
  if(!alunos || !alunos->prox) return;

  int trocou;
  do {
    trocou = 0;
    TLista* atual = alunos->prox;
    while(atual && atual->prox) {
      if(atual->aluno.media > atual->prox->aluno.media) {
        troca_alunos(&atual->aluno, &atual->prox->aluno);
        trocou = 1;
      }
      atual = atual->prox;
    }
  } while(trocou);
}

int ler_alunos(TLista *alunos) {
  FILE *f = fopen("notas.csv", "r");
  if(!f) {
    printf("Erro ao abrir arquivo!\n");
    return 0;
  }

  char linha[MAX];
  while(fgets(linha, MAX, f)) {
    linha[strcspn(linha, "\n")] = '\0';
    Aluno a = ler_aluno(linha);
    insere_no_fim(alunos, a);
  }

  fclose(f);
  return 1;
}

void insere_no_fim(TLista *alunos, Aluno aluno) {
  TLista* novo = (TLista*) malloc(sizeof(TLista));
  novo->aluno = aluno;
  novo->prox = NULL;

  TLista* aux = alunos;
  while(aux->prox != NULL)
    aux = aux->prox;

  aux->prox = novo;
}

TLista* cria_lista() {
  TLista* l = (TLista*) malloc(sizeof(TLista));
  l->prox = NULL;
  return l;
}

TLista* destroi_lista(TLista* alunos) {
  TLista* atual = alunos;
  while(atual) {
    TLista* prox = atual->prox;
    free(atual);
    atual = prox;
  }
  return NULL;
}

float calcula_media(float* notas) {
  float soma = 0;
  for(int i = 0; i < 4; i++) soma += notas[i];
  return soma / 4.0;
}

Aluno ler_aluno(char entrada[MAX]) {
  Aluno a;
  char *token = strtok(entrada, ",");
  strcpy(a.nome, token);

  for(int i = 0; i < 4; i++) {
    token = strtok(NULL, ",");
    a.notas[i] = atof(token);
  }

  a.media = calcula_media(a.notas);
  return a;
}

void exibe_aluno(Aluno a) {
  printf("(%s | %.2f)", a.nome, a.media);
}

void exibe_lista(TLista* alunos) {
  TLista *aux = alunos->prox;
  while(aux != NULL) {
    exibe_aluno(aux->aluno);
    if( aux->prox != NULL ) printf(" -> ");
    aux = aux->prox;
  }
  printf("\n");
}

void ler_string(char* s) {
  scanf("\n");
  fgets(s, MAX, stdin);
  size_t tam = strlen(s);
  if( s[tam-1] == '\n' ) s[tam-1] = '\0';
}
