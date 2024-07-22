#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FILAS 30
#define COLS 11

void rellenar_aleat(char [][COLS]);
int mas_antigua(char [][COLS]);
void imprimir_mat(char [][COLS]);

int main(){
    srand(time(NULL));
    char matricula[FILAS][COLS]={""};
    rellenar_aleat(matricula);
    printf("La matricula mas antigua esta en la posicion %i (%s).\n", mas_antigua(matricula), matricula[mas_antigua(matricula)]);
    imprimir_mat(matricula);
    return 0;
}


void rellenar_aleat(char mat[FILAS][COLS]){
    int i,j;
    for(i=0; i<FILAS; i++){
        mat[i][0]='E';
        mat[i][1]=mat[i][6]='-';
        for(j=2; j<COLS-1; j++){
            if(j<6)
                mat[i][j]=rand()%10+'0';
            else if(j>6)
                mat[i][j]=rand()%26+'A';
        }
    }
}

int mas_antigua(char mat[FILAS][COLS]){
    int i,j,k,pos=0;
    char comparar[2][4]={""};
    for(i=1; i<FILAS; i++){
        for(j=7, k=0; j<COLS-1; j++, k++){
                comparar[0][k]=mat[pos][j];
                comparar[1][k]=mat[i][j];
        }
     //   printf("%s, %s, %i\n", comparar[0], comparar[1], strcmp(comparar[0], comparar[1]));
        if(strcmp(comparar[0], comparar[1])>0)
            pos=i;
    }
    return pos;
}

void imprimir_mat(char mat[FILAS][COLS]){
    for(int i=0; i<FILAS; i++)
            printf("%s\n", mat[i]);
}
