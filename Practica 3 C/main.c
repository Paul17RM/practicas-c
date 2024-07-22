#include <stdio.h>
#include <stdlib.h>
int main(){
    float num, num2;
    float dec;
    int bit;
    int numbit=0;

    do{
        printf("Parte entera numero float: ");
        scanf("%f", &num);
    }while(num<0);

    num = (int)num;

    do{
        num/=2;
        dec=num-(int)num;
        if(dec >= 0.5)
            bit=1;
        else
            bit=0;
        printf("Bit %i = %i\n", numbit, bit);
        numbit++;
    }while(num>=1);



    do{
        printf("Parte decimal numero float: ");
        scanf("%f", &num2);
    }while(num2<0 || num2>=1);

    numbit=-1;

    do{
        num2=num2*=2;
        if(num2<1)
            bit=0;
        else{
            bit=1;
            num2-=1;
        }
        printf("Bit %i = %i\n", numbit, bit);
        numbit--;
    }while(num2!=0);

    return 0;
}
