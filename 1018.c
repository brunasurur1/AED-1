///Bruna Surur Bergara, RA: 165536
///Exercício Cédulas feito em 07/12 para relembrar LP

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int N, cem, cinquenta, vinte, dez, cinco, dois, um;

    scanf("%d",&N);

    cem = N/100;
    cinquenta = (N%100)/50;
    vinte = (N - cem*100 - cinquenta*50)/20;
    dez = (N - cem*100 - cinquenta*50 - vinte*20)/10;
    cinco = (N - cem*100 - cinquenta*50 - vinte*20 - dez*10)/5;
    dois = (N - cem*100 - cinquenta*50 - vinte*20 - dez*10 - cinco*5)/2;
    um = (N - cem*100 - cinquenta*50 - vinte*20 - dez*10 - cinco*5 -dois*2)/1;

    printf("%d\n",N);
    printf("%d nota(s) de R$ 100,00\n", cem);
    printf("%d nota(s) de R$ 50,00\n", cinquenta);
    printf("%d nota(s) de R$ 20,00\n", vinte);
    printf("%d nota(s) de R$ 10,00\n", dez);
    printf("%d nota(s) de R$ 5,00\n", cinco);
    printf("%d nota(s) de R$ 2,00\n", dois);
    printf("%d nota(s) de R$ 1,00\n", um);

    return 0;
}
