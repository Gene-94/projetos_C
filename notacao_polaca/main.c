#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define OPERADORES "+-:/x*"

//struct para inserir tanto valores como operadores

// typedef struct eq {
//     int nr;
//     char opr;
//     struct eq *proximo;
// } eq;



//duas structs, uma contendo os numeros e outra os operadores
//desta forma quando alocar a memoria não reserva floats e char quando não é necessario, fa-lo separadamente

typedef struct nr {
    float numero;
    struct nr *proximo;
}nr;

typedef struct opr{
    char operador;
    struct opr *proximo;
}opr;

void pedir(char *string);
int validar(char *string);
void distribuir(char *string);
void adicionar_nr(int num);
void adicionar_opr(char opr);
void adicionar();

int main (){

    //char *str_eq;
    char str_eq[150] = {0};
    int x;

    printf("\t***** Calculadora Polaca *****\n");

    //o str_eq vai servir como uma especie de buffer, depois de ser carregado para a lista podemos libertar esta memoria
    //str_eq = (char *)malloc(150*sizeof(char));
    //não consigo passar os ponteiros corretamente se usar malloc/calloc

    do{
        // pedir expressão + instruções
        pedir(str_eq);

        //validar o input
        x=validar(str_eq);
    }while(x);//se não for validado volta a pedir


    //separar a equação nas suas partes individuais
    //confirmar se é numero ou operador
    //carregar para a lista
    distribuir(str_eq);




    return 0;
}

void pedir(char *string){

    // pedir expressão + instruções
    printf("\nInsira a sua equação na forma de notação polaca,com espaço entre os numero e operadores, abaixo.\n");
    printf("(exemplo: + * - + 2 3 5 33 + 3 4)");
    printf("\nEquação: ");

    //ler a equação escrita pelo utilizador toda numa linha so
    scanf(" %149[^\n]", string);
}

int validar(char *string){
    //validar o input
    /* se diferente de [0-9] e de OPERADORES e de " " */
    char c_permit[] ="+-x*/:0123456789 ";

    for(int i=0;string[i]!=0;i++) {
        int k=0;
        for(int j=0; c_permit[j]!=0;j++){

            if(c_permit[j]==string[i]){
                k=1;
                break;
            }
        }
        if(k==0){
            printf("\nForam identificados caracteres não reconhecidos na sua expressão.\n");
            printf("Por favor volte a inserir a sua equação, conferindo de que segue as indicações.\n");
            return 1;
        }
    }
    return 0;
}

void distribuir(char *string){
    //separar a equação nas suas partes individuais
    //confirmar se é numero ou operador
    //carregar para a lista
    char *cpntr, *cpntr2;
    int num;
    char op;
    cpntr=string;
    while(*cpntr!=0 && *cpntr2!=0){
      num=strtol(cpntr, &cpntr2,10);
      if(cpntr==cpntr2){
          cpntr2++;
          ch = *cpntr2;
          //inserir dados em no de struct opr
          adicionar_opr(ch);
          cpntr2++;
      }
      else{
          // Inserir num em no de struct nr
          adicionar_nr(num);
      }
      num=strtol(cpntr2, &cpntr,10);
      if(cpntr2==cpntr){
          cpntr++;
          ch = *cpntr;
          //inserir dados em no de struct opr
          adicionar_opr(ch);
          cpntr++;
      }
      else{
          // Inserir num em no de struct nr
          adicionar_nr(num);
      }
    }
}

//void adicionar_nr(){
//
//}
//
//void adicionar_opr(){
//
//}


