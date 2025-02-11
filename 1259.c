//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Pares e Ímpares feito em 11/02 para estudo

#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordenar os números pares em ordem crescente
int compararPares(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return num1 - num2; // Ordem crescente
}

// Função de comparação para ordenar os números ímpares em ordem decrescente
int compararImpares(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    return num2 - num1; // Ordem decrescente
}

int main() {
    int N; // Número de elementos
    scanf("%d", &N); // Lê o número de elementos

    int numeros[N]; // Array para armazenar os números
    int pares[N], impares[N]; // Arrays para armazenar os números pares e ímpares
    int countPares = 0, countImpares = 0; // Contadores para números pares e ímpares

    // Lê os números e separa em pares e ímpares
    for (int i = 0; i < N; i++) {
        scanf("%d", &numeros[i]);
        if (numeros[i] % 2 == 0) {
            pares[countPares++] = numeros[i]; // Armazena o número par
        } else {
            impares[countImpares++] = numeros[i]; // Armazena o número ímpar
        }
    }

    // Ordena os números pares em ordem crescente
    qsort(pares, countPares, sizeof(int), compararPares);

    // Ordena os números ímpares em ordem decrescente
    qsort(impares, countImpares, sizeof(int), compararImpares);

    // Imprime os números pares
    for (int i = 0; i < countPares; i++) {
        printf("%d\n", pares[i]);
    }

    // Imprime os números ímpares
    for (int i = 0; i < countImpares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
