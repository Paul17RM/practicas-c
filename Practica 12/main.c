#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int num_palabras(FILE *);
void linea_mas_palabras(FILE *);
void quitar_caracteres(FILE *, FILE *, char [14]);

int main(){
    FILE *fich, *fichnuevo;
    char cadena[14];
    if(!(fich = fopen("texto1.txt", "r"))){
        printf("Error en la apertura del fichero");
        return 1;
    }
    if(!(fichnuevo = fopen("salida.txt", "w"))){
        printf("Error en la apertura del fichero");
        return 2;
    }

    printf("El numero de palabras del fichero es %i\n\n", num_palabras(fich));
    rewind(fich);
    linea_mas_palabras(fich);
    printf("Introduzca la cadena con los caracteres a quitar <max 14>: ");
    gets(cadena);
    rewind(fich);
    quitar_caracteres(fich, fichnuevo, cadena);

    fclose(fich);
    fclose(fichnuevo);

    return 0;
}


int num_palabras(FILE *f){
    int contador=0;
    char palabra[20];
    int fin = fscanf(f, "%s", palabra);
    while(fin!=EOF){
        if(isalpha(palabra[0]))
        contador++;
        fin = fscanf(f, "%s", palabra);
    }
    return contador;
}

void linea_mas_palabras(FILE *f){
    char linea[255], maspalabras[255];
    int contador, mayor=0, lmaspal, lin=0;
    while(fgets(linea, 255, f)){
        char *palabra = strtok(linea, " ");
        if(palabra != NULL){
            for(contador=0; palabra != NULL; contador++)
                palabra = strtok(NULL, " ");
        }
        lin++;
        if(contador>mayor){
            mayor=contador;
            lmaspal=lin;
        }
    }
    rewind(f);
    for(lin=1; lin<=lmaspal; lin++)
        fgets(linea, 255, f);
    printf("La linea con mas palabras es la linea %i con %i palabras: \n - %s\n", lmaspal, mayor, linea);
}

void quitar_caracteres(FILE *f_in, FILE *f_out, char cad[14]){
    int i;
    char letra, printar;
    int fin = fscanf(f_in, "%c", &letra);
    while(fin!=EOF){
        printar='s';
        for(i=0; i<strlen(cad); i++)
            if(cad[i]==letra)
                printar='n';
        if(printar!='n')
            fputc(letra, f_out);
        fin = fscanf(f_in, "%c", &letra);
    }
}
