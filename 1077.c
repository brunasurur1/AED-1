//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Infixa para Posfixa, pedido no torneio Filas e Pilhas

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000  // Tamanho máximo da expressão

// Função para retornar a precedência de um operador
int precedencia(char operador) {
    switch (operador) {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default: return 0;  // Para parênteses
    }
}

// Função para converter infixa para posfixa
void infixaParaPosfixa(char *infixa, char *posfixa) {
    char pilha[MAX_SIZE];  // Pilha para operadores e parênteses
    int topo = -1;  // Índice do topo da pilha
    int j = 0;  // Índice para a expressão posfixa

    for (int i = 0; infixa[i] != '\0'; i++) {  // Percorre a expressão infixa
        if (isalnum(infixa[i])) {  // Se for um operando (letra ou número)
            posfixa[j++] = infixa[i];  // Adiciona à expressão posfixa
        } else if (infixa[i] == '(') {  // Se for um parêntese de abertura
            pilha[++topo] = infixa[i];  // Empilha
        } else if (infixa[i] == ')') {  // Se for um parêntese de fechamento
            while (topo != -1 && pilha[topo] != '(') {  // Desempilha até encontrar o '('
                posfixa[j++] = pilha[topo--];
            }
            topo--;  // Remove o '(' da pilha
        } else {  // Se for um operador
            while (topo != -1 && precedencia(pilha[topo]) >= precedencia(infixa[i])) {
                posfixa[j++] = pilha[topo--];  // Desempilha operadores com maior ou igual precedência
            }
            pilha[++topo] = infixa[i];  // Empilha o operador atual
        }
    }

    // Desempilha todos os operadores restantes
    while (topo != -1) {
        posfixa[j++] = pilha[topo--];
    }

    posfixa[j] = '\0';  // Finaliza a string da expressão posfixa
}

int main() {
    int N;
    scanf("%d", &N);  // Lê o número de casos de teste
    getchar();  // Consome o caractere de nova linha após o número de casos de teste

    for (int i = 0; i < N; i++) {  // Loop para processar cada caso de teste
        char infixa[MAX_SIZE + 1];  // Array para armazenar a expressão infixa
        char posfixa[MAX_SIZE + 1];  // Array para armazenar a expressão posfixa

        fgets(infixa, MAX_SIZE + 1, stdin);  // Lê a expressão infixa da entrada

        // Remove o caractere de nova linha no final da string, se houver
        infixa[strcspn(infixa, "\n")] = '\0';

        // Converte a expressão infixa para posfixa
        infixaParaPosfixa(infixa, posfixa);

        // Imprime a expressão posfixa
        printf("%s\n", posfixa);
    }

    return 0;  
}
