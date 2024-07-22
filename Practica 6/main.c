#include <stdio.h>
#include <stdlib.h>
#define maximo_chars 64

void binario_entera(int , char [maximo_chars]);
void binario_fraccionaria(float , char [maximo_chars]);
void resetear(char [maximo_chars]);
void poner_posicion (char [maximo_chars],int , char );
int bits_blanco(char [maximo_chars]);
void insertar_final(char [maximo_chars],char );
void prn_binario(char [maximo_chars]);


int main(){
    float num, num2;
    char cifra[maximo_chars];
    resetear(cifra);
    do{
        printf("Entera?: ");
        scanf("%f", &num);
    }while(num<0);

    do{
        printf("Fraccionaria?: ");
        scanf("%f", &num2);
    }while(num2<0 || num2>=1);

    binario_entera(num, cifra);
    if(num2!=0)
        insertar_final(cifra, '.');
    binario_fraccionaria(num2, cifra);
    prn_binario(cifra);
    return 0;
}


void binario_entera(int entera, char numero[maximo_chars]){
    float dec, ent=entera;
    for(int i=maximo_chars-1; ent>=1; i--){
    ent/=2;
    dec=ent-(int)ent;
    if(dec>=0.5)
        numero[i]='1';
    else
        numero[i]='0';
    }
}


void binario_fraccionaria(float decimal, char numero[maximo_chars]){
    do{
        decimal*=2;
        if(decimal<1)
            insertar_final(numero, '0');
        else{
            insertar_final(numero, '1');
            decimal-=1;
        }
    }while(decimal!=0);
}


void resetear(char numero[maximo_chars]){
    for(int i=0;i<maximo_chars;i++)
        numero[i]=' ';
}


void poner_posicion (char numero[maximo_chars],int n, char caracter){
    numero[n]=caracter;
}


int bits_blanco(char numero[maximo_chars]){
    int cont=0;
    for(int i=0; i<maximo_chars; i++)
        if(numero[i]==' ')
            cont++;
    return cont;
}


void insertar_final(char numero[maximo_chars],char c){
    for(int i=bits_blanco(numero)-1; i<maximo_chars-1; i++)
        poner_posicion(numero, i, numero[i+1]);
        poner_posicion(numero, maximo_chars-1, c);
}


void prn_binario(char numero[maximo_chars]){
    for(int i=0; i<maximo_chars; i++)
        if(numero[i]!=' ')
        printf("%c", numero[i]);
}
