#include <stdio.h>
#include <stdlib.h>

/* Enunciado:
 *
 * Usando a estrutura Retângulo (do exercício 5) e Ponto (do exercício 4), leia um
 * retângulo e um ponto. Informe se o ponto está dentro do retângulo.
 */

typedef struct
{
  float coordX;
  float coordY;
} Point;

typedef struct
{
  Point upperLeft;
  Point lowerRight;
} Rectangle;

int isPointInsideRectangle(Point point, Rectangle rect)
{
  int isBoundedInX = point.coordX >= rect.upperLeft.coordX && point.coordX <= rect.lowerRight.coordX;
  int isBoundedInY = point.coordY <= rect.upperLeft.coordY && point.coordY >= rect.lowerRight.coordY;

  return isBoundedInX && isBoundedInY;
}

int main(int argc, char *argv[])
{
  Rectangle rect;
  Point point;

  printf("Digite as coordenadas do ponto superior esquerdo do retangulo (x y): ");
  scanf("%f %f", &rect.upperLeft.coordX, &rect.upperLeft.coordY);

  printf("Digite as coordenadas do ponto inferior direito do retangulo (x y): ");
  scanf("%f %f", &rect.lowerRight.coordX, &rect.lowerRight.coordY);

  printf("Digite as coordenadas do ponto (x y): ");
  scanf("%f %f", &rect.lowerRight.coordX, &rect.lowerRight.coordY);

  printf("O ponto %s dentro do retangulo.\n",
         isPointInsideRectangle(point, rect) ? "esta" : "nao esta");

  return 0;
}
