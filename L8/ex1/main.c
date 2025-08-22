/*
 * Enunciado:
 *    Crie uma lista ligada de alunos, em que cada aluno deve consistir de um
 *    struct contendo o seu RA, 4 notas e a m�dia do aluno. O programa
 *    principal deve pedir para que o usu�rio digite o RA e as 4 notas de
 *    3 alunos, para a seguir exibir a lista ligada completa (use exibe_lista).
*
 * Exemplos:
 *
 *    Aluno: Rodrigo 2 3 4 5
 *    Aluno: Alexandre 10 10 8 9
 *    Aluno: Diego 7 8 10 10
 *    (Rodrigo | 3.50) -> (Alexandre | 9.25) -> (Diego | 8.75)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[MAX];
    float grades[4];
    float average;
} Student;

typedef struct Node {
    Student student;
    struct Node* next;
} Node;

Student read_student();
void print_student(Student s);
float calculate_average(float* grades);

Node* create_list();
Node* destroy_list(Node* list);
void insert_at_end(Node* list, Student s);

void print_list(Node* list);
void read_string(char* s);

int main() {
    Node* list = create_list();

    for (int i = 0; i < 3; i++) {
        printf("Enter the name of student %d: ", i+1);
        Student s = read_student();
        insert_at_end(list, s);
    }

    printf("\nLinked list:\n");
    print_list(list);

    list = destroy_list(list);
    return EXIT_SUCCESS;
}

Student read_student() {
    Student s;
    read_string(s.name);
    printf("Enter 4 grades for %s: ", s.name);
    for (int i = 0; i < 4; i++) {
        scanf("%f", &s.grades[i]);
    }
    s.average = calculate_average(s.grades);
    return s;
}

float calculate_average(float* grades) {
    float sum = 0;
    for (int i = 0; i < 4; i++) sum += grades[i];
    return sum / 4.0;
}

Node* create_list() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

Node* destroy_list(Node* list) {
    Node *aux = list;
    while(aux != NULL) {
        Node *tmp = aux;
        aux = aux->next;
        free(tmp);
    }
    return NULL;
}

void insert_at_end(Node* list, Student s) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->student = s;
    new_node->next = NULL;

    Node *aux = list;
    while(aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = new_node;
}

void print_student(Student s) {
    printf("(%s | %.2f)", s.name, s.average);
}

void print_list(Node* list) {
    Node *aux = list->next;
    while(aux != NULL) {
        print_student(aux->student);
        if(aux->next != NULL) printf(" -> ");
        aux = aux->next;
    }
    printf("\n");
}

void read_string(char* s) {
    scanf(" %[^\n]", s);  
}