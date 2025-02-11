//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Wrong answer (5%)
//Exercício Beecrowd: Controlador de Vôo tentado em 09/02 para estudo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM 1000 // Tamanho máximo para os aviões por fila

// Estrutura para representar uma fila
typedef struct {
    char avioes[MAX_TAM][10]; // Array de strings para armazenar os aviões
    int frente, tras; // Índices para a frente e o final da fila
} Fila;

// Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
}

// Verifica se a fila está vazia
int filaVazia(Fila *fila) {
    return fila->frente > fila->tras;
}

// Enfileira um avião na fila
void enfileirar(Fila *fila, char *aviao) {
    if (fila->tras < MAX_TAM - 1) {
        strcpy(fila->avioes[++(fila->tras)], aviao);
    }
}

// Desenfileira um avião da fila
char* desenfileirar(Fila *fila) {
    if (filaVazia(fila)) {
        return NULL;
    }
    return fila->avioes[(fila->frente)++];
}

int main() {
    Fila oeste, norte, sul, leste;
    inicializarFila(&oeste);
    inicializarFila(&norte);
    inicializarFila(&sul);
    inicializarFila(&leste);

    int pontoCardeal;
    char aviao[10];

    while (1) {
        scanf("%d", &pontoCardeal);
        if (pontoCardeal == 0) break;
        scanf("%s", aviao);

        switch (pontoCardeal) {
            case -1: enfileirar(&oeste, aviao); break;
            case -3: enfileirar(&norte, aviao); break;
            case -2: enfileirar(&sul, aviao); break;
            case -4: enfileirar(&leste, aviao); break;
        }
    }

    int primeiro = 1;

    // Imprime Oeste primeiro
    while (!filaVazia(&oeste)) {
        if (!primeiro) printf(" ");
        printf("%s", desenfileirar(&oeste));
        primeiro = 0;
    }

    // Melhorando a alternância exata entre Norte e Sul
    while (!filaVazia(&norte) || !filaVazia(&sul)) {
        if (!filaVazia(&norte)) {
            if (!primeiro) printf(" ");
            printf("%s", desenfileirar(&norte));
            primeiro = 0;
        }
        if (!filaVazia(&sul)) {
            if (!primeiro) printf(" ");
            printf("%s", desenfileirar(&sul));
            primeiro = 0;
        }
    }

    // Imprime Leste por último
    while (!filaVazia(&leste)) {
        if (!primeiro) printf(" ");
        printf("%s", desenfileirar(&leste));
        primeiro = 0;
    }

    printf("\n"); // Corrigindo formatação da saída
    return 0;
}
