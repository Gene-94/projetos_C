#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct no_lista{
  // completar a declaracao da estrutura
  int data;
  struct no_lista *proximo;
};

// variavel global
struct no_lista *cabeca = NULL; // List is empty, head = tail.

/*
 * Criar um nó de lista.
 *
 * Parâmetros:
 *   - int data, valor do nó
 *
 * retorna um apontador para um nó de lista
 */
struct no_lista *criar_no_lista(int data)
{
    struct no_lista *temporario = (struct no_lista *) malloc(sizeof(struct no_lista));

    temporario->data = data;
    temporario->proximo = NULL; // First elementi in will be last in list

    return temporario;
}

/*
 * Inserir no inicio da lista
 *
 * Parâmetros:
 *   - struct no_lista lista
 *   - struct no_lista no, novo nó a inserir
 *
 * retorna um apontador para o novo nó da lista
 */
struct no_lista *inserir(struct no_lista *lista, struct no_lista *novo_no)
{
    novo_no->proximo = lista; // First element in will be last in list, as lista wil = cabeca & cabeca starting value is NULL

    cabeca = novo_no;

    return novo_no;
}

/*
 * Imprime uma lista
 *
 * Parâmetros:
 *   - lista
 *
 */
void imprime_lista(struct no_lista *lista){
    if (!lista)
      return;

    printf("%d -> ", lista->data);


    imprime_lista(lista->proximo);
}

int main(void){

    int numeros[] = {3, 2, 8, 6, 4, 4, 12};
    struct no_lista *no;


    for(int i=0; i<7; i++){ //numeros[6] é o ultimo elemento do array, portanto i=6 na ultima iteração e i<7 na condição
    no = criar_no_lista(numeros[i]);
      inserir(cabeca, no);
    }

    // imprimir a lista a partir da cabeca, utilizando o procedimento correcto. substituir os _____
    imprime_lista(cabeca);

    printf("\n");

    return 0;
}
