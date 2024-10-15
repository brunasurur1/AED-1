//Bruna Surur Bergara, RA: 165536
//Exercício área do triângulo do Exemplo de Torneio para entrega no dia 15/10

#include <stdio.h>
#include <math.h> //Necessária para função pow
 
int main() 
{
    const double n = 3.14159; //uso do const pra indicar que é uma variável constante
    double raio, area; //variável de dupla precisão - double
    scanf("%lf",&raio); //recebe o valor do raio
    area = n * pow(raio,2); //uso da função pow para fazer raio elevado à 2
    printf("A=%.4lf\n", area); 

 
    return 0;
}
