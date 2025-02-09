//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Ir e Vir feito em 09/02 para estudo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 2000  // Define o número máximo de intersecções (nós) no grafo

int N, M;  // Número de intersecções e ruas
int grafo[max][max];  // Matriz de adjacência para o grafo original
int grafoTransposto[max][max];  // Matriz de adjacência para o grafo transposto
int visitado[max];  // Array para marcar nós visitados durante a DFS
int ordem[max];  // Array para armazenar a ordem de término dos nós na primeira DFS
int tempo;  // Variável para controlar o tempo de término na DFS

// Função para realizar a DFS no grafo original
void dfs(int u) {
    visitado[u] = 1;  // Marca o nó atual como visitado
    for (int v = 0; v < N; v++) {  // Percorre todos os nós adjacentes
        if (grafo[u][v] && !visitado[v]) {  // Se houver uma aresta e o nó não foi visitado
            dfs(v);  // Realiza a DFS no nó adjacente
        }
    }
    ordem[tempo++] = u;  // Armazena o nó na ordem de término
}

// Função para realizar a DFS no grafo transposto
void dfsTransposto(int u) {
    visitado[u] = 1;  // Marca o nó atual como visitado
    for (int v = 0; v < N; v++) {  // Percorre todos os nós adjacentes
        if (grafoTransposto[u][v] && !visitado[v]) {  // Se houver uma aresta e o nó não foi visitado
            dfsTransposto(v);  // Realiza a DFS no nó adjacente
        }
    }
}

// Função para verificar se o grafo é fortemente conexo
int ehFortementeConexo() {
    tempo = 0;  // Inicializa o tempo de término
    memset(visitado, 0, sizeof(visitado));  // Inicializa o array de visitados com 0

    // Primeira DFS para determinar a ordem de término
    for (int i = 0; i < N; i++) {  // Percorre todos os nós
        if (!visitado[i]) {  // Se o nó não foi visitado
            dfs(i);  // Realiza a DFS a partir desse nó
        }
    }

    // Inverte o grafo
    for (int i = 0; i < N; i++) {  // Percorre todas as linhas da matriz
        for (int j = 0; j < N; j++) {  // Percorre todas as colunas da matriz
            grafoTransposto[j][i] = grafo[i][j];  // Transpõe a matriz de adjacência
        }
    }

    memset(visitado, 0, sizeof(visitado));  // Reinicializa o array de visitados
    int componentes = 0;  // Contador de componentes fortemente conexos

    // Segunda DFS no grafo transposto na ordem inversa
    for (int i = N - 1; i >= 0; i--) {  // Percorre a ordem de término em ordem inversa
        int u = ordem[i];  // Obtém o nó na ordem de término
        if (!visitado[u]) {  // Se o nó não foi visitado
            dfsTransposto(u);  // Realiza a DFS no grafo transposto
            componentes++;  // Incrementa o contador de componentes
        }
    }

    return componentes == 1;  // Retorna 1 se houver apenas um componente fortemente conexo
}

int main() {
    while (1) {  // Loop para processar múltiplos casos de teste
        scanf("%d %d", &N, &M);  // Lê o número de intersecções e ruas
        if (N == 0 && M == 0) {  // Condição de parada
            break;
        }

        memset(grafo, 0, sizeof(grafo));  // Inicializa a matriz de adjacência do grafo original
        memset(grafoTransposto, 0, sizeof(grafoTransposto));  // Inicializa a matriz de adjacência do grafo transposto

        for (int i = 0; i < M; i++) {  // Lê as descrições das ruas
            int V, W, P;
            scanf("%d %d %d", &V, &W, &P);  // Lê a descrição da rua
            V--; W--;  // Ajusta para índices baseados em 0
            grafo[V][W] = 1;  // Adiciona a aresta no grafo original
            if (P == 2) {  // Se a rua for de mão dupla
                grafo[W][V] = 1;  // Adiciona a aresta inversa no grafo original
            }
        }

        if (ehFortementeConexo()) {  // Verifica se o grafo é fortemente conexo
            printf("1\n");  // Imprime 1 se for fortemente conexo
        } else {
            printf("0\n");  // Imprime 0 se não for fortemente conexo
        }
    }

    return 0;  
}
