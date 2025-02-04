//Bruna Surur Bergara, RA: 165536
//Exercício Beecrowd: Tabelas Hash entregue em 28/01/2025 e dado em torneio

#include <stdio.h>
#include <stdlib.h>

// Estrutura de elemento para listas encadeadas
typedef struct Elemento {
    int valor;
    struct Elemento* proximo;
} Elemento;

// Função para criar um novo elemento na lista encadeada
Elemento* criarElemento(int valor) {
    Elemento* novoElemento = (Elemento*)malloc(sizeof(Elemento));
    novoElemento->valor = valor;
    novoElemento->proximo = NULL;
    return novoElemento;
}

// Função para inserir um valor na lista encadeada da tabela hash
void inserir(Elemento** tabelaHash, int posicao, int valor) {
    Elemento* novoElemento = criarElemento(valor);
    if (tabelaHash[posicao] == NULL) {
        tabelaHash[posicao] = novoElemento;
    } else {
        Elemento* atual = tabelaHash[posicao];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoElemento;
    }
}

// Função para exibir o conteúdo da tabela hash
void exibirTabelaHash(Elemento** tabelaHash, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ->", i);
        Elemento* atual = tabelaHash[i];
        while (atual != NULL) {
            printf(" %d ->", atual->valor);
            atual = atual->proximo;
        }
        printf(" \\\n");
    }
}

// Função principal
int main() {
    int casosTeste; // Número de casos de teste
    scanf("%d", &casosTeste);

    for (int caso = 0; caso < casosTeste; caso++) {
        if (caso > 0) {
            printf("\n"); // Linha em branco entre os casos de teste
        }

        int M, C; // Tamanho da tabela hash e quantidade de valores
        scanf("%d %d", &M, &C);

        Elemento** tabelaHash = (Elemento**)malloc(M * sizeof(Elemento*));
        for (int i = 0; i < M; i++) {
            tabelaHash[i] = NULL;
        }

        for (int i = 0; i < C; i++) {
            int valor;
            scanf("%d", &valor);
            int posicao = valor % M;
            inserir(tabelaHash, posicao, valor);
        }

        exibirTabelaHash(tabelaHash, M);

        // Libera a memória alocada para a tabela hash
        for (int i = 0; i < M; i++) {
            Elemento* atual = tabelaHash[i];
            while (atual != NULL) {
                Elemento* paraLiberar = atual;
                atual = atual->proximo;
                free(paraLiberar);
            }
        }
        free(tabelaHash);
    }

    return 0;
}
