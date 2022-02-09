#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct eq {
    int nr;
    char opr;
    struct eq *proximo;
} eq;


int main (){
    char *str_eq, *token;
    
    char operadores[] ="+-x*/:";

    printf("\t***** Calculadora Polaca *****\n");
    printf("\nInsira a sua equação na forma de notação polaca,com espaço entre os numero e operadores, abaixo.\n");
    printf("(exemplo: + * - + 2 3 5 33 + 3 4");
    printf("Esquação: ");

    str_eq = (char *)calloc(150,sizeof(char));
    scanf("%149[^\n]", str_eq);

    for(int i=0; str_eq[i]!=0;i++){
        if()
    }

    eq *fim = malloc(sizeof(int));
    token = strtok(str_eq, " ");
    //strtof(token, NULL, 10);
    fim->nr = atof(token);
    while (token != NULL){
        token = strtok(NULL, " ");
    }
    


    return 0;
}