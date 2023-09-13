#include <stdio.h>

// Definição de uma estrutura para representar um ponto
struct Ponto {
    float x;
    float y;
};

void testeReta() {
    // Declaração de variáveis para dois pontos
    struct Ponto ponto1, ponto2;

    // Solicita ao usuário que insira as coordenadas do primeiro ponto
    printf("Digite as coordenadas do primeiro ponto (x y): ");
    scanf("%f %f", &ponto1.x, &ponto1.y);

    // Solicita ao usuário que insira as coordenadas do segundo ponto
    printf("Digite as coordenadas do segundo ponto (x y): ");
    scanf("%f %f", &ponto2.x, &ponto2.y);

    // Exibe os pontos que formam a reta
    printf("A reta e composta atraves desses dois pontos: (%.2f,%.2f) e (%.2f, %.2f)\n", ponto1.x, ponto1.y, ponto2.x, ponto2.y);

}