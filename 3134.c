//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
//Exercício Beecrowd: Balança Equilibrada, pedido no torneio ÁRVORES

#include <stdio.h>
#include <math.h>

#define PRECISAO 1e-6 // Definição de precisão para comparação de ponto flutuante

// Função que verifica se é possível dividir os pacotes em dois grupos de mesmo peso
int verificaEquilibrio(double pesos[4], int index, double ladoEsq, double ladoDir) {
    if (index == 4) {
        return fabs(ladoEsq - ladoDir) < PRECISAO; // Verifica se os lados são praticamente iguais
    }
    
    // Tenta colocar o pacote atual no lado esquerdo ou direito
    return verificaEquilibrio(pesos, index + 1, ladoEsq + pesos[index], ladoDir) ||
           verificaEquilibrio(pesos, index + 1, ladoEsq, ladoDir + pesos[index]);
}

int main() {
    double pesos[4];
    
    // Lendo os quatro pesos
    for (int i = 0; i < 4; i++) {
        scanf("%lf", &pesos[i]);
    }
    
    // Se for possível balancear os pacotes, imprime "YES", senão imprime "NO"
    if (verificaEquilibrio(pesos, 0, 0.0, 0.0)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
