#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define maximo_chars 64
#define B 4

void binario_entera(int , char [maximo_chars]);
void binario_fraccionaria(float , char [maximo_chars]);
void resetear(char [maximo_chars]);
void poner_posicion (char [maximo_chars],int , char );
int bits_blanco(char [maximo_chars]);
void insertar_final(char [maximo_chars],char );
void prn_binario(char [maximo_chars]);
void mover_izda(char [maximo_chars]);
int posicion_punto_decimal (char [maximo_chars]);

int longitud(int );
float random_real();
void real_binario(float real,char bits_binario[maximo_chars]);
float numero_real(char b[maximo_chars]);


int main(){
    srand(time(NULL));
    float real;
    char cifra[maximo_chars];
    for(int cont=0; cont<B; cont++){
        resetear(cifra);
        real=random_real();
        printf("\nReal random: %f", real);
        printf("\nNumero real convertido a binario: ");
        real_binario(real, cifra);
        printf("\nReal recalculado: %f\n", numero_real(cifra));
    }
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
        printf("%c", numero[i]);
}

void mover_izda(char numero[maximo_chars]){
    for(int i=bits_blanco(numero), j=0; i<maximo_chars; i++, j++){
        poner_posicion(numero, j, numero[i]);
        poner_posicion(numero, i, ' ');
    }
}

int posicion_punto_decimal(char numero[maximo_chars]){
    int i;
    for(i=0; numero[i]!='.'; i++){}
    return i;
}

int longitud(int num){
    int suma=1;
    if(num/10!=0)
        suma+=longitud(num/10);
    return suma;
}

float random_real(){
    float entera, fraccionaria, random;
    entera=rand();
    fraccionaria=rand();
    fraccionaria/=pow(10, longitud(fraccionaria));
    random=entera+fraccionaria;
    return random;
}

void real_binario(float num, char binario[maximo_chars]){
    binario_entera(num, binario);
    insertar_final(binario, '.');
    binario_fraccionaria(num-(int)num, binario);
    mover_izda(binario);
    prn_binario(binario);
}

float numero_real(char b[maximo_chars]){
    float real=0;
    int i, exp;
    for(i=posicion_punto_decimal(b)-1, exp=0; i>=0; i--, exp++)
        if(b[i]=='1')
            real+=pow(2,exp);
    for(i=posicion_punto_decimal(b)+1, exp=-1; b[i]!=' '; i++, exp--)
        if(b[i]=='1')
            real+=pow(2,exp);
    return real;
}
