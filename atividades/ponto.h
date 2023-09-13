#include <stdio.h>
#include <math.h>

struct Ponto2D {
    float x;
    float y;
};

float calcularDistancia(struct Ponto2D ponto1, struct Ponto2D ponto2) {
    float dx = ponto1.x - ponto2.x;
    float dy = ponto1.y - ponto2.y;
    return sqrt(dx * dx + dy * dy);
}

void testePonto() {
    struct Ponto2D ponto1, ponto2;
    ponto1.x = 1.0;
    ponto1.y = 2.0;
    ponto2.x = 4.0;
    ponto2.y = 6.0;

    printf("Ponto 1: (%.2f, %.2f)\n", ponto1.x, ponto1.y);
    printf("Ponto 2: (%.2f, %.2f)\n", ponto2.x, ponto2.y);
    printf("Distancia entre os pontos: %.2f unidades\n", calcularDistancia(ponto1, ponto2));

}