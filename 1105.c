//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Sub-prime, feito em 05/02

#include <stdio.h>

int main() {
    int B, N;

    while (1) {
        scanf("%d %d", &B, &N);  // Lê o número de bancos e debêntures

        if (B == 0 && N == 0) {  // Condição de parada
            break;
        }

        int reservas[B + 1];  // Array para armazenar as reservas dos bancos (índices de 1 a B)
        for (int i = 1; i <= B; i++) {
            scanf("%d", &reservas[i]);  // Lê as reservas de cada banco
        }

        // Processa as debêntures
        for (int i = 0; i < N; i++) {
            int D, C, V;
            scanf("%d %d %d", &D, &C, &V);  // Lê a debênture (devedor, credor, valor)

            // Subtrai o valor da debênture do saldo do devedor
            reservas[D] -= V;
            // Adiciona o valor da debênture ao saldo do credor
            reservas[C] += V;
        }

        // Verifica se todos os bancos têm saldo não negativo
        int possivel = 1;  // Assume que é possível liquidar todas as debêntures
        for (int i = 1; i <= B; i++) {
            if (reservas[i] < 0) {  // Se algum banco tem saldo negativo
                possivel = 0;  // Não é possível liquidar todas as debêntures
                break;
            }
        }

        // Imprime o resultado
        if (possivel) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}
