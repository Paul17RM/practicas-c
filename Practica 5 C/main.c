#include <stdio.h>
#include <stdlib.h>

int potencia(int ,int );  // base, exponente
void print_binario(int );  // printa en binario un int
void pulsar();  // espera a pulsar una tecla
void scan(int*,int*);   // scan de base y de exponente límite

int main(){
    int b, e;
    scan(&b, &e);
    potencia(b, e);
    return 0;
}


int potencia(int base,int exp){
    int decimal=1;
    for(int i=0; i<=exp; i++){
        printf("\nBase: %d\nExponente: %d\n", base, i);
        if(i!=0)
            decimal*=base;
        printf("Decimal= %d\n", decimal);
        print_binario(decimal);
        pulsar();
    }
}


void print_binario(int p){
    int bit;
    float num, dec;
    num=p;
        for(int numbit=0; num>=1; numbit++){
            num/=2;
            dec=num-(int)num;
            if(dec >= 0.5)
                bit=1;
            else
                bit=0;
            if(numbit%8==0)
                printf("\n");
            printf("Bit%i=%i\n", numbit, bit);
        }
}


void pulsar(){
    printf("\nPULSA PARA CONTINUAR\n");
    getchar();
}


void scan(int*b,int*e){
    char pregunta;
    do{
        do{
            printf("Base [2-10]: ");
            scanf("%i", b);
        }while(*b>10 || *b<2);

        do{
            printf("Exponente [0-10]: ");
            scanf("%i", e);
            fflush(stdin);

        }while(*e>10 || *e<0);

        printf("Modificar base y exponente (S/N)?: ");
        scanf("%c", &pregunta);
        fflush(stdin);

    }while(pregunta=='s' || pregunta=='S');
}
