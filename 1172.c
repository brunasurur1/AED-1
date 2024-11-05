

#include <stdio.h>
#define MAX 10 /// Definindo a variável MAX em 10, temos o total de endereços

int main()
{
    int X[MAX],i; ///X[MAX]=vetor e i para contabilizar a posição

    ///Com o for passaremos por cada posição do vetor para definirmos o número que será lido
    for(i=0;i<MAX;i++){
        scanf("%d",&X[i]);
    }
    ///Com o if, criaremos a condição de trocar numeros iguais a zero ou negativos por 1
    for(i=0;i<MAX;i++){
     if(X[i]<=0){
        printf("X[%d] = 1\n",i);
     }
     /// com o else, apenas traremos as outras possibilidades
     else {
        printf("X[%d] = %d\n",i,X[i]);
     }

    }

    return 0;
}
