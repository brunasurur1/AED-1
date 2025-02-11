//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Wrong answer (40%)
//Exercício Beecrowd: Desvio de Rota tentado em 08/02 para estudo

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Número máximo de cidades
#define cidadesmax 250 
// Valor para representar infinito
#define INFINITO INT_MAX  

int N, M, C, K;
int grafo[cidadesmax][cidadesmax];  // Matriz de adjacência do grafo
int custo[cidadesmax];  // Array para armazenar os custos mínimos
int rotaServico[cidadesmax];  // Array para armazenar a rota de serviço

// Função para inicializar o grafo
void inicializarGrafo() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grafo[i][j] = INFINITO;  // Inicializa todas as arestas com custo infinito
        }
        grafo[i][i] = 0;  // Custo de uma cidade para ela mesma é 0
    }
}

// Função para executar o algoritmo de Dijkstra
void dijkstra(int origem) {
    int visitado[cidadesmax] = {0};  // Array para marcar as cidades visitadas

    for (int i = 0; i < N; i++) {
        custo[i] = INFINITO;  // Inicializa os custos como infinito
    }
    custo[origem] = 0;  // Custo da origem para ela mesma é 0

    for (int count = 0; count < N - 1; count++) {
        int u = -1;

        // Encontra a cidade com o menor custo não visitada
        for (int v = 0; v < N; v++) {
            if (!visitado[v] && (u == -1 || custo[v] < custo[u])) {
                u = v;
            }
        }

        if (u == -1) break;  // Se não houver mais cidades para processar, sai do loop

        visitado[u] = 1;  // Marca a cidade como visitada

        // Atualiza os custos das cidades adjacentes
        for (int v = 0; v < N; v++) {
            if (!visitado[v] && grafo[u][v] != INFINITO && custo[u] + grafo[u][v] < custo[v]) {
                custo[v] = custo[u] + grafo[u][v];
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);  

        if (N == 0 && M == 0 && C == 0 && K == 0) {  // Condição de parada
            break;
        }

        inicializarGrafo();  // Inicializa o grafo

        // Lê as estradas e atualiza o grafo
        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);  // Lê U, V e P
            if (grafo[U][V] > P) {  // Atualiza o custo de U para V se for menor
                grafo[U][V] = P;
                grafo[V][U] = P;  // Atualiza o custo de V para U
            }
        }

        // Define a rota de serviço
        for (int i = 0; i < C; i++) {
            rotaServico[i] = i;  // A rota de serviço é 0, 1, ..., C-1
        }

        dijkstra(K);  // Executa o algoritmo de Dijkstra a partir da cidade de conserto

        int custoTotal = INFINITO;

        // Calcula o custo total mínimo
        for (int i = 0; i < C; i++) {
            if (custo[rotaServico[i]] != INFINITO) {
                int custoRota = 0;

                // Calcula o custo da rota de serviço da cidade i até o destino (C-1)
                for (int j = i; j < C - 1; j++) {
                    custoRota += grafo[rotaServico[j]][rotaServico[j + 1]];
                }

                // Atualiza o custo total mínimo
                if (custo[rotaServico[i]] + custoRota < custoTotal) {
                    custoTotal = custo[rotaServico[i]] + custoRota;
                }
            }
        }

        printf("%d\n", custoTotal);  
    }

    return 0;  
}
