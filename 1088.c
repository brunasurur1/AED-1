//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Bolhas e Baldes feito em 09/02 para estudo

#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para mesclar dois subarrays e contar inversões
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left; // Índices para percorrer os subarrays
    long long inversoes = 0; // Contador de inversões

    // Percorre os subarrays e mescla de forma ordenada
    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++]; // Mantém a ordem
        } else {
            temp[k++] = arr[j++]; // Move elemento da direita
            inversoes += (mid - i); // Conta inversões quando há troca
        }
    }

    // Copia os elementos restantes do primeiro subarray
    while (i <= mid - 1) temp[k++] = arr[i++];
    // Copia os elementos restantes do segundo subarray
    while (j <= right) temp[k++] = arr[j++];
    // Copia de volta para o array original
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inversoes;
}

// Função recursiva do Merge Sort para contar inversões
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inversoes = 0; // Contador de inversões
    if (left < right) {
        int mid = (left + right) / 2; // Encontra o meio do array
        inversoes += mergeSortAndCount(arr, temp, left, mid); // Ordena e conta inversões na primeira metade
        inversoes += mergeSortAndCount(arr, temp, mid + 1, right); // Ordena e conta inversões na segunda metade
        inversoes += mergeAndCount(arr, temp, left, mid + 1, right); // Mescla e conta inversões cruzadas
    }
    return inversoes;
}

// Função principal para contar inversões
long long contarInversoes(int arr[], int n) {
    int* temp = (int*)malloc(n * sizeof(int)); // Array temporário para o Merge Sort
    long long inversoes = mergeSortAndCount(arr, temp, 0, n - 1); // Chama a função para contar inversões
    free(temp); // Libera a memória alocada
    return inversoes;
}

int main() {
    while (1) {
        int n;
        scanf("%d", &n); // Lê o tamanho do array
        if (n == 0) break; // Condição de parada

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]); // Lê os elementos do array
        }

        long long inversoes = contarInversoes(arr, n); // Otimização para O(n log n) usando Merge Sort
        
        // Se o número de inversões for par, Carlos ganha, senão Marcelo
        if (inversoes % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }
    return 0;
}
