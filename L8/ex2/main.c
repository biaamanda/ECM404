/*
 * Enunciado:
 *    Repita o exerc�cio anterior, mas agora utilize como entrada o arquivo
 *    notas.csv. A quantidade de alunos pode ser diferente de 3.
 *
 * Exemplo de linha:
 *    Rodrigo,1,2,3,4
 *
 *    Note que o separador utilizado � a v�rgula
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

/* Funções */
Student read_student(char line[MAX]);
void print_student(Student s);
float calculate_average(float* grades);

int read_students(Node *list);

Node* create_list();
Node* destroy_list(Node* list);
void insert_at_end(Node *list, Student s);

void print_list(Node* list);

int main () {
    Node* list = create_list();

    int qtd = read_students(list);
    printf("Read %d students.\n", qtd);

    printf("\nLinked list:\n");
    print_list(list);

    list = destroy_list(list);
    return EXIT_SUCCESS;
}

int read_students(Node *list) {
    FILE *f = fopen("grades.csv", "r");
    if (!f) {
        perror("Error opening grades.csv");
        exit(1);
    }

    char line[MAX];
    int count = 0;

    while (fgets(line, MAX, f)) {
        // remove newline
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) continue; // skip empty lines

        Student s = read_student(line);
        insert_at_end(list, s);
        count++;
    }

    fclose(f);
    return count;
}

Student read_student(char input[MAX]) {
    Student s;
    char *token;

    // Name
    token = strtok(input, ",");
    strcpy(s.name, token);

    // Grades
    for (int i = 0; i < 4; i++) {
        token = strtok(NULL, ",");
        if (token != NULL) {
            s.grades[i] = atof(token);
        } else {
            s.grades[i] = 0;
        }
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
    while (aux != NULL) {
        Node *tmp = aux;
        aux = aux->next;
        free(tmp);
    }
    return NULL;
}

void insert_at_end(Node *list, Student s) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->student = s;
    new_node->next = NULL;

    Node *aux = list;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = new_node;
}

void print_student(Student s) {
    printf("(%s | %.2f)", s.name, s.average);
}

void print_list(Node* list) {
    Node *aux = list->next;
    while (aux != NULL) {
        print_student(aux->student);
        if (aux->next != NULL) printf(" -> ");
        aux = aux->next;
    }
    printf("\n");
}