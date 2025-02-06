//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Jogando Cartas Fora, feito em 05/02

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma fila
typedef struct {
    int *items;  // Array para armazenar os elementos da fila
    int inicio;   // Índice do início da fila
    int final;    // Índice do final da fila
    int tamanho;  // Tamanho máximo da fila
    int count;    // Número de elementos na fila
} Fila;

// Função para criar uma fila
Fila* crieFila(int tamanho) {
    Fila *fila = (Fila*)malloc(sizeof(Fila));  // Aloca memória para a fila
    fila->items = (int*)malloc(tamanho * sizeof(int));  // Aloca memória para o array de itens
    fila->inicio = 0;  // Inicializa o índice do início da fila
    fila->final = -1;   // Inicializa o índice do final da fila
    fila->tamanho = tamanho;  // Define o tamanho máximo da fila
    fila->count = 0;  // Inicializa o contador de elementos na fila
    return fila;  // Retorna a fila criada
}

// Função para verificar se a fila está vazia
int filaVazia(Fila *fila) {
    return fila->count == 0;  // Retorna 1 se a fila estiver vazia, 0 caso contrário
}

// Função para verificar se a fila está cheia
int filaCheia(Fila *fila) {
    return fila->count == fila->tamanho;  // Retorna 1 se a fila estiver cheia, 0 caso contrário
}

// Função para adicionar um elemento à fila
void enqueue(Fila *fila, int item) {
    if (filaCheia(fila)) {
        return;  // Se a fila estiver cheia, não faz nada
    }
    fila->final = (fila->final + 1) % fila->tamanho;  // Atualiza o índice do final da fila (circular)
    fila->items[fila->final] = item;  // Adiciona o item ao final da fila
    fila->count++;  // Incrementa o contador de elementos na fila
}

// Função para remover um elemento da fila
int dequeue(Fila *fila) {
    if (filaVazia(fila)) {
        return -1;  // Se a fila estiver vazia, retorna -1 (erro)
    }
    int item = fila->items[fila->inicio];  // Pega o item no início da fila
    fila->inicio = (fila->inicio + 1) % fila->tamanho;  // Atualiza o índice do início da fila (circular)
    fila->count--;  // Decrementa o contador de elementos na fila
    return item;  // Retorna o item removido
}

int main() {
    int n;  // Variável para armazenar o número de cartas

    while (1) {  // Loop infinito para processar múltiplos casos de teste
        scanf("%d", &n);  // Lê o número de cartas

        if (n == 0) {  // Condição de parada: se n for 0, encerra o loop
            break;
        }

        Fila *fila = crieFila(n);  // Cria uma fila para as cartas

        // Inicializa a fila com as cartas de 1 até n
        for (int i = 1; i <= n; i++) {
            enqueue(fila, i);  // Adiciona cada carta à fila
        }

        int descartadas[n - 1];  // Array para armazenar as cartas descartadas
        int descartadasQtd = 0;  // Contador de cartas descartadas

        // Processa as cartas até sobrar apenas uma
        while (fila->count > 1) {
            descartadas[descartadasQtd++] = dequeue(fila);  // Descarta a carta do topo e armazena no array
            enqueue(fila, dequeue(fila));  // Move a próxima carta para o final da fila
        }

        // Imprime a sequência de cartas descartadas
        printf("Discarded cards: ");
        for (int i = 0; i < descartadasQtd; i++) {
            printf("%d", descartadas[i]);  // Imprime cada carta descartada
            if (i < descartadasQtd - 1) {
                printf(", ");  // Adiciona uma vírgula e espaço entre as cartas (exceto a última)
            }
        }
        printf("\n");  // Pula para a próxima linha

        // Imprime a última carta remanescente
        printf("Remaining card: %d\n", dequeue(fila));

        // Libera a memória da fila
        free(fila->items);  // Libera o array de itens da fila
        free(fila);  // Libera a estrutura da fila
    }

    return 0;  // Retorna 0 indicando que o programa terminou com sucesso
}
