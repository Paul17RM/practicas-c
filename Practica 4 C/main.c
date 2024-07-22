#include <stdio.h>
#include <stdlib.h>

int main(){
    int bit, numbit, base, exp;
    long decimal=1;
    float num, dec;
    char pregunta;

    do{
        do{
            printf("Base [2-10]: ");
            scanf("%i", &base);
        }while(base>10 || base<2);

        do{
            printf("Exponente [0-10]: ");
            scanf("%i", &exp);
            fflush(stdin);

        }while(exp>10 || exp<0);

        printf("Modificar base y exponente (S/N)?: ");
        scanf("%c", &pregunta);
        fflush(stdin);

    }while(pregunta=='s' || pregunta=='S');


    for(int i=0; i<=exp; i++){
        printf("\nBase: %d\n", base);
        printf("Exponente: %d\n", i);
        if(i!=0)
            decimal*=base;
        printf("Decimal= %ld\n", decimal);

        num=decimal;
        numbit=0;
        do{
            num/=2;
            dec=num-(int)num;
            if(dec >= 0.5)
                bit=1;
            else
                bit=0;
            if(numbit%8==0)
                printf("\n");
            printf("Bit%i=%i\n", numbit, bit);
                numbit++;
        }while(num>=1);

        printf("\nPULSA PARA CONTINUAR\n");
        getchar();

    }
    return 0;
}
