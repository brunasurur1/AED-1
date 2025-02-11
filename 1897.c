//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Wrong answer (20%)
//Exercício Beecrowd: Jogo Esperto tentado em 07/02 para estudo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 10001  // Tamanho máximo para os números

// Estrutura para armazenar um nó na fila
typedef struct {
    int numero;  // Número atual
    int operacoes;  // Número de operações realizadas até chegar a esse número
} Node;

// Função para realizar a busca em largura (BFS)
int bfs(int N, int M) {
    if (N == M) {
        return 0;  // N já é igual a M, nenhuma operação é necessária
    }

    bool visitado[tam] = {false};  // Array para marcar os números já visitados
    Node fila[tam];  // Fila para armazenar os nós a serem visitados
    int inicio = 0, fim = 0;  // Índices para o início e o fim da fila

    fila[fim].numero = N;  // Adiciona o número inicial à fila
    fila[fim].operacoes = 0;  // Nenhuma operação foi realizada ainda
    fim++;
    visitado[N] = true;  // Marca o número inicial como visitado

    while (inicio < fim) {  // Enquanto a fila não estiver vazia
        Node atual = fila[inicio];  // Pega o nó atual da fila
        inicio++;

        // Aplica todas as operações possíveis
        int resultados[6];
        resultados[0] = atual.numero * 2;  // Operação 1: N * 2
        resultados[1] = atual.numero * 3;  // Operação 2: N * 3
        resultados[2] = atual.numero / 2;  // Operação 3: N / 2
        resultados[3] = atual.numero / 3;  // Operação 4: N / 3
        resultados[4] = atual.numero + 7;  // Operação 5: N + 7
        resultados[5] = atual.numero - 7;  // Operação 6: N - 7

        for (int i = 0; i < 6; i++) {  // Para cada operação
            int proximo = resultados[i];

            // Verifica se o próximo número é válido e não foi visitado
            if (proximo >= 0 && proximo <= 10000 && !visitado[proximo]) {
                if (proximo == M) {  // Se alcançamos M
                    return atual.operacoes + 1;  // Retorna o número de operações
                }

                // Adiciona o próximo número à fila
                fila[fim].numero = proximo;
                fila[fim].operacoes = atual.operacoes + 1;
                fim++;
                visitado[proximo] = true;  // Marca o próximo número como visitado
            }
        }
    }

    return -1;  // Se não for possível converter N em M
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);  

    int resultado = bfs(N, M);  // Executa a busca em largura

    printf("%d\n", resultado); 

    return 0;  
}
