//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Dama, feito em 04/02

#include <stdio.h>
#include <stdlib.h>  // Para usar a função abs()

int main() {
    int X1, Y1, X2, Y2;

    // Loop controlado para ler os casos de teste
    while (scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2) == 4) {
        // Verifica se todos os valores são zero (condição de parada)
        if (X1 == 0 && Y1 == 0 && X2 == 0 && Y2 == 0) {
            break;  // Sai do loop
        }

        // Verifica se a dama já está na casa de destino
        if (X1 == X2 && Y1 == Y2) {
            printf("0\n");  // Nenhum movimento necessário
        }
        // Verifica se a dama está na mesma linha, coluna ou diagonal
        else if (X1 == X2 || Y1 == Y2 || abs(X1 - X2) == abs(Y1 - Y2)) {
            printf("1\n");  // A dama pode chegar em um único movimento
        }
        // Caso contrário, são necessários dois movimentos
        else {
            printf("2\n");
        }
    }

    return 0;  
}
