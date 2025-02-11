//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Primo Rápido feito em 11/02 para estudo

#include <stdio.h>

// Função para verificar se um número é primo usando a divisão apenas por ímpares
int ehPrimo(int n) {
    if (n < 2) return 0; // Números menores que 2 não são primos
    if (n == 2 || n == 3) return 1; // 2 e 3 são primos
    if (n % 2 == 0 || n % 3 == 0) return 0; // Se for par (exceto 2) ou múltiplo de 3, não é primo

// Começamos a verificação com 5, pois ja descartamos 2 e 3, e 4 é múltiplo de 2
    int divisor = 5; 

// Se n é divisível por d, onde d x d <= n, então n não é primo
    while (divisor * divisor <= n) {
        if (n % divisor == 0 || n % (divisor + 2) == 0) {
            return 0; // Se for divisível por divisor ou (divisor + 2), não é primo
        }
        divisor += 2; // Testa apenas ímpares
    }

    return 1; // Se passou por todas as verificações é primo
}

int main() {
    int t, n;
    
    scanf("%d", &t); // Lê a quantidade de casos de teste

    while (t--) {
        scanf("%d", &n); // Lê o número a ser testado

        if (ehPrimo(n)) {
            printf("Prime\n"); // Se for primo, imprime "Prime"
        } else {
            printf("Not Prime\n"); // Se não for primo, imprime "Not Prime"
        }
    }

    return 0;
}

