#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
 * Exercício 8 - Filas
 * Faça a entrada de dados de duas filas, de tamanhos definidos pelo usuário. Para cada uma utilize a função InserirNaLista. Depois, faça uma função que recebe as duas filas e retorna uma fila com os elementos das duas intercalados conforme a ordem. Quando os valores da fila menor não existirem mais, incluir somente os valores da outra fila.
 */

 typedef struct{
    int items[MAX];
    int front, back;
 }Queue;
 
 void boot(Queue *q){
    q-> front = 0;
    q-> back = -1;
 }

 int empty(Queue *q){
    return q->front > q->back;
 }

 int full(Queue *q){
    return q->back == MAX -1;
 }

 void enqueue(Queue *q, int value){
    if(!full(q)){
        q->items[++q->back] = value;
    }
 }

 int dequeue(Queue *q){
    if(!empty(q)){
        return q->items[q->front++];
    }
    return -1;
 }

 void display(Queue q){
    for(int i = q.front; i <= q.back; i++) {
        printf("%d", q.items[i]);
    }
    printf("\n");
 }

 Queue intercalete (Queue q1, Queue q2) {
    Queue q3;
    boot(&q3);

    while(!empty(&q1) && !empty(&q2)){
        enqueue(&q3, dequeue(&q1));
        enqueue(&q3, dequeue(&q2));
    }

    while(!empty(&q1)) {
        enqueue(&q3, dequeue(&q1));
    }

    while(!empty(&q2)) {
        enqueue(&q3, dequeue(&q2));
    }
    return q3;
 }

int main() {
    Queue q1, q2, q3;
    int n1, n2, value;

    boot(&q1);
    boot(&q2);

    printf("Digite o tamanho da fila 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Fila1[%d]: ", i);
        scanf("%d", &value);
        enqueue(&q1, value);
    }

    printf("Digite o tamanho da fila 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Fila2[%d]: ", i);
        scanf("%d", &value);
        enqueue(&q2, value);
    }

    q3 = intercalete(q1, q2);

    printf("\nFila resultante (intercalada): ");
    exibir(q3);

    return 0;
}
