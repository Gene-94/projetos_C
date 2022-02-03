#include <stdlib.h>
#include <stdio.h>
 //p->a == (*p).a

typedef struct no_lista {
    char valor;
    struct no_lista *proximo;
}no;

void imprimir_lista(no *inicio) {
    no *temporario;
    temporario = inicio;

    while (temporario != NULL) {
        printf(" %c", temporario->valor);
        temporario = temporario->proximo;
    }
}

no *criar_novo_no(char valor) {
    no *resultado;
    resultado = malloc(sizeof(no));
    resultado->valor=valor;
    resultado->proximo=NULL;
    return resultado;
}

no *inserir_inicio(no **inicio, no *no_x){
    no_x->proximo=*inicio;
    *inicio = no_x;
    return no_x;
}

void inserir_depois_de_no(no *no_anterior, no *novo_no){
    novo_no->proximo = no_anterior->proximo;
    no_anterior->proximo=novo_no;
}

no *pesquisa (no *inicio, char valor) {
    no *tpm = inicio;
    while (tpm != NULL){
        if (tpm->valor==valor) return tpm;
        tpm=tpm->proximo;
    }
    return NULL;
}

int main () {
    no *temp;
    //no *n1,*n2,*n3;
    no *inicio=NULL;
    char in;


//    n1=malloc(sizeof(no));
//    n2=malloc(sizeof(no));
//    n3=malloc(sizeof(no));


//    printf("Input: ");
//    scanf(" %c", &in);
//    n1->valor = in;
//    printf("Input: ");
//    scanf(" %c", &in);
//    n2->valor = in;
//    printf("Input: ");
//    scanf(" %c", &in);
//    n3->valor = in;
//
//
//    inicio = n2;
//    n2->proximo = n1;
//    n1->proximo = n3;
//    n3->proximo = NULL;

//    printf("Input: ");
//    scanf(" %c", &in);
//    n1=criar_novo_no(in);
//    printf("Input: ");
//    scanf(" %c", &in);
//    n2=criar_novo_no(in);
//    printf("Input: ");
//    scanf(" %c", &in);
//    n3=criar_novo_no(in);


//    for(int i = 0; i<3; i++){
//        printf("Insira um carcter: ");
//        scanf(" %c", &in);
//        temp = criar_novo_no(in);
//        temp->proximo = inicio;
//        inicio = temp;
//    }


//    temp = criar_novo_no('a');
//    inicio=temp;
//    temp=criar_novo_no('z');
//    temp->proximo=inicio;
//    inicio=temp;
//    temp=criar_novo_no('f');
//    temp->proximo=inicio;
//    inicio=temp;

//    printf("Input: ");
//    scanf(" %c", &in);
//    temp = criar_novo_no(in);
//    inicio=temp;
//    printf("Input: ");
//    scanf(" %c", &in);
//    temp=criar_novo_no(in);
//    temp->proximo=inicio;
//    inicio=temp;
//    printf("Input: ");
//    scanf(" %c", &in);
//    temp=criar_novo_no(in);
//    temp->proximo=inicio;
//    inicio=temp;

    for(int i=0;i<3;i++){
        printf("Input: ");
        scanf(" %c", &in);
        temp=criar_novo_no(in);
        inserir_inicio(&inicio,temp);
    }
//
//    imprimir_lista(inicio);
//
//    printf("\n\n\n");

    //inserir_depois_de_no(temp, criar_novo_no(in));

    for(int i=0;i<3;i++){
        printf("Input: ");
        scanf(" %c", &in);
        inserir_depois_de_no(temp, criar_novo_no(in));
    }

    //temp= pesquisa(inicio,'+');

    //printf("\n\n Encontri o node com %c", temp->valor);

    imprimir_lista(inicio);



    return 0;
}

