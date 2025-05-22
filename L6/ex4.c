#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Enunciado:
 *
 * Crie uma estrutura para representar as coordenadas de um ponto (X, Y).
 * Leia dois pontos do teclado e exiba a distância entre eles.
 */

typedef struct {
  float coordx;
  float coordy;
} Coordinate;

Coordinate readPoint();

float calculateDistance(Coordinate c1, Coordinate c2);

Coordinate readCoordinate() {
    Coordinate c;
    scanf("%f, %f", &c.coordx, &c.coordy);
    return c;
}

float calculateDistance(Coordinate c1, Coordinate c2) {
    float dx = c2.coordx - c1.coordx;
    float dy = c2.coordy - c1.coordy;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Coordinate c1, c2;

    printf("Digite o primeiro ponto: ");
    c1 = readCoordinate();

    printf("Digite o segundo ponto: ");
    c2 = readCoordinate();

    float distance = calculateDistance(c1, c2);

    printf("Distancia: %.2f\n", distance);

    return 0;
}