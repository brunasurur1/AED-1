//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Borboletas feito em 11/02 para estudo

#include <stdio.h>
#include <stdlib.h>

#define MAX 200

int main() {
    int N; // Tamanho da matriz (N x N)
    scanf("%d", &N); // Lê o tamanho da matriz

    int floresta[MAX][MAX]; // Matriz para armazenar a floresta
    int especies[1001] = {0}; // Array para contar as espécies de borboletas

    // Lê a matriz da floresta
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &floresta[i][j]);
        }
    }

    int capturas = 2 * N; // Número de capturas (2N)
    int especiesDistintas = 0; // Contador de espécies distintas

    // Realiza as capturas
    for (int i = 0; i < capturas; i++) {
        int x, y; // Coordenadas da captura
        scanf("%d %d", &x, &y); // Lê as coordenadas
        x--; y--; // Ajusta para índices baseados em 0

        int especie = floresta[x][y]; // Obtém a espécie da borboleta capturada
        if (especies[especie] == 0) { // Se a espécie ainda não foi capturada
            especiesDistintas++; // Incrementa o contador de espécies distintas
        }
        especies[especie]++; // Marca a espécie como capturada
    }

    // Imprime o número de espécies distintas capturadas
    printf("%d\n", especiesDistintas);

    return 0;
}
