//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Bingo! feito em 09/02 para estudo

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, B;  // Declaração das variáveis para o número total e a quantidade de bolas disponíveis
    
    while (1) {  // Loop infinito para processar múltiplos casos de teste
        scanf("%d %d", &N, &B);  // Lê os valores de N (número máximo) e B (quantidade de bolas disponíveis)
        
        if (N == 0 && B == 0) break;  // Se ambos forem zero, encerra a execução
        
        int bolas[B];  // Array para armazenar os números das bolas disponíveis
        int diferencas[N + 1];  // Array para marcar quais diferenças já foram encontradas
        
        for (int i = 0; i < B; i++) {
            scanf("%d", &bolas[i]);  // Lê os valores das bolas disponíveis
        }

        // Inicializa o array de diferenças como todas ausentes (0)
        for (int i = 0; i <= N; i++) {
            diferencas[i] = 0;  
        }

        // Calcula todas as diferenças possíveis entre os números das bolas
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                int diff = abs(bolas[i] - bolas[j]);  // Calcula a diferença absoluta entre duas bolas
                diferencas[diff] = 1;  // Marca essa diferença como encontrada
            }
        }

        int possivel = 1;  // Variável para indicar se todas as diferenças foram cobertas

        // Verifica se todas as diferenças de 0 até N foram encontradas
        for (int i = 0; i <= N; i++) {
            if (diferencas[i] == 0) {  // Se uma diferença não foi encontrada
                possivel = 0;  // Indica que o bingo não pode cobrir todas as diferenças
                break;  // Sai do loop, pois já sabemos que o resultado será "N"
            }
        }

        if (possivel) {  // Se todas as diferenças de 0 até N foram cobertas
            printf("Y\n");  // Imprime "Y" indicando que é possível cobrir todas as diferenças
        } else {
            printf("N\n");  // Imprime "N" indicando que alguma diferença não foi encontrada
        }
    }

    return 0;
}
