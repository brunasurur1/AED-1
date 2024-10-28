#include <stdio.h>
#define TAM 9           // Define a constante TAM como 9, representando o tamanho da matriz 9x9
 
int main() {
    int n;              // Declara a variável para armazenar o número de instâncias de Sudoku
    scanf("%d", &n);    // Lê o número de instâncias de Sudoku a serem verificadas

    for (int k = 1; k <= n; k++) { // Loop para processar cada instância de Sudoku
        int matriz[TAM][TAM];      // Declara uma matriz 9x9 para armazenar a instância do Sudoku
        int eh_valido = 1;         // Inicializa como 1 (verdadeiro), assumindo que a matriz é válida

        // Ler a matriz 9x9 do Sudoku
        for (int linha = 0; linha < TAM; linha++) {
            for (int coluna = 0; coluna < TAM; coluna++) {
                scanf("%d", &matriz[linha][coluna]); // Lê cada valor da matriz de Sudoku
            }
        }

        // Verificar cada linha da matriz
        for (int linha = 0; linha < TAM && eh_valido; linha++) {
            int contador[TAM + 1] = {0};     // Vetor para contar aparições dos números de 1 a 9
            for (int coluna = 0; coluna < TAM; coluna++) {
                if (contador[matriz[linha][coluna]] > 0) { // Se o número já apareceu na linha
                    eh_valido = 0;                         // Define como inválido
                    break;                                 // Sai do loop da linha
                }
                contador[matriz[linha][coluna]]++; // Incrementa a contagem do número na linha
            }
        }

        // Verificar cada coluna da matriz
        for (int coluna = 0; coluna < TAM && eh_valido; coluna++) {
            int contador[TAM + 1] = {0};     // Vetor para contar aparições dos números de 1 a 9
            for (int linha = 0; linha < TAM; linha++) {
                if (contador[matriz[linha][coluna]] > 0) { // Se o número já apareceu na coluna
                    eh_valido = 0;                         // Define como inválido
                    break;                                 // Sai do loop da coluna
                }
                contador[matriz[linha][coluna]]++; // Incrementa a contagem do número na coluna
            }
        }

        // Verificar cada região 3x3 da matriz
        for (int regiao_linha = 0; regiao_linha < TAM && eh_valido; regiao_linha += 3) {
            for (int regiao_coluna = 0; regiao_coluna < TAM && eh_valido; regiao_coluna += 3) {
                int contador[TAM + 1] = {0};   // Vetor para contar aparições dos números de 1 a 9
                for (int i = regiao_linha; i < regiao_linha + 3; i++) {     // Loop para linhas da região
                    for (int j = regiao_coluna; j < regiao_coluna + 3; j++) { // Loop para colunas da região
                        if (contador[matriz[i][j]] > 0) { // Se o número já apareceu na região 3x3
                            eh_valido = 0;                // Define como inválido
                            break;                        // Sai do loop da região
                        }
                        contador[matriz[i][j]]++; // Incrementa a contagem do número na região 3x3
                    }
                }
            }
        }

        // Saída dos resultados
        printf("Instancia %d\n", k); // Imprime o número da instância atual
        if (eh_valido) {
            printf("SIM\n");         // Se válido, imprime "SIM"
        } else {
            printf("NAO\n");         // Se inválido, imprime "NAO"
        }

        printf("\n"); // Linha em branco após cada instância
    }

    return 0;
}
