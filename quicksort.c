//Bruna Surur Bergara, RA: 165536
//Exercício "Comparação de Algoritmos - Parte 2" para entrega até dia 11/12/2024
// Código para QuickSort


#include <stdio.h>

// Função para trocar dois elementos em um array
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função de partição: escolhe um pivô e reorganiza o array
int partition(int array[], int low, int high) {
    // Escolhe o último elemento como pivô (pode ser qualquer outro)
    int pivot = array[high];
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (array[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Função de ordenação Quick Sort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // pi é o índice de partição, array[p] está no lugar correto
        int pi = partition(array, low, high);

        // Ordena recursivamente os sub-arrays antes e depois da partição
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

// Programa principal
int main() {
    int data[] = {52531, 98584, 94234, 27104, 52401, 54009, 17653, 13865, 23508, 60192};
    int n = sizeof(data) / sizeof(data[0]);
    printf("Array não ordenado: \n");
    printArray(data, n);

    // Chamada da função de ordenação Quick Sort
    quickSort(data, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(data, n);
    return 0;
}
