#include <stdio.h>

int main() {
    int M, N;

    while (1) {  // Loop infinito para ler os pares de valores
        scanf("%d %d", &M, &N);  // Lê os valores de M e N

        // Verifica se algum dos valores é menor ou igual a zero
        if (M <= 0 || N <= 0) {
            break;  // Sai do loop se a condição for atendida
        }

        // Determina o menor e o maior valor entre M e N
        int menor = (M < N) ? M : N;
        int maior = (M > N) ? M : N;

        int soma = 0;  // Variável para armazenar a soma dos números

        // Loop para imprimir a sequência e calcular a soma
        for (int i = menor; i <= maior; i++) {
            printf("%d ", i);  // Imprime o número atual
            soma += i;  // Adiciona o número à soma
        }

        printf("Sum=%d\n", soma);  // Imprime a soma dos números
    }

    return 0;  // Retorna 0 indicando que o programa terminou com sucesso
}
