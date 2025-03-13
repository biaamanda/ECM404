#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sum();
void subtract();
void multiply();
void divide();
void squareRoot();
void power();
void sine();
void cosine();
void menu(int menuOption);

void menu(int menuOption) {
  switch (menuOption) {
  case 1:
    sum();
    break;
  case 2:
    subtract();
    break;
  case 3:
    multiply();
    break;
  case 4:
    divide();
    break;
  case 5:
    squareRoot();
    break;
  case 6:
    power();
    break;
  case 7:
    sine();
    break;
  case 8:
    cosine();
    break;
  default:
    printf("Opcao invalida!\n");
    break;
  }
}

void sum() {
  float a,b;

  printf("Soma \n");
  printf("Digite dois valores (a+b): ");
  scanf("%f+%f", &a, &b);

  printf("%.2f + %.2f = %.2f", a,b,a+b);
}

void subtract() {
  float a,b;

  printf("Subtracao \n");
  printf("Digite dois valores (a-b): ");
  scanf("%f-%f", &a, &b);

  printf("%.2f - %.2f = %.2f", a,b,a-b);
}

void multiply() {
  float a,b;

  printf("Multiplicacao \n");
  printf("Digite dois valores (a*b): ");
  scanf("%f*%f", &a, &b);

  printf("%.2f * %.2f = %.2f", a,b,a*b);
}

void divide() {
  float a,b;

  printf("Divisao \n");
  printf("Digite dois valores (a/b): ");
  scanf("%f/%f", &a, &b);

  printf("%.2f / %.2f = %.2f", a,b,a/b);
}
  
void squareRoot() {
  float x,n;

  printf("Raiz \n");
  printf("Digite dois valores (x r n): ");
  scanf("%f r %f", &x, &n);

  printf("%.2f r %.2f = %.2f", x, n, pow(x, 1/n));
}

void power() {
  float x,n;

  printf("X elevado a N \n");
  printf("Digite dois valores (x^n): ");
  scanf("%f^%f", &x, &n);

  printf("%.2f ^ %.2f = %.2f", x, n, pow(x, n));
}

void sine() {
  float angle;

  printf("Seno \n");
  printf("Digite um valor em graus: ");
  scanf("%f", &angle);

  printf("seno(%.2f) = %.2f", angle, sin(angle * M_PI / 180));
}

void cosine() {
  float angle;

  printf("Cosseno \n");
  printf("Digite um valor em graus: ");
  scanf("%f", &angle);

  printf("cosseno(%.2f) = %.2f", angle, cos(angle * M_PI / 180));
}

int main() {
  int option;

  do {
    printf("\n\n");
    printf("\n*** Calculadora ***\n");
    printf("Selecione uma das opcoes abaixo:\n");
    printf("1 - Soma\n");
    printf("2 - Subtracao\n");
    printf("3 - Multiplicacao\n");
    printf("4 - Divisao\n");
    printf("5 - Raiz n\n");
    printf("6 - X elevado a n\n");
    printf("7 - Seno\n");
    printf("8 - Cosseno\n");
    printf("-1 - Sair\n");

    scanf("%i", &option);

    if (option != -1) {
      menu(option);
    }

  } while (option != -1);

  printf("Programa encerrado.\n");
  return 0;
}
