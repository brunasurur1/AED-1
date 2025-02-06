//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Revisão de Contrato, feito em 05/02

#include <stdio.h>
#include <string.h>

int main() {
    int D;
    char N[101];  // String para armazenar o número (até 100 dígitos)

    while (1) {
        scanf("%d %s", &D, N);  // Lê o dígito e o número

        if (D == 0 && strcmp(N, "0") == 0) {  // Condição de parada
            break;
        }

        char resultado[101];  // String para armazenar o número resultante
        int j = 0;  // Índice para a string resultado

        // Percorre a string N e remove o dígito D
        for (int i = 0; N[i] != '\0'; i++) {
            if (N[i] != '0' + D) {  // Verifica se o dígito não é igual a D
                resultado[j] = N[i];  // Adiciona o dígito ao resultado
                j++;
            }
        }
        resultado[j] = '\0';  // Finaliza a string resultado

        // Remove zeros à esquerda, exceto se o número for zero
        int k = 0;
        while (resultado[k] == '0' && k < j - 1) {
            k++;
        }

        // Verifica se o resultado está vazio
        if (j == 0) {
            printf("0\n");  // Se todos os dígitos foram removidos, imprime 0
        } else {
            printf("%s\n", resultado + k);  // Imprime o número resultante sem zeros à esquerda
        }
    }

    return 0;
}
