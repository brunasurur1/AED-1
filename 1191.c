//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Recuperação de Árvore feito em 10/02 para estudo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Estrutura para representar um nó da árvore binária
typedef struct Noh {
    char data; // Dado do nó
    struct Noh* left; // Ponteiro para o filho esquerdo
    struct Noh* right; // Ponteiro para o filho direito
} Noh;

// Função para criar um novo nó
Noh* criarNo(char data) {
    Noh* novoNo = (Noh*)malloc(sizeof(Noh)); // Aloca memória para o novo nó
    novoNo->data = data; // Define o dado do nó
    novoNo->left = NULL; // Inicializa o filho esquerdo como NULL
    novoNo->right = NULL; // Inicializa o filho direito como NULL
    return novoNo; // Retorna o novo nó
}

// Função para encontrar o índice de um caractere em uma string
int encontrarIndice(char* str, int inicio, int fim, char valor) {
    for (int i = inicio; i <= fim; i++) { // Percorre a string
        if (str[i] == valor) { // Se encontrar o valor
            return i; // Retorna o índice
        }
    }
    return -1; // Retorna -1 se não encontrar
}

// Função para construir a árvore a partir das travessias em ordem e pré-ordem
Noh* construirArvore(char* preOrdem, char* emOrdem, int inicio, int fim, int* indicePre) {
    if (inicio > fim) { // Se o índice inicial for maior que o final
        return NULL; // Retorna NULL
    }

    Noh* no = criarNo(preOrdem[*indicePre]); // Cria um novo nó com o dado atual da pré-ordem
    (*indicePre)++; // Incrementa o índice da pré-ordem

    if (inicio == fim) { // Se o índice inicial for igual ao final
        return no; // Retorna o nó
    }

    int indiceEmOrdem = encontrarIndice(emOrdem, inicio, fim, no->data); // Encontra o índice do nó na travessia em ordem

    // Constrói a subárvore esquerda
    no->left = construirArvore(preOrdem, emOrdem, inicio, indiceEmOrdem - 1, indicePre);
    // Constrói a subárvore direita
    no->right = construirArvore(preOrdem, emOrdem, indiceEmOrdem + 1, fim, indicePre);

    return no; // Retorna o nó
}

// Função para realizar a travessia em pós-ordem
void posOrdem(Noh* no) {
    if (no == NULL) { // Se o nó for NULL
        return; // Retorna
    }

    posOrdem(no->left); // Visita a subárvore esquerda
    posOrdem(no->right); // Visita a subárvore direita
    printf("%c", no->data); // Imprime o dado do nó
}

// Função principal
int main() {
    char preOrdem[MAX], emOrdem[MAX]; // Strings para armazenar as travessias em pré-ordem e em ordem

    while (scanf("%s %s", preOrdem, emOrdem) != EOF) { // Lê as travessias em pré-ordem e em ordem
        int indicePre = 0; // Índice para percorrer a travessia em pré-ordem
        int tamanho = strlen(emOrdem); // Tamanho da travessia em ordem

        // Constrói a árvore a partir das travessias
        Noh* raiz = construirArvore(preOrdem, emOrdem, 0, tamanho - 1, &indicePre);

        // Realiza a travessia em pós-ordem e imprime o resultado
        posOrdem(raiz);
        printf("\n");
    }

    return 0;
}
