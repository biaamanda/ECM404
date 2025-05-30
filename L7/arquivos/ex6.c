#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Exercício 6 - Arquivos
 * Crie um programa que receba como entrada o número de alunos de uma disciplina. 
 * Aloque dinamicamente dois vetores para armazenar as informações a respeito desses alunos. 
 * O primeiro vetor contém o nome dos alunos e o segundo contém suas notas finais. 
 * Crie um arquivo que armazene, a cada linha, o nome do aluno e sua nota final. 
 * Use nomes com no máximo 40 caracteres. 
 * Se o nome não contém 40 caracteres, complete com espaço em branco.
 */

 #define MAX_NAME_LEN 40

int main() {
    int numberStudents;
    char **studentsNames;
    float *grades;
    FILE *file;

    printf("Digite o numero de alunos: ");
    scanf("%d", &numberStudents);
    getchar();

    studentsNames = (char **)malloc(numberStudents * sizeof(char *));
    grades = (float *)malloc(numberStudents * sizeof(float));

    for (int i = 0; i < numberStudents; i++) {
        studentsNames[i] = (char *)malloc((MAX_NAME_LEN + 1) * sizeof(char));
        if (studentsNames[i] == NULL) {
            printf("Erro ao alocar memória para o nome.\n");
            return 1;
        }

        printf("Nome do aluno %d: \n", i + 1);
        fgets(studentsNames[i], MAX_NAME_LEN + 1, stdin);
        studentsNames[i][strcspn(studentsNames[i], "\n")] = '\0'; // Remover \n


        int len = strlen(studentsNames[i]);
        for (int j = len; j < MAX_NAME_LEN; j++) {
            studentsNames[i][j] = ' ';
        }
        studentsNames[i][MAX_NAME_LEN] = '\0';

        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &grades[i]);
        getchar(); // Consumir o \n após a nota
    }

    file = fopen("alunos_notas.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < numberStudents; i++) {
        fprintf(file, "%-40s %.2f\n", studentsNames[i], grades[i]);
    }

    fclose(file);
    for (int i = 0; i < numberStudents; i++) {
        free(studentsNames[i]);
    }
    free(studentsNames);
    free(grades);

    printf("Dados salvos em 'alunos_notas.txt'.\n");

    return 0;
}
