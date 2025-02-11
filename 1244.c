//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Ordenação por Tamanho feito em 11/02 para estudo

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar uma palavra e sua posição original
typedef struct {
    char palavra[51]; // String para armazenar a palavra (até 50 caracteres)
    int posicao;      // Posição original da palavra na entrada
} Palavra;

// Função de comparação para o qsort
int compararPalavras(const void *a, const void *b) {
    Palavra *palavraA = (Palavra *)a;
    Palavra *palavraB = (Palavra *)b;

    // Compara pelo tamanho da palavra (da maior para a menor)
    int tamanhoA = strlen(palavraA->palavra);
    int tamanhoB = strlen(palavraB->palavra);

    if (tamanhoA > tamanhoB) {
        return -1; // Retorna -1 para ordenar da maior para a menor
    } else if (tamanhoA < tamanhoB) {
        return 1; // Retorna 1 para ordenar da maior para a menor
    } else {
        // Se os tamanhos forem iguais, mantém a ordem original
        return palavraA->posicao - palavraB->posicao;
    }
}

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N); // Lê o número de casos de teste
    getchar(); // Consome o caractere de nova linha após o número

    for (int i = 0; i < N; i++) { // Loop para cada caso de teste
        char linha[2501]; // String para armazenar a linha de entrada (até 2500 caracteres)
        fgets(linha, 2501, stdin); // Lê a linha de entrada

        // Remove o caractere de nova linha no final da linha
        linha[strcspn(linha, "\n")] = '\0';

        Palavra palavras[50]; // Array para armazenar as palavras
        int contador = 0; // Contador de palavras

        // Divide a linha em palavras
        char *token = strtok(linha, " "); // Usa strtok para dividir a linha por espaços
        while (token != NULL) {
            strcpy(palavras[contador].palavra, token); // Copia a palavra para a estrutura
            palavras[contador].posicao = contador; // Armazena a posição original
            contador++; // Incrementa o contador de palavras
            token = strtok(NULL, " "); // Continua a divisão da linha
        }

        // Ordena as palavras usando qsort
        qsort(palavras, contador, sizeof(Palavra), compararPalavras);

        // Imprime as palavras ordenadas
        for (int j = 0; j < contador; j++) {
            printf("%s", palavras[j].palavra);
            if (j < contador - 1) {
                printf(" "); // Adiciona um espaço entre as palavras, exceto após a última
            }
        }
        printf("\n"); // Imprime uma nova linha após cada caso de teste
    }

    return 0;
}
