#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Enunciado:
 *
 * Crie uma estrutura com nome e data de nascimento. Leia um vetor com 6 pessoas.
 * Exiba os nomes da pessoa mais nova e da mais velha.
 * A estrutura de data deve ser a do exercício 7.
 */

#define MAX_PEOPLE 6
#define MAX_NAME_LENGTH 50

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  char name[MAX_NAME_LENGTH];
  Date birthDate;
  int birthDateInDays;
} Person;

void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

bool isLeapYear(int year) {
  return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}

int daysInMonth(int month, int year)
{
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month == 2 && isLeapYear(year)) {
    return 29;
  }

  return daysInMonth[month];
}

bool isValidDate(Date date) {
  if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1) {
    return false;
  }

  int maxDays = daysInMonth(date.month, date.year);
  return date.day <= maxDays;
}

int daysSinceEpoch(Date date)
{
  int totalDays = 0;

  for (int year = 1; year < date.year; year++) {
    if (isLeapYear(year)) {
      totalDays += 366;
    }
    else {
      totalDays += 365;
    }
  }

  for (int month = 1; month < date.month; month++) {
    totalDays += daysInMonth(month, date.year);
  }

  totalDays += date.day;

  return totalDays;
}

void findOldestAndYoungest(Person people[], int *oldestIndex, int *youngestIndex)
{
  *oldestIndex = 0;
  *youngestIndex = 0;

  for (int i = 1; i < MAX_PEOPLE; i++) {
    // mais velha tem menor birthDateInDays
    if (people[i].birthDateInDays < people[*oldestIndex].birthDateInDays) {
      *oldestIndex = i;
    }
    if (people[i].birthDateInDays > people[*youngestIndex].birthDateInDays) {
      *youngestIndex = i;
    }
  }
}

int main(int argc, char *argv[])
{
  Person people[MAX_PEOPLE];

  for (int i = 0; i < MAX_PEOPLE; i++) {
    printf("Digite o nome da pessoa %i: ", i + 1);
    scanf("%49s", people[i].name);
    clearInputBuffer();

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%i/%i/%i", &people[i].birthDate.day, &people[i].birthDate.month, &people[i].birthDate.year);
    clearInputBuffer();

    if (!isValidDate(people[i].birthDate)) {
      printf("Data invalida. Tente novamente.\n");
      i--;
      continue;
    }

    people[i].birthDateInDays = daysSinceEpoch(people[i].birthDate);
    printf("\n");
  }

  int oldestIndex, youngestIndex;
  findOldestAndYoungest(people, &oldestIndex, &youngestIndex);

  printf("Pessoa mais velha: %s\n", people[oldestIndex].name);
  printf("Pessoa mais nova: %s\n", people[youngestIndex].name);

  return 0;
}