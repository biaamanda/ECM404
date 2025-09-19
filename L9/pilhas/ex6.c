#include <stdio.h>
#include <stdlib.h>

#define MAX 8

/*
 * Exercício 6 - Pilhas
 * Elabore um programa que, dado um valor inteiro entre 0 e 255, apresente sua representação binária (com 8 algarismos) utilizando uma pilha.
Passos:
 a) armazenar na pilha o resto das divisões sucessivas enquanto o numerador seja maior que 1;
 b) armazenar na pilha o último valor do numerador;
 c) armazenar na pilha valores zero, enquanto a pilha tiver menos do que 8 itens;
 d) retirar e exibir os valores da pilha, enquanto existirem.
 */
typedef struct {
    int top;
    int items[MAX];
}Stack;

void boot(Stack *s){
    s->top = -1;
}

int full(Stack *s) {
    return s->top == MAX - 1;
}

int empty{
    return p->top == -1;
}

void push {
    if(!full(s)){
        return p->items[++s->top] = value;
    }
}

int pop{
    if(!empty(s)){
        return p->items[p->top--1];
    }
    return -1;
}


int main(){
    int num;

    Stack s;
    boot(&s);

    printf(Digite um numero entre 0 e 255: );
    scanf("%d", &number);

    int temp = number;
    while (temp > 1){
        push(&s, temp % 2);
        temp /= 2;
    }

    push(&s, temp);

    while(!full(&s)){
        push(&s, 0);
    }

    printf("Representacao binaria: ", number)

    while(!empty(&s)){
        printf("%d", pop(&s));
    }
    return 0;
}