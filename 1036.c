#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double A, B, C, delta, x1, x2;

    scanf("%lf %lf %lf",&A,&B,&C); //Lê os valores de ponto flutuante A, B e C

   delta = B * B - 4 * A * C; //cálculo do delta para uso na fórmula de Bhaskara

   if(A==0 || delta<0){ //Condições para não ser possível o cálculo
       printf("Impossivel calcular\n");
   }
   else{
//Cálculo das duas raízes
   x1 = (-B + sqrt(delta))/(2 * A); 
   x2 = (-B - sqrt(delta))/(2 * A);
//Imprime os resultados
       printf("R1 = %.5lf\n",x1);
       printf("R2 = %.5lf\n",x2);
   }
    return 0;
}
