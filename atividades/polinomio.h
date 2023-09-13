#include <stdio.h>

double calcularFuncaoQuadratica(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

void teste_Funcao_segundoGrau() {
    double a, b, c, x;
    printf("Informe os valores de a, b, c e x: ");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &x);

    double resultado = calcularFuncaoQuadratica(a, b, c, x);
    printf("O resultado da funcao de segundo grau e: %.2f\n", resultado);

}