#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma aresta em um grafo
typedef struct {
    int inicio, fim, custo;
} Conexao;

// Função de comparação usada para ordenar conexões pelo custo
int comparar(const void* a, const void* b) {
    Conexao* conexaoA = (Conexao*)a;
    Conexao* conexaoB = (Conexao*)b;
    return conexaoA->custo - conexaoB->custo;
}

// Funções auxiliares para o algoritmo de união e busca (Union-Find)
int encontrar(int* conjunto, int elemento) {
    if (conjunto[elemento] != elemento) {
        conjunto[elemento] = encontrar(conjunto, conjunto[elemento]); // Compressão do caminho
    }
    return conjunto[elemento];
}

void unir(int* conjunto, int* nivel, int elemento1, int elemento2) {
    int raiz1 = encontrar(conjunto, elemento1);
    int raiz2 = encontrar(conjunto, elemento2);

    if (raiz1 != raiz2) {
        if (nivel[raiz1] > nivel[raiz2]) {
            conjunto[raiz2] = raiz1;
        } else if (nivel[raiz1] < nivel[raiz2]) {
            conjunto[raiz1] = raiz2;
        } else {
            conjunto[raiz2] = raiz1;
            nivel[raiz1]++;
        }
    }
}

int main() {
    while (1) {
        int m, n;
        scanf("%d %d", &m, &n);

        if (m == 0 && n == 0) {
            break;
        }

        Conexao* conexoes = (Conexao*)malloc(n * sizeof(Conexao));
        int custoOriginal = 0;

        // Leitura das conexões do grafo
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &conexoes[i].inicio, &conexoes[i].fim, &conexoes[i].custo);
            custoOriginal += conexoes[i].custo;
        }

        // Ordena as conexões pelo custo usando qsort
        qsort(conexoes, n, sizeof(Conexao), comparar);

        // Inicializa estruturas para o algoritmo de Kruskal
        int* conjunto = (int*)malloc(m * sizeof(int));
        int* nivel = (int*)calloc(m, sizeof(int));
        for (int i = 0; i < m; i++) {
            conjunto[i] = i;
        }

        int custoMST = 0;
        // Construção da árvore geradora mínima (MST)
        for (int i = 0; i < n; i++) {
            int inicio = conexoes[i].inicio;
            int fim = conexoes[i].fim;

            if (encontrar(conjunto, inicio) != encontrar(conjunto, fim)) {
                unir(conjunto, nivel, inicio, fim);
                custoMST += conexoes[i].custo;
            }
        }

        // Exibe o custo economizado
        printf("%d\n", custoOriginal - custoMST);

        free(conexoes);
        free(conjunto);
        free(nivel);
    }

    return 0;
}
