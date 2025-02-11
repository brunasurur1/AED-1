//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Runtime error
//Exercício Beecrowd: Produção Ótima de Ótima Vodka tentado em 10/02 para estudo

#include <stdio.h>  
#include <limits.h> 

#define MAX_N 100  // Número máximo de anos permitido

// Função para calcular o menor custo possível
int calcularCustoMinimo(int N, int I, int M, int custos[]) {
    int dp[MAX_N + 1][MAX_N + 1]; // Tabela de Programação Dinâmica (DP)
    
    // Inicializa a tabela DP com um valor muito alto (simulando infinito)
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = INT_MAX; // Define todos os valores como "infinito"
        }
    }

    // Caso base: No início, o equipamento começa com idade "I" e custo 0
    dp[0][I] = 0;

    // Preenchendo a tabela DP ano a ano
    for (int ano = 1; ano <= N; ano++) {
        for (int idade = 1; idade <= M; idade++) {
            // Mantendo o equipamento por mais um ano (se a idade for maior que 1)
            if (idade > 1) {
                dp[ano][idade] = dp[ano - 1][idade - 1] + custos[ano - 1];
            }
            // Comprando um novo equipamento (idade reseta para M)
            for (int idadeAnt = 1; idadeAnt < M; idadeAnt++) {
                if (dp[ano - 1][idadeAnt] != INT_MAX) { 
                    dp[ano][M] = (dp[ano][M] < dp[ano - 1][idadeAnt] + custos[ano - 1]) ? dp[ano][M] : (dp[ano - 1][idadeAnt] + custos[ano - 1]);
                }
            }
        }
    }

    // Encontrar o menor custo final dentre todas as idades possíveis ao fim do período
    int menorCusto = INT_MAX;
    for (int idade = 1; idade <= M; idade++) {
        if (dp[N][idade] < menorCusto) {
            menorCusto = dp[N][idade]; // Atualiza o menor custo encontrado
        }
    }

    return menorCusto; // Retorna o menor custo encontrado
}

int main() {
    int N, I, M;  // Declaração das variáveis: número de anos, idade inicial e idade máxima
    int custos[MAX_N];  // Vetor para armazenar os custos anuais

    // Enquanto houver entrada válida
    while (scanf("%d %d %d", &N, &I, &M) == 3) {
        // Lendo os custos anuais
        for (int i = 0; i < N; i++) {
            scanf("%d", &custos[i]);  
        }

        printf("%d\n", calcularCustoMinimo(N, I, M, custos));
    }

    return 0;
}
