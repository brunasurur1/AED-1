//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Runtime error
//Exercício Beecrowd: A Fila de Desempregados tentado em 09/02 para estudo

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da lista circular duplamente ligada
typedef struct No {
    int valor;  // Valor do nó (representando a posição na fila)
    struct No *prox;  // Ponteiro para o próximo nó na lista circular
    struct No *ant;   // Ponteiro para o nó anterior na lista circular
} No;

// Função para criar um novo nó na lista circular
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));  // Aloca memória para o nó
    novo->valor = valor;  // Define o valor do nó
    novo->prox = novo;  // Inicialmente, aponta para si mesmo (lista circular)
    novo->ant = novo;
    return novo;
}

// Função para remover um nó da lista circular e retornar o próximo nó válido
No* removerNo(No *atual) {
    if (atual->prox == atual) {  // Se há apenas um elemento na lista
        free(atual);  // Libera a memória
        return NULL;
    }
    No *anterior = atual->ant;  // Obtém o nó anterior
    No *proximo = atual->prox;  // Obtém o próximo nó

    anterior->prox = proximo;  // Ajusta os ponteiros para remover o nó atual
    proximo->ant = anterior;

    free(atual);  // Libera o nó removido
    return proximo;  // Retorna o próximo nó válido
}

int main() {
    int N, k, m;  // Número de pessoas na fila e os passos para remover cada uma

    while (1) {
        scanf("%d %d %d", &N, &k, &m);  // Lê os valores de entrada

        if (N == 0 && k == 0 && m == 0) break;  // Condição de parada

        No *inicio = criarNo(1);  // Cria o primeiro nó da lista

        // Criação da lista circular com N pessoas
        No *ultimo = inicio;
        for (int i = 2; i <= N; i++) {
            No *novo = criarNo(i);  // Cria um novo nó
            ultimo->prox = novo;  // Conecta o novo nó ao último
            novo->ant = ultimo;
            novo->prox = inicio;  // Liga de volta ao primeiro nó
            inicio->ant = novo;
            ultimo = novo;  // Atualiza o último nó da lista
        }

        No *sentidoHorario = inicio;  // Ponteiro para percorrer no sentido horário
        No *sentidoAntiHorario = ultimo;  // Ponteiro para percorrer no sentido anti-horário

        while (N > 0) {  // Continua enquanto houver pessoas na fila
            for (int i = 1; i < k; i++) sentidoHorario = sentidoHorario->prox;  // Move k posições no sentido horário
            for (int i = 1; i < m; i++) sentidoAntiHorario = sentidoAntiHorario->ant;  // Move m posições no sentido anti-horário

            printf("%3d", sentidoHorario->valor);  // Imprime a primeira pessoa removida
            
            if (sentidoHorario != sentidoAntiHorario) {  // Se forem diferentes, imprime a segunda pessoa removida
                printf("%3d", sentidoAntiHorario->valor);
                No *temp = sentidoHorario;
                sentidoHorario = removerNo(sentidoHorario);  // Remove a primeira pessoa
                sentidoAntiHorario = removerNo(sentidoAntiHorario);  // Remove a segunda pessoa
                if (sentidoHorario == temp) sentidoHorario = sentidoHorario->prox;  // Ajusta ponteiro se necessário
                N -= 2;  // Duas pessoas removidas
            } else {
                sentidoHorario = removerNo(sentidoHorario);  // Remove a única pessoa restante
                N--;  // Apenas uma pessoa removida
            }

            if (N > 0) printf(",");  // Imprime vírgula se houver mais pessoas a serem removidas
        }

        printf("\n");  // Nova linha após a sequência de eliminações
    }

    return 0;
}
