#include <stdio.h>
 
int main() 
{
    int dias, anos, meses, diasRestantes;

    scanf("%d", &dias); // le a idade da pessoa em dias

    anos = dias / 365; //calculando os anos
    diasRestantes = dias % 365; //pega o resto dos dias que não formam 1 ano

    meses = diasRestantes / 30; // calculando os meses
    diasRestantes = diasRestantes % 30; //resto dos dias que não formam 1 mês

    // Saída: exibir anos, meses e dias
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", diasRestantes);
    return 0;
}
