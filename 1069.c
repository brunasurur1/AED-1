#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1000

// Função que conta quantos diamantes podem ser extraídos
int contar_diamantes(const char *linha) {
    int pilha = 0, diamantes = 0;
    
    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == '<') {
            pilha++; // Encontra uma possível abertura de diamante
        } else if (linha[i] == '>' && pilha > 0) {
            pilha--; // Fecha um diamante
            diamantes++; // Contabiliza um diamante extraído
        }
    }
    return diamantes;
}

int main() {
    int N; // Número de casos de teste
    char linha[MAX_TAMANHO + 1];
    
    // Lendo o número de casos de teste
    scanf("%d", &N);
    getchar(); // Consumir o newline após o número
    
    for (int i = 0; i < N; i++) {
        if (fgets(linha, sizeof(linha), stdin)) {
            linha[strcspn(linha, "\n")] = '\0'; // Remover o newline
            printf("%d\n", contar_diamantes(linha));
        }
    }
    
    return 0;
}
