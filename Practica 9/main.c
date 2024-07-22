#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 25

void rellenar (char *);
void eliminar (char *, char *);
int pos_car_fin (char *, char);

int main(){
    srand(time(NULL));
    char cadena[N], cadena2[N], cadena3[N], res, caracter;
    do{
        rellenar(cadena);
        rellenar(cadena2);
        printf("\n%s\n%s\n", cadena, cadena2);

        eliminar(cadena, cadena2);
        printf("\n%s\n%s\n", cadena, cadena2);

        rellenar(cadena3);
        caracter='2';
        printf("\n%s\nEl caracter %c esta en la posicion %i", cadena3, caracter, pos_car_fin(cadena3, caracter));

        printf("\nRepetir la ejecucion(S/N)?: ");
        scanf("%c", &res);
        fflush(stdin);
    }while(res=='S' || res=='s');
    return 0;
}


void rellenar(char *cad){
    int num, lon= rand()%(N-1);
    for(int i=0; i<=lon; i++){
        num= rand()%3;
        if(num==0)
            cad[i]=rand()%26+'A';
        else if(num==1)
            cad[i]=rand()%26+'a';
        else
            cad[i]=rand()%10+'0';
    }
    cad[lon+1]='\0';
}

void eliminar(char *cad, char *cad2){
    int i,j,k;
    for(i=0; i<strlen(cad); i++)
        for(j=0; j<strlen(cad2); j++)
            if(cad[i]==cad2[j])
                for(k=i; k<strlen(cad); k++)
                    cad[k]=cad[k+1];
}

int pos_car_fin(char *cad, char car){
    int i;
    if(strrchr(cad, car))
        i=strlen(strrchr(cad, car));
    else
        i=-1;
    return i;
}
