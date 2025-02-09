//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Países em Guerra feito em 09/02 para estudo

#include <stdio.h>
#include <limits.h>

#define MAX 501
#define INF INT_MAX

int N, E; // Número de cidades e acordos de envio de mensagens
int dist[MAX][MAX]; // Matriz de distâncias entre as cidades

// Função para inicializar a matriz de distâncias
void initialize() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 0; // Distância de uma cidade para ela mesma é 0
            } else {
                dist[i][j] = INF; // Inicialmente, a distância é infinita
            }
        }
    }
}

// Função para aplicar o algoritmo de Floyd-Warshall
void floydWarshall() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // Se a distância de i para k e de k para j for menor que a distância atual de i para j
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; // Atualiza a distância
                }
            }
        }
    }
}

// Função para identificar cidades no mesmo país e definir distância 0
void identifySameCountry() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // Se houver um caminho de i para j e de j para i, as cidades estão no mesmo país
            if (dist[i][j] != INF && dist[j][i] != INF) {
                dist[i][j] = 0; // Comunicação instantânea
                dist[j][i] = 0; // Comunicação instantânea
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &N, &E); // Lê o número de cidades e acordos de envio de mensagens
        if (N == 0 && E == 0) break; // Se ambos forem 0, termina o programa

        initialize(); // Inicializa a matriz de distâncias

        // Lê os acordos de envio de mensagens
        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H); // Lê os detalhes do acordo
            if (dist[X][Y] > H) {
                dist[X][Y] = H; // Atualiza a distância de X para Y
            }
        }

        identifySameCountry(); // Identifica cidades no mesmo país e define distância 0
        floydWarshall(); // Aplica o algoritmo de Floyd-Warshall para calcular as distâncias mínimas

        int K;
        scanf("%d", &K); // Lê o número de consultas

        // Processa cada consulta
        for (int i = 0; i < K; i++) {
            int O, D;
            scanf("%d %d", &O, &D); // Lê a origem e o destino da consulta

            if (dist[O][D] == INF) {
                printf("Nao e possivel entregar a carta\n"); // Se não houver caminho, imprime a mensagem
            } else {
                printf("%d\n", dist[O][D]); // Caso contrário, imprime a distância mínima
            }
        }

        printf("\n"); // Imprime uma linha em branco após cada caso de teste
    }

    return 0;
}
