//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: BMenor da Pilha, pedido no torneio Filas e Pilhas

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAX_OPERACOES 1000000 // Número máximo de operações permitidas

// Estrutura que representa um nó da pilha, armazenando um valor e o menor valor até o momento
typedef struct {
    int valor; // Valor do presente empilhado
    int min_atual; // Menor valor presente na pilha até o momento
} No;

// Estrutura da pilha, contendo os dados e um índice para o topo
typedef struct {
    No dados[MAX_OPERACOES]; // Array para armazenar os elementos da pilha
    int topo; // Índice do topo da pilha
} Pilha;

// Inicializa a pilha, definindo o topo como -1 (pilha vazia)
void inicializar_pilha(Pilha *p) {
    p->topo = -1;
}

// Insere um valor na pilha
void push(Pilha *p, int valor) {
    if (p->topo + 1 >= MAX_OPERACOES) return; // Evita estouro da pilha
    
    p->topo++; // Incrementa o índice do topo
    p->dados[p->topo].valor = valor; // Armazena o valor na pilha
    
    // Atualiza o menor valor na pilha até o momento
    if (p->topo == 0)
        p->dados[p->topo].min_atual = valor;
    else
        p->dados[p->topo].min_atual = (valor < p->dados[p->topo - 1].min_atual) ? valor : p->dados[p->topo - 1].min_atual;
}

// Remove um valor da pilha
void pop(Pilha *p) {
    if (p->topo >= 0) { // Só remove se houver elementos na pilha
        p->topo--; // Decrementa o topo para "remover" o elemento
    }
}

// Retorna o menor valor da pilha
void min(Pilha *p) {
    if (p->topo >= 0) // Se a pilha não estiver vazia
        printf("%d\n", p->dados[p->topo].min_atual); // Imprime o menor valor atual
    else if (p->topo == -1) // Garante que "EMPTY" só é impresso uma vez
        printf("EMPTY\n");
}

int main() {
    int N; // Número de operações
    char operacao[10]; // String para armazenar a operação lida
    int valor; // Variável para armazenar valores em operações PUSH
    Pilha pilha; // Declara a pilha
    inicializar_pilha(&pilha); // Inicializa a pilha
    
    scanf("%d", &N); // Lê o número de operações
    
    for (int i = 0; i < N; i++) { // Processa cada operação
        scanf("%s", operacao); // Lê o tipo de operação
        
        if (strcmp(operacao, "PUSH") == 0) { // Se for PUSH, lê um valor e adiciona na pilha
            scanf("%d", &valor);
            push(&pilha, valor);
        } else if (strcmp(operacao, "POP") == 0) { // Se for POP, remove um elemento da pilha
            if (pilha.topo >= 0) { // Apenas remove se houver elementos
                pop(&pilha);
            } else {
                printf("EMPTY\n"); // Imprime "EMPTY" somente quando a pilha está vazia
            }
        } else if (strcmp(operacao, "MIN") == 0) { // Se for MIN, imprime o menor valor da pilha
            min(&pilha);
        }
    }
    
    return 0;
}
