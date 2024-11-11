//Bruna Surur Bergara, RA: 165536
//Exercício "Amigos" dado no torneio para entrega até dia 11/11/2024
//Entregue 100% mas com "Presentation Error" no dia 10/11/2024
//Entregue com Accepted no dia 11/11/2024

#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>    

// Definindo uma estrutura chamada Celula que representará cada amigo na lista.
typedef struct Celula {
    char nome[20];          // Vetor de caracteres (string) para armazenar o nome do amigo, com até 20 caracteres.
    struct Celula *seg;     // Ponteiro para a próxima célula na lista, permitindo criar uma lista encadeada.
} Celula;

// Função para inicializar uma nova lista vazia com uma célula cabeça.
Celula* inicializa() {
    Celula *cabeca = (Celula*)malloc(sizeof(Celula)); // Aloca memória para uma nova célula cabeça.
    cabeca->seg = NULL;                               // Define que o ponteiro seg aponta para NULL (lista vazia).
    return cabeca;                                    // Retorna o ponteiro para a célula cabeça.
}

// Função para inserir um novo amigo no final da lista.
void insereNoFim(char nome[], Celula *lst) {
    Celula *nova = (Celula*)malloc(sizeof(Celula)); // Aloca memória para a nova célula a ser inserida.
    strcpy(nova->nome, nome);                       // Copia o nome do novo amigo para a célula nova.
    nova->seg = NULL;                               // Define o próximo elemento como NULL, pois será o último da lista.
    
    Celula *p = lst;                                // Ponteiro temporário para percorrer a lista, começando pela cabeça.
    while (p->seg != NULL) {                        // Continua avançando enquanto houver próximos elementos.
        p = p->seg;                                 // Avança para a próxima célula.
    }
    p->seg = nova;                                  // Conecta a nova célula ao final da lista.
}

// Função para buscar um amigo pelo nome e retornar o ponteiro para a célula onde ele está.
Celula* busca(char nome[], Celula *lst) {
    Celula *p = lst->seg;                           // Começa a busca após a célula cabeça.
    while (p != NULL && strcmp(p->nome, nome) != 0) { // Enquanto a lista não termina e o nome não é encontrado.
        p = p->seg;                                 // Avança para a próxima célula.
    }
    return p;                                       // Retorna o ponteiro para a célula com o nome ou NULL se não encontrar.
}

// Função para inserir uma nova célula antes de uma célula que contenha um nome específico.
void insereAntes(char nomeNovo[], char nomeExistente[], Celula *lst) {
    Celula *nova = (Celula*)malloc(sizeof(Celula)); // Aloca memória para a nova célula.
    strcpy(nova->nome, nomeNovo);                   // Copia o nome do novo amigo para a nova célula.
    
    Celula *p = lst;                                // Ponteiro auxiliar, começando na célula cabeça.
    while (p->seg != NULL && strcmp(p->seg->nome, nomeExistente) != 0) { // Avança até encontrar o nomeExistente ou o fim da lista.
        p = p->seg;                                 // Avança para a próxima célula.
    }
    
    nova->seg = p->seg;                             // Conecta o próximo da nova célula ao próximo de p.
    p->seg = nova;                                  // Conecta a nova célula antes da célula que contém nomeExistente.
}

// Função para imprimir todos os nomes da lista, começando após a célula cabeça.
void imprimeLista(Celula *lst) {
    Celula *p = lst->seg;                           // Ponteiro para começar na primeira célula após a cabeça.
    while (p != NULL) {                             // Continua enquanto houver elementos na lista.
        printf("%s", p->nome);                      // Imprime o nome do amigo.
        p = p->seg;                                 // Avança para a próxima célula.
        if (p != NULL) printf(" ");                 // Se não for o último item, imprime um espaço.
    }
    printf("\n");                                   // Quebra de linha após imprimir toda a lista.
}

// Função principal que executa a lógica do programa.
int main() {
    Celula *lista = inicializa();                   // Cria e inicializa a lista com uma célula cabeça.
    
    char nomesIniciais[100], novosNomes[100], amigoIndicado[20]; // Variáveis para armazenar as entradas.
    
    fgets(nomesIniciais, 100, stdin);               // Lê a lista inicial de amigos como uma linha completa.
    nomesIniciais[strcspn(nomesIniciais, "\n")] = '\0'; // Remove o caractere de nova linha.
    
    fgets(novosNomes, 100, stdin);                  // Lê a nova lista de amigos.
    novosNomes[strcspn(novosNomes, "\n")] = '\0';   // Remove o caractere de nova linha.
    
    fgets(amigoIndicado, 20, stdin);                // Lê o nome do amigo indicado ou "nao".
    amigoIndicado[strcspn(amigoIndicado, "\n")] = '\0'; // Remove o caractere de nova linha.
    
    char *token = strtok(nomesIniciais, " ");       // Separa a lista inicial em nomes individuais.
    while (token != NULL) {                         // Continua enquanto houver nomes na lista inicial.
        insereNoFim(token, lista);                  // Insere cada nome no final da lista.
        token = strtok(NULL, " ");                  // Avança para o próximo nome.
    }
    
    token = strtok(novosNomes, " ");                // Separa a nova lista em nomes individuais.
    while (token != NULL) {                         // Continua enquanto houver nomes na nova lista.
        if (strcmp(amigoIndicado, "nao") == 0) {    // Se a indicação é "nao", insere no fim.
            insereNoFim(token, lista);
        } else {                                    // Caso contrário, insere antes do amigo indicado.
            Celula *posicao = busca(amigoIndicado, lista); // Busca a posição do amigo indicado.
            if (posicao != NULL) {                  // Se encontrado, insere antes dele.
                insereAntes(token, amigoIndicado, lista);
            } else {                                // Se não encontrado, insere no fim.
                insereNoFim(token, lista);
            }
        }
        token = strtok(NULL, " ");                  // Avança para o próximo nome.
    }

    imprimeLista(lista);                            // Chama a função para imprimir a lista.
    
    return 0;                                       // Fim do programa com código de retorno 0.
}
