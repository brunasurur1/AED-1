//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Flores Coloridas feito em 10/02 para estudo

#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

// Função para calcular a área do triângulo usando a fórmula de Heron
double calcularAreaTriangulo(double a, double b, double c) {
    double s = (a + b + c) / 2.0; // Semiperímetro
    return sqrt(s * (s - a) * (s - b) * (s - c)); // Fórmula de Heron
}

// Função para calcular o raio do círculo inscrito no triângulo
double calcularRaioInscrito(double area, double s) {
    return area / s;
}

// Função para calcular o raio do círculo circunscrito ao triângulo
double calcularRaioCircunscrito(double a, double b, double c, double area) {
    return (a * b * c) / (4.0 * area);
}

int main() {
    double a, b, c; // Variáveis para armazenar os lados do triângulo
    
    // Laço para processar múltiplos casos de teste
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double areaTriangulo = calcularAreaTriangulo(a, b, c); // Calcula a área do triângulo
        double s = (a + b + c) / 2.0; // Calcula o semiperímetro
        
        double raioInscrito = calcularRaioInscrito(areaTriangulo, s); // Raio do círculo inscrito
        double areaCirculoInscrito = PI * raioInscrito * raioInscrito; // Área do círculo inscrito

        double raioCircunscrito = calcularRaioCircunscrito(a, b, c, areaTriangulo); // Raio do círculo circunscrito
        double areaCirculoCircunscrito = PI * raioCircunscrito * raioCircunscrito; // Área do círculo circunscrito

        // Área das flores amarelas (fora do triângulo, dentro do círculo circunscrito)
        double areaFloresAmarelas = areaCirculoCircunscrito - areaTriangulo;

        // Área das flores violetas (área do triângulo sem o círculo inscrito)
        double areaFloresVioletas = areaTriangulo - areaCirculoInscrito;

        // Exibição do resultado com 4 casas decimais
        printf("%.4lf %.4lf %.4lf\n", areaFloresAmarelas, areaFloresVioletas, areaCirculoInscrito);
    }

    return 0;
}
