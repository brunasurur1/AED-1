

#include <stdio.h> // Biblioteca para entrada e saída de dados
#include <stdlib.h> // Biblioteca para funções auxiliares, incluindo qsort

#define MAX_ALUNOS 1000 // Define o número máximo de alunos permitido

// Função de comparação para ordenação decrescente
int comparar(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Retorna a diferença para ordenar em ordem decrescente
}

int main() {
    int N, M, i, inalterados; // Declaração das variáveis principais
    int notas[MAX_ALUNOS], ordenado[MAX_ALUNOS]; // Arrays para armazenar as notas originais e ordenadas
    
    scanf("%d", &N); // Lê o número de casos de teste
    
    while (N--) { // Loop para processar cada caso de teste
        scanf("%d", &M); // Lê o número de alunos no caso de teste atual
        
        for (i = 0; i < M; i++) { // Lê as notas dos alunos
            scanf("%d", &notas[i]); // Armazena a nota no array original
            ordenado[i] = notas[i]; // Copia a nota para o array que será ordenado
        }
        
        qsort(ordenado, M, sizeof(int), comparar); // Ordena o array em ordem decrescente
        
        inalterados = 0; // Inicializa o contador de alunos que não trocaram de posição
        for (i = 0; i < M; i++) { // Percorre os arrays comparando posições
            if (notas[i] == ordenado[i]) { // Verifica se a posição original foi mantida
                inalterados++; // Incrementa o contador se a posição for mantida
            }
        }
        
        printf("%d\n", inalterados); // Exibe o número de alunos que não precisaram trocar de lugar
    }
    
    return 0;
}
