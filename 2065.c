//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Fila do Supermercado, pedido no torneio Filas e Pilhas

#include <stdio.h>
#include <limits.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);  // Lê o número de funcionários e clientes

    int v[N];  // Array para armazenar o tempo de processamento por item de cada funcionário
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);  // Lê o tempo de processamento por item de cada funcionário
    }

    int c[M];  // Array para armazenar o número de itens de cada cliente
    for (int j = 0; j < M; j++) {
        scanf("%d", &c[j]);  // Lê o número de itens de cada cliente
    }

    int tempoTermino[N];  // Array para armazenar o tempo de término de cada funcionário
    for (int i = 0; i < N; i++) {
        tempoTermino[i] = 0;  // Inicializa todos os tempos de término como 0
    }

    // Atribui cada cliente ao funcionário com o menor tempo de término
    for (int j = 0; j < M; j++) {
        int funcionarioEscolhido = 0;
        int menorTempo = tempoTermino[0];

        // Encontra o funcionário com o menor tempo de término
        for (int i = 1; i < N; i++) {
            if (tempoTermino[i] < menorTempo) {
                menorTempo = tempoTermino[i];
                funcionarioEscolhido = i;
            }
        }

        // Atualiza o tempo de término do funcionário escolhido
        tempoTermino[funcionarioEscolhido] += v[funcionarioEscolhido] * c[j];
    }

    // Encontra o maior tempo de término entre todos os funcionários
    int tempoTotal = 0;
    for (int i = 0; i < N; i++) {
        if (tempoTermino[i] > tempoTotal) {
            tempoTotal = tempoTermino[i];
        }
    }

    // Imprime o tempo total necessário para atender todos os clientes
    printf("%d\n", tempoTotal);

    return 0;  
}
