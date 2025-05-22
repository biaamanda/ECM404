#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Enunciado:
 *
 * Escreva um programa com uma estrutura representando uma data (dia, mês, ano).
 * Leia duas datas e exiba o número de dias decorridos entre elas.
 * Considere anos bissextos (fevereiro até o dia 29).
 */

typedef struct {
  int day;
  int month;
  int year;
} Date;

bool isLeapYear(int year)
{
  //se for ano bisexto ha existência de um resto na divisão do ano por 4

  return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
}

int getDaysInMonth(int month, int year)
{
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month == 2 && isLeapYear(year)) {
    return 29;
  }

  return daysInMonth[month];
}

int daysSinceEpoch(Date d) {
  int totalDays = 0;

  for (int year = 1; year < d.year; year++) {
    if (isLeapYear(year)) {
      totalDays += 366;
    }
    else{
      totalDays += 365;
    }
  }

  for (int month = 1; month < d.month; month++) {
    totalDays += getDaysInMonth(month, d.year);
  }

  totalDays += d.day;

  return totalDays;
}

int distanceBetweenDatesInDays(Date date1, Date date2)
{
  int days1 = daysSinceEpoch(date1);
  int days2 = daysSinceEpoch(date2);

  return abs(days2 - days1);
}

bool isValidDate(Date date) {
  if (date.year < 1 || date.month < 1 || date.month > 12 || date.day < 1) {
    return false;
  }

  int maxDays = getDaysInMonth(date.month, date.year);
  return date.day <= maxDays;
}

int main(int argc, char *argv[])
{
  Date date1, date2;

  printf("Digite a primeira data (dd/mm/yyyy): ");
  scanf("%i/%i/%i", &date1.day, &date1.month, &date1.year);

  if (!isValidDate(date1)) {
    printf("Primeira data inválida!\n");
    return 1;
  }

  printf("Digite a segunda data (dd/mm/yyyy): ");
  scanf("%i/%i/%i", &date2.day, &date2.month, &date2.year);

  if (!isValidDate(date2)) {
    printf("Segunda data inválida!\n");
    return 1;
  }

  int daysDifference = distanceBetweenDatesInDays(date1, date2);

  printf("Número de dias entre as datas: %d\n", daysDifference);

  return 0;
}