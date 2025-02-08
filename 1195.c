

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
typedef struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
} Node;

// Função para criar um novo nó
Node* criarNo(int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore
Node* inserir(Node* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Função para percurso pré-ordem
void preOrdem(Node* raiz) {
    if (raiz != NULL) {
        printf(" %d", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Função para percurso em-ordem
void emOrdem(Node* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf(" %d", raiz->valor);
        emOrdem(raiz->direita);
    }
}

// Função para percurso pós-ordem
void posOrdem(Node* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf(" %d", raiz->valor);
    }
}

// Função para liberar a memória da árvore
void liberarArvore(Node* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    int C;
    scanf("%d", &C);  // Lê o número de casos de teste

    for (int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);  // Lê o número de elementos

        Node* raiz = NULL;
        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);  // Lê cada valor
            raiz = inserir(raiz, valor);  // Insere na árvore
        }

        printf("Case %d:\n", caso);

        // Percursos
        printf("Pre.:");
        preOrdem(raiz);
        printf("\n");

        printf("In..:");
        emOrdem(raiz);
        printf("\n");

        printf("Post:");
        posOrdem(raiz);
        printf("\n\n");

        // Libera a memória da árvore
        liberarArvore(raiz);
    }

    return 0;
}
