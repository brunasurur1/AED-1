//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd:WERTYU feito em 11/02 para estudo

#include <stdio.h>
#include <string.h>

// Mapeamento do teclado QWERTY deslocado para a esquerda
const char teclado[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
    char linha[1000]; // Buffer para armazenar a entrada

    // Lê cada linha da entrada
    while (fgets(linha, sizeof(linha), stdin)) {
        // Processa cada caractere da linha
        for (int i = 0; linha[i] != '\0'; i++) {
            // Se for espaço ou nova linha, imprime diretamente
            if (linha[i] == ' ' || linha[i] == '\n') {
                putchar(linha[i]);
                continue;
            }

            // Busca o caractere no mapeamento do teclado
            for (int j = 1; teclado[j] != '\0'; j++) {
                if (linha[i] == teclado[j]) {
                    putchar(teclado[j - 1]); // Imprime o caractere anterior
                    break;
                }
            }
        }
    }

    return 0;
}
