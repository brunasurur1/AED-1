//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Lista Telefônica Econômica feito em 10/02 para estudo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMEROS 100000
#define MAX_DIGITOS 201 // +1 para o caractere nulo '\0'

// Função para comparar duas strings (números de telefone)
int compararStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n; // Número de telefones na lista
    char *telefones[MAX_NUMEROS]; // Array de ponteiros para strings
    char buffer[MAX_DIGITOS]; // Buffer para ler cada número de telefone
    int economizados; // Número de dígitos economizados

    while (scanf("%d", &n) != EOF) { // Lê o número de telefones
        // Verifica se o número de telefones está dentro do limite
        if (n < 1 || n > MAX_NUMEROS) {
            printf("Número de telefones fora do limite.\n");
            continue;
        }

        // Aloca memória para cada número de telefone
        for (int i = 0; i < n; i++) {
            scanf("%s", buffer);
            telefones[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
            if (telefones[i] == NULL) {
                printf("Erro ao alocar memória.\n");
                return 1; // Encerra o programa com erro
            }
            strcpy(telefones[i], buffer);
        }

        // Ordena a lista de números de telefone
        qsort(telefones, n, sizeof(char *), compararStrings);

        economizados = 0; // Inicializa o contador de dígitos economizados

        // Compara cada número de telefone com o próximo
        for (int i = 0; i < n - 1; i++) {
            int j = 0;
            // Conta quantos dígitos iniciais são iguais entre os dois números
            while (telefones[i][j] == telefones[i + 1][j] && telefones[i][j] != '\0' && telefones[i + 1][j] != '\0') {
                economizados++; // Incrementa o contador de dígitos economizados
                j++;
            }
        }

        // Imprime o número de dígitos economizados
        printf("%d\n", economizados);

        // Libera a memória alocada para os números de telefone
        for (int i = 0; i < n; i++) {
            free(telefones[i]);
        }
    }

    return 0;
}
