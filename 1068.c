//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Balanço de Parênteses, pedido no torneio Filas e Pilhas

#include <stdio.h>
#include <string.h>

#define MAX_CARACTERES 1000  // Tamanho máximo da expressão

// Função para verificar se os parênteses estão balanceados
int balanceada(char *expressao) {
    int pilha[MAX_CARACTERES], topo = -1;

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha[++topo] = '(';  // Empilha '('
        } else if (expressao[i] == ')') {
            if (topo == -1) {  // Se não houver '(' correspondente
                return 0;
            }
            topo--;  // Desempilha '(' correspondente
        }
    }

    return topo == -1;  // Retorna 1 se estiver balanceado, 0 caso contrário
}

int main() {
    char expressao[MAX_CARACTERES + 1];

    // Lê expressões até o final da entrada (EOF)
    while (fgets(expressao, sizeof(expressao), stdin)) {
        expressao[strcspn(expressao, "\n")] = '\0';  // Remove a quebra de linha

        if (strlen(expressao) == 0) {
            continue;  // Ignora linhas vazias
        }

        // Verifica se a expressão está balanceada
        if (balanceada(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
