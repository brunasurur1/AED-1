//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Ones feito em 11/02 para estudo

#include <stdio.h>

int main() {
    int n; // Número de entrada
    while (scanf("%d", &n) != EOF) { // Lê o número de entrada até o final do arquivo (EOF)
        int count = 1; // Contador para o número de dígitos '1'
        int resto = 1 % n; // Resto inicial

        // Loop para encontrar o menor número composto apenas por '1's que é múltiplo de n
        while (resto != 0) {
            resto = (resto * 10 + 1) % n; // Atualiza o resto
            count++; // Incrementa o contador de dígitos
        }

        // Imprime o número de dígitos '1' necessários
        printf("%d\n", count);
    }

    return 0;
}
