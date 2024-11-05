//Bruna Surur Bergara, RA: 165536
//Exercício Beecrowd: Prefixa, Infixa e Posfixa entregue em 22/05/2023

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 2000

typedef struct arvore {
    char letra;
    struct arvore* esq;
    struct arvore* dir;
} arvore;

short indice;
arvore* nvno(char letra) {
    arvore* no = (arvore*)malloc(sizeof(arvore));
    no->letra = letra;
    no->esq = no->dir = NULL;

    return no;
}
int src(char *str, int inicio, int fim, char letra) {
    for (int i = inicio; i <= fim; ++i) {
        if (str[i] == letra) {
            return i;
        }
    }
    return -1;
}
arvore* tree(char *prefixa, char *infixa, int inicio, int fim) {
    if (inicio > fim)
        return NULL;

    arvore* no = nvno(prefixa[indice++]);

    if (inicio == fim)
        return no;

    int infixaIndice = src(infixa, inicio, fim, no->letra);
    no->esq = tree(prefixa, infixa, inicio, infixaIndice - 1);
    no->dir = tree(prefixa, infixa, infixaIndice + 1, fim);

    return no;
}

void posfixa(arvore *no) {
    if (no == NULL)
        return;

    posfixa(no->esq);
    posfixa(no->dir);
    printf("%c", no->letra);
}

int main() {
    short ncasos;
    short nnods;
    char prefixa[MAXSIZE], infixa[MAXSIZE];

    scanf("%hu", &ncasos);

    while (ncasos--) {
        scanf("%hu %s %s%*c", &nnods, prefixa, infixa);
        indice = 0;
        arvore* raiz = tree(prefixa, infixa, 0, nnods - 1);
        posfixa(raiz);
        printf("\n");
    }

    return 0;
}
