//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Wrong answer (5%)
//Exercício Beecrowd: Fuga do Cavalo tentado em 09/02 para estudo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 8
#define MAX_MOVIMENTOS 8

// Definição dos movimentos possíveis do cavalo
int dx[MAX_MOVIMENTOS] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[MAX_MOVIMENTOS] = {1, -1, 1, -1, 2, -2, 2, -2};

// Converte a notação de xadrez (ex: "c4") para índices do tabuleiro
void converterPosicao(char *entrada, int *linha, int *coluna) {
    *coluna = entrada[0] - 'a';  // Converte 'a'..'h' para 0..7
    *linha = TAMANHO - (entrada[1] - '0'); // Converte '1'..'8' para 0..7
}

int calcularMovimentosValidos(int cavaloX, int cavaloY, int tabuleiro[TAMANHO][TAMANHO]) {
    int movimentosValidos = 0;

    // Testa os 8 movimentos possíveis do cavalo
    for (int i = 0; i < MAX_MOVIMENTOS; i++) {
        int novoX = cavaloX + dx[i];
        int novoY = cavaloY + dy[i];

        // Verifica se está dentro do tabuleiro e não cai sobre um peão
        if (novoX >= 0 && novoX < TAMANHO && novoY >= 0 && novoY < TAMANHO && tabuleiro[novoX][novoY] == 0) {
            movimentosValidos++;
        }
    }

    return movimentosValidos;
}

int main() {
    char entrada[3];
    int casoTeste = 1; 

    while (1) {
        int tabuleiro[TAMANHO][TAMANHO] = {0};  // Inicializa o tabuleiro zerado
        
        scanf("%s", entrada);
        if (entrada[0] == '0') break;  // Condição de parada

        int cavaloX, cavaloY;
        converterPosicao(entrada, &cavaloX, &cavaloY); 

        // Lê e marca os peões no tabuleiro
        for (int i = 0; i < 8; i++) {
            scanf("%s", entrada);
            int peaoX, peaoY;
            converterPosicao(entrada, &peaoX, &peaoY);
            tabuleiro[peaoX][peaoY] = 1; 
        }

        // Se o cavalo já começa sobre um peão, ele não pode se mover
        if (tabuleiro[cavaloX][cavaloY] == 1) {
            printf("Caso de Teste #%d: 0 movimento(s).\n", casoTeste++);
            continue;
        }

        // Calcula os movimentos válidos do cavalo
        int movimentos = calcularMovimentosValidos(cavaloX, cavaloY, tabuleiro);

        // Imprime o resultado formatado corretamente
        printf("Caso de Teste #%d: %d movimento(s).\n", casoTeste++, movimentos);
    }

    return 0;
}
