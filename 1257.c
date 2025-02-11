//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Array Hash feito em 11/02 para estudo

#include <stdio.h>
#include <string.h>

int main() {
    int N; // Número de casos de teste
    scanf("%d", &N); 

    for (int i = 0; i < N; i++) { // Loop para cada caso de teste
        int L; // Número de strings
        scanf("%d", &L); 

        int hash = 0; // Inicializa o valor de hash como 0

        for (int j = 0; j < L; j++) { // Loop para cada string
            char str[51]; // String com até 50 caracteres
            scanf("%s", str); 

            int len = strlen(str); // Calcula o comprimento da string

            for (int k = 0; k < len; k++) { // Loop para cada caractere da string
                // Calcula o valor de hash para o caractere atual
                // (posição do caractere no alfabeto) + (posição do caractere na string) + (posição da string no conjunto)
                hash += (str[k] - 'A') + j + k;
            }
        }

        printf("%d\n", hash);
    }

    return 0;
}
