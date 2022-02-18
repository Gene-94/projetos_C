#include <stdlib.h>
#include <stdio.h>


typedef struct _lista {
    int index;
    char ch;
    struct lista * proximo;

}lista;

void seed_lista(lista **cabeca){
    //prepopular a lista para ser mais facil distingir as ações visualmente
    lista *pont=*cabeca;


    pont=malloc(sizeof(lista));
    pont->index=10;
    pont->ch='G'
    pont->proximo=malloc(sizeof(lista));
    pont->proximo->index=22;
    pont->proximo->ch='A'
    pont->proximo->proximo=malloc(sizeof(lista));
    pont->proximo->proximo->index=56;
    pont->proximo->proximo->ch='X'
    pont->proximo->proximo->proximo=NULL;  


}

void add_fim_lista(){
    // adiciona entrada no fim da lista, o valor de .proximo=NULL, sendo que é a tail da lista

}


void add_inicio_lista(){
    //adiciona entrada no inicio da lista, empurrando o valor atual da cabeça um no para a frente e tornando a nova entrada na cabeça

}


void add_depois_de(){
    //recebe um valor, pesquisa a lista ate encontrar o valor recebido e adiciona nova entrada após a entrada com o valor pesquisado

}

void add_antes_de(){
    //recebe um valor, pesquisa a lista ate encontrar o valor recebido e adiciona nova entrada antes da entrada com o valor pesquisado

}

void apagar_no(){
    // pesquisa no por valor de indice e apaga esse no da lista

}

void imprimir_lista(lista * cabeca){
    // imprime todos os valores da lista 
    for(lista * pont = cabeca; pont!=NULL;pont = pont->proximo){
        printf("\n----------------------\n")
        printf("Indice: %d\n", pont->index);
        printf("Caracter: %c", pont->ch);
        printf("\n----------------------\n")
    
    }
}


int main()
{
    // prepopular lista com 3 items com diversos valores 
    // pedir para utilizador inserir entrada a ser adicionada no fim da lista 
    // pedir para utilizador inserir entrada a ser adicionada no inicio da lista 
    // pedir para utilizador inserir entrada a ser adicionada após um determinado valor de indice
    // pedir para utilizador inserir entrada a ser adicionada entes de um valor de caracter
    // apaga no com um determinado indice
    //reimprime a lista após cada uma das ações
    lista *cabeca=NULL; 


    seed_lista(&cabeca);
    imprimir_lista(cabeca);



    return 0;
}
