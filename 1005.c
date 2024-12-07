

#include <stdio.h>
#include <stdlib.h>

int main()
{

    double A,B,media;

    scanf("%lf", &A);
    scanf("%lf", &B);

    media = (3.5 * A + 7.5 * B)/11;

    printf("MEDIA = %.5lf\n", media);

    return 0;
}
