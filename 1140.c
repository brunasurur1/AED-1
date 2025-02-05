#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Para usar a função tolower()

int main() {
    char frase[1000];  // Array para armazenar a frase (considerando o pior caso)

    while (1) {  // Loop para ler cada caso de teste
        fgets(frase, sizeof(frase), stdin);  // Lê a frase da entrada

        // Remove o caractere de nova linha (\n) do final da frase, se houver
        frase[strcspn(frase, "\n")] = '\0';

        // Verifica se a frase é apenas '*' (condição de parada)
        if (strcmp(frase, "*") == 0) {
            break;  // Sai do loop
        }

        // Verifica se a frase é um tautograma
        char primeiraLetra = tolower(frase[0]);  // Pega a primeira letra da frase (em minúscula)
        int tautograma = 1;  // Assume que é um tautograma inicialmente

        for (int i = 1; frase[i] != '\0'; i++) {  // Percorre a frase
            if (frase[i - 1] == ' ') {  // Verifica se o caractere anterior é um espaço
                if (tolower(frase[i]) != primeiraLetra) {  // Compara a primeira letra da palavra atual
                    tautograma = 0;  // Não é um tautograma
                    break;  // Sai do loop
                }
            }
        }

        // Imprime o resultado
        if (tautograma) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;  
}
