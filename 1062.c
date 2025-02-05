//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Trilhos, feito em 04/02

#include <stdio.h>
#include <stdlib.h>

#define vagoes 1000 // Define o número máximo de vagões

// Função para verificar se a sequência de saída é possível
int verificar_reorganizacao(int n, int ordem_vagoes[]) {
    int pilha[vagoes], indice_topo = -1, prox_vagao = 1; // Inicializa a pilha, topo e o próximo vagão esperado
    
    for (int i = 0; i < n; i++) { // Percorre a sequência de saída desejada
        while (prox_vagao <= ordem_vagoes[i]) { // Empilha os vagões até alcançar o desejado
            pilha[++indice_topo] = prox_vagao++; // Adiciona vagões à pilha
        }
        if (pilha[indice_topo] == ordem_vagoes[i]) { // Verifica se o vagão no topo é o esperado
            indice_topo--; // Remove o vagão da pilha
        } else {
            return 0; // Caso contrário, a sequência não é possível
        }
    }
    return 1; // Retorna 1 se for possível organizar a sequência
}

int main() {
    int n; // Número de vagões
    while (scanf("%d", &n) && n != 0) { // Lê o número de vagões até encontrar um 0
        int ordem_vagoes[vagoes]; // Vetor para armazenar a ordem desejada
        while (scanf("%d", &ordem_vagoes[0]) && ordem_vagoes[0] != 0) { // Lê a primeira entrada da sequência até encontrar 0
            for (int i = 1; i < n; i++) { // Lê os demais elementos da sequência
                scanf("%d", &ordem_vagoes[i]);
            }
            // Verifica se a sequência de saída pode ser obtida e imprime "Yes" ou "No"
            printf("%s\n", verificar_reorganizacao(n, ordem_vagoes) ? "Yes" : "No");
        }
        printf("\n"); // Linha em branco após cada bloco
    }
    return 0; 
}
