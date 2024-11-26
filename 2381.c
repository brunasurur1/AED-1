//Bruna Surur Bergara, RA: 165536
//Exercício "Lista de Chamada" dado para entrega até dia 26/11/2024
//Entregue no dia 26/11/2024

#include <stdio.h>
#include <string.h>

int main() {
    int N, K;           // Declara N (número de alunos) e K (posição sorteada)
    scanf("%d %d", &N, &K); // Lê os valores de N e K fornecidos pelo usuário

    char nomes[N][21];  // Declara um array de strings para armazenar os nomes (máximo de 20 caracteres + '\0')

    for (int i = 0; i < N; i++) {
        // Lê os nomes dos alunos e os armazena no array 'nomes'
        scanf("%s", nomes[i]);
    }

    // Realiza a ordenação alfabética dos nomes usando o algoritmo Bubble Sort
    for (int i = 0; i < N - 1; i++) {             // Loop externo para percorrer todos os elementos
        for (int j = 0; j < N - i - 1; j++) {     // Loop interno para comparar pares de elementos adjacentes
            if (strcmp(nomes[j], nomes[j + 1]) > 0) { // Compara dois nomes; se o atual for maior, troca com o próximo
                char temp[21];                     // Variável temporária para realizar a troca
                strcpy(temp, nomes[j]);            // Copia o nome atual para a variável temporária
                strcpy(nomes[j], nomes[j + 1]);    // Substitui o nome atual pelo próximo
                strcpy(nomes[j + 1], temp);        // Coloca o valor da variável temporária no próximo
            }
        }
    }

    // Imprime o nome do aluno correspondente à posição K-ésima (ajustando para índice 0)
    printf("%s\n", nomes[K - 1]);

    return 0; 
}
