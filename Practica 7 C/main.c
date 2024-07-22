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

void mover_izda(char [maximo_chars]);
void scan_real(float * );
int posicion_punto_decimal (char [maximo_chars]);
void notacion_cientifica(char [maximo_chars], int * );
void copiar_mantisa(char [maximo_chars],char [32]);

void copiar_exponente(char [maximo_chars],char r[32]);
// copia el exponente a un array de 32 chars, en las 8 siguientes posiciones a la posicion 0

void colocar_signo(char ,char [32]);


int main(){
    float real;
    int exponente;
    char cifra[maximo_chars], memoria[32]={' '}, s='0', exp[maximo_chars];
    resetear(cifra);
    resetear(exp);
    scan_real(&real);
    if(real<0)
        s='1';
    binario_entera(real, cifra);
    insertar_final(cifra, '.');
    binario_fraccionaria((real-(int)real), cifra);
    mover_izda(cifra);
    printf("Numero real convertido a binario: ");
    prn_binario(cifra);

    notacion_cientifica(cifra, &exponente);
    printf("\nNumero binario en notacion cientifica: ");
    prn_binario(cifra);
    printf("\nExponente: %i", exponente);
    binario_entera(exponente+127, exp);
    mover_izda(exp);
    printf("\nExponente+127 en binario: ");
    prn_binario(exp);
    copiar_mantisa(cifra, memoria);
    copiar_exponente(exp, memoria);
    colocar_signo(s, memoria);
    printf("\nRepresentacion en memoria: ");
    for(int i=0; i<32; i++)
        printf("%c", memoria[i]);
    return 0;
}


void binario_entera(int entera, char numero[maximo_chars]){
    if (entera<0)
        entera-=(entera*2);
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
    if (decimal<0)
        decimal-=(decimal*2);
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

void scan_real(float *num){
    printf("Numero real en base decimal?: ");
    scanf("%f", num);
}

int posicion_punto_decimal(char numero[maximo_chars]){
    int i;
    for(i=0; numero[i]!='.'; i++){}
    return i;
}

void notacion_cientifica(char numero[maximo_chars], int *exp){
    int i,j;
    for(i=posicion_punto_decimal(numero)-1, j=0; i>0; i--, j++){
        poner_posicion(numero, i+1, numero[i]);
    }
    poner_posicion(numero, 1, '.');
    *exp=j;
}

void copiar_mantisa(char numero[maximo_chars], char mant[32]){
    int i,j;
    for(i=9, j=2; i<33; i++, j++){
        mant[i]=numero[j];
        if(mant[i]==' ')
            mant[i]='0';
    }
}

void copiar_exponente(char numero[maximo_chars], char r[32]){
    int i;
    for(i=0; i<8; i++)
        r[i+1]=numero[i];
        if(r[i]==' ')
            r[i]='0';
}

void colocar_signo(char signo, char r[32]){
    r[0]=signo;
}
