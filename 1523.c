//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Wrong answer (25%)
//Exercício Beecrowd: Estacionamento Linear tentado em 07/02 para estudo

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um evento (chegada ou saída)
typedef struct {
    int tempo; // Momento do evento (horário de chegada ou saída)
    int tipo; // -1 para saída, 1 para chegada
} Evento;

// Função de comparação para ordenar eventos
int comparar_eventos(const void *a, const void *b) {
    Evento *e1 = (Evento *)a;
    Evento *e2 = (Evento *)b;
    if (e1->tempo == e2->tempo) {
        return e1->tipo - e2->tipo; // Prioriza saídas quando tempos são iguais
    }
    return e1->tempo - e2->tempo; // Ordena pelo tempo do evento
}

int main() {
    int N, K; // Número de motoristas e capacidade do estacionamento
    
    while (1) { // Loop infinito até encontrar condição de parada
        scanf("%d %d", &N, &K); // Lê os valores de N (motoristas) e K (capacidade)
        if (N == 0 && K == 0) break; // Condição de parada
        
        Evento eventos[2 * N]; // Vetor para armazenar eventos de chegada e saída
        
        for (int i = 0; i < N; i++) { // Loop para ler os horários de chegada e saída
            int chegada, saida;
            scanf("%d %d", &chegada, &saida); // Lê os tempos de chegada e saída
            eventos[2 * i] = (Evento){chegada, 1}; // Armazena evento de chegada
            eventos[2 * i + 1] = (Evento){saida, -1}; // Armazena evento de saída
        }
        
        // Ordena os eventos para garantir processamento correto
        qsort(eventos, 2 * N, sizeof(Evento), comparar_eventos);
        
        int estacionados = 0; // Contador de carros estacionados
        int sucesso = 1; // Flag para indicar se todos conseguiram estacionar
        
        for (int i = 0; i < 2 * N; i++) { // Processa os eventos ordenados
            if (eventos[i].tipo == -1) { // Primeiro processa saídas
                estacionados--;
            } else { // Depois processa chegadas
                if (estacionados + 1 > K) { // Se ultrapassar a capacidade do estacionamento
                    sucesso = 0; // Define falha
                    break; // Sai do loop
                }
                estacionados++; // Adiciona um carro ao estacionamento
            }
        }
        
        printf("%s\n", sucesso ? "Sim" : "Nao"); 
    }
    
    return 0;
}
