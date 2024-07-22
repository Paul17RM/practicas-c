#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;
    float dec;
    int bit;
    int numbit=0;

    do
        {
        printf("Numero decimal [0-255]: ");
        scanf("%f", &num);
        }
    while(num<0 || num>255);

        num = (int)num;

    do
        {
        num/=2;
        dec=num-(int)num;
        if(dec >= 0.5)
            bit=1;
        else
            bit=0;
        printf("Bit %i = %i\n", numbit, bit);
        numbit++;
        }
    while(num>=1);

    return 0;
}
