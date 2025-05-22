#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Enunciado:
 *
 * Crie uma estrutura Retângulo com dois pontos: superior esquerdo e inferior direito.
 * Cada ponto tem X e Y. Leia um retângulo e calcule a área, perímetro e a diagonal.
 */

typedef struct {
  float coordx;
  float coordy;
} Point;

float calculateArea(Point p1, Point p2) {
  return fabs((p2.coordx - p1.coordx)*(p2.coordy - p1.coordx));
}

float calculatePerimeter(Point p1, Point p2) {
  return 2 * (fabs(p2.coordx - p1.coordx) + fabs(p2.coordy - p1.coordx));
}

float calculateDiagonal(Point p1, Point p2) {
  return sqrt(pow(p2.coordx - p1.coordx, 2) + pow(p2.coordy - p1.coordy, 2));
}


int main(int argc, char *argv[])
{
  Point point[2];

  printf("Digite as coordenadas do ponto superior esquerdo: ");
  scanf("%f %f", &point[0].coordx, &point[0].coordy);

  printf("Digite as coordenadas do ponto inferior direito: ");
  scanf("%f %f", &point[1].coordx, &point[1].coordy);

  printf("Area: %.2f\n", calculateArea(point[0], point[1]));
  printf("Perimetro: %.2f\n", calculatePerimeter(point[0], point[1]));
  printf("Diagonal: %.2f\n", calculateDiagonal(point[0], point[1]));

  return 0;
}
