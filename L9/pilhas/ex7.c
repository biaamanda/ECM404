#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100
/*
 * Exercício 7 - Pilhas
 * Altere o programa anterior para realizar a conversão de um número inteiro positivo para qualquer base (até 36) que o usuário determinar. Para exibição, crie uma string com os caracteres que representam os algarismos de 0 até 9 seguido de A até Z.
 */

typedef struct {
    int top;
    int elements[MAX_ELEMENTS];
} Stack;

void createStack(Stack *p) {
    p->top = -1;
}

int isEmpty(Stack *p) {
    return p->top == -1;
}

void stackUp(Stack *p, int value) {
    if (p->top < MAX_ELEMENTS - 1) {
        p->top++;
        p->elements[p->top] = value;
    } else {
        printf("Erro: Pilha cheia.\n");
    }
}

int unstack(Stack *p) {
    if (!isEmpty(p)) {
        int value = p->elements[p->top];
        p->top--;
        return value;
    } else {
        printf("Erro: Pilha vazia.\n");
        return -1; 
    }
}

void convertBase(int number, int base, Stack *p) {
    if (number == 0) {
        stackUp(p, 0);
        return;
    }

    while (number > 0) {
        int rest = number % base;
        stackUp(p, rest);
        number /= base;
    }
}

void result(Stack *p) {
    char characters[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    printf("Resultado: ");
    while (!isEmpty(p)) {
        int digit = unstack(p);
        printf("%c", characters[digit]);
    }
    printf("\n");
}

int main() {
    int number, base;
    Stack p;
    createStack(&p);

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Erro: Por favor, digite um numero positivo.\n");
        return 1;
    }
    
    printf("Digite a base de conversao (entre 2 e 36): ");
    scanf("%d", &base);

    if (base < 2 || base > 36) {
        printf("Erro: A base deve ser entre 2 e 36.\n");
        return 1;
    }
    
    convertBase(number, base, &p);
    result(&p);

    return 0;
}