
#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 5

// Função para verificar se uma célula está dentro dos limites do labirinto
bool dentroDosLimites(int x, int y) {
    return x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO;
}

// Função para realizar a busca em profundidade (DFS) no labirinto
bool DFS(int labirinto[TAMANHO][TAMANHO], int visitado[TAMANHO][TAMANHO], int x, int y) {
    // Verifica se a célula está dentro dos limites, não foi visitada e não é uma parede
    if (!dentroDosLimites(x, y)) {
        return false;
    }
    if (visitado[x][y] || labirinto[x][y] == 1) {
        return false;
    }

    visitado[x][y] = 1; // Marca a célula como visitada

    // Se chegou ao canto inferior direito, o ladrão escapou
    if (x == TAMANHO - 1 && y == TAMANHO - 1) {
        return true;
    }

    // Visita as células vizinhas
    if (DFS(labirinto, visitado, x + 1, y)) return true;
    if (DFS(labirinto, visitado, x - 1, y)) return true;
    if (DFS(labirinto, visitado, x, y + 1)) return true;
    if (DFS(labirinto, visitado, x, y - 1)) return true;

    return false; // Se não encontrou um caminho, retorna falso
}

int main() {
    int T; // Número de casos de teste
    scanf("%d", &T); // Lê o número de casos de teste

    while (T--) { // Loop para cada caso de teste
        int labirinto[TAMANHO][TAMANHO]; // Matriz para armazenar o labirinto
        int visitado[TAMANHO][TAMANHO] = {0}; // Matriz para marcar as células visitadas

        // Lê o labirinto
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                scanf("%d", &labirinto[i][j]);
            }
        }

        // Realiza a busca em profundidade a partir da célula inicial (0, 0)
        if (DFS(labirinto, visitado, 0, 0)) {
            printf("COPS\n"); 
        } else {
            printf("ROBBERS\n"); 
        }
    }

    return 0;
}
