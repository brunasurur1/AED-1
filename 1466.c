//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Polícia e Ladrão feito em 12/02 para estudo

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da árvore binária
typedef struct Node {
    int data; // Dado do nó
    struct Node* left; // Ponteiro para o filho esquerdo
    struct Node* right; // Ponteiro para o filho direito
} Node;

// Função para criar um novo nó
Node* criarNo(int data) {
    Node* novoNo = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo nó
    novoNo->data = data; // Define o dado do nó
    novoNo->left = NULL; // Inicializa o filho esquerdo como NULL
    novoNo->right = NULL; // Inicializa o filho direito como NULL
    return novoNo; // Retorna o novo nó
}

// Função para inserir um nó na árvore
Node* inserirNo(Node* raiz, int data) {
    if (raiz == NULL) { // Se a árvore estiver vazia
        return criarNo(data); // Cria um novo nó
    }

    if (data < raiz->data) { // Se o dado for menor que o dado da raiz
        raiz->left = inserirNo(raiz->left, data); // Insere no filho esquerdo
    } else { // Se o dado for maior ou igual ao dado da raiz
        raiz->right = inserirNo(raiz->right, data); // Insere no filho direito
    }

    return raiz; // Retorna a raiz da árvore
}

// Função para realizar o percurso em nível (BFS)
void percursoEmNivel(Node* raiz) {
    if (raiz == NULL) { // Se a árvore estiver vazia
        return;
    }

    Node* fila[1000]; // Fila para armazenar os nós
    int inicio = 0, fim = 0; // Índices para o início e o fim da fila

    fila[fim++] = raiz; // Adiciona a raiz na fila

    while (inicio < fim) { // Enquanto a fila não estiver vazia
        Node* noAtual = fila[inicio++]; // Remove o nó da frente da fila

        printf("%d", noAtual->data); // Imprime o dado do nó

        if (noAtual->left != NULL) { // Se houver filho esquerdo
            fila[fim++] = noAtual->left; // Adiciona o filho esquerdo na fila
        }
        if (noAtual->right != NULL) { // Se houver filho direito
            fila[fim++] = noAtual->right; // Adiciona o filho direito na fila
        }

        if (inicio < fim) { // Se ainda houver nós na fila
            printf(" "); // Imprime um espaço entre os dados
        }
    }

    printf("\n"); // Imprime uma nova linha após o percurso
}

int main() {
    int C; // Número de casos de teste
    scanf("%d", &C); // Lê o número de casos de teste

    for (int caso = 1; caso <= C; caso++) { // Loop para cada caso de teste
        int N; // Número de nós na árvore
        scanf("%d", &N); // Lê o número de nós

        Node* raiz = NULL; // Inicializa a raiz da árvore como NULL

        for (int i = 0; i < N; i++) { // Loop para ler os nós
            int data;
            scanf("%d", &data); // Lê o dado do nó
            raiz = inserirNo(raiz, data); // Insere o nó na árvore
        }

        printf("Case %d:\n", caso); // Imprime o número do caso de teste
        percursoEmNivel(raiz); // Realiza o percurso em nível
        printf("\n"); 
    }

    return 0;
}
