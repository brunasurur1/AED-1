//Bruna Surur Bergara, RA: 165536
//Exercício feito para estudo
// Não foi finalizado, erro do becrowd: Wrong answer (5%)
//Exercício Beecrowd: Acampamento de Férias tentado em 10/02 para estudo

#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de cada participante
typedef struct {
    char nome[30]; // Nome do participante
    int valor;     // Número associado ao participante
} Participante;

int main() {
    int n; // Número de participantes
    while (scanf("%d", &n) && n != 0) { // Continua até encontrar 0
        Participante participantes[n]; // Vetor de participantes
        
        // Leitura dos participantes
        for (int i = 0; i < n; i++) {
            scanf("%s %d", participantes[i].nome, &participantes[i].valor);
        }

        int indice = 0; // Índice do participante inicial
        
        // Simulação do jogo até restar apenas um participante
        while (n > 1) {
            int passo = participantes[indice].valor; // Número de passos baseado no participante atual
            
            if (passo % 2 == 0) { // Se for par, sentido anti-horário
                indice = (indice - (passo % n) + n) % n;
            } else { // Se for ímpar, sentido horário
                indice = (indice + (passo % n)) % n;
            }
            
            // Remove o participante da lista
            for (int i = indice; i < n - 1; i++) {
                participantes[i] = participantes[i + 1];
            }
            n--; // Reduz o número de participantes
            indice = (indice) % n; // Ajusta o índice para a nova lista
        }

        printf("Vencedor(a): %s\n", participantes[0].nome);
    }

    return 0;
}
