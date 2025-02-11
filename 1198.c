//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: O Bravo Guerreiro Hashmat feito em 11/02 para estudo

#include <stdio.h>
#include <stdlib.h>

// Função para calcular o valor absoluto da diferença entre dois números
long long int calcularDiferencaAbsoluta(long long int a, long long int b) {
    long long int diferenca = a - b; // Calcula a diferença
    if (diferenca < 0) { // Se a diferença for negativa
        return -diferenca; // Retorna o valor absoluto
    }
    return diferenca; // Retorna a diferença
}

int main() {
    long long int hashmat, oponente; // Variáveis para armazenar os números de soldados de Hashmat e seu oponente

    // Loop para ler as entradas até o final do arquivo (EOF)
    while (scanf("%lld %lld", &hashmat, &oponente) != EOF) {
        // Calcula e imprime a diferença absoluta
        printf("%lld\n", calcularDiferencaAbsoluta(hashmat, oponente));
    }

    return 0;
}
