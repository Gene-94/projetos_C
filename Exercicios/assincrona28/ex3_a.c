#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct _node {
    int numero;
    struct _node *proximo;
}node;


void inserir_no(node **head, int *val){
    node *aux=*head;

    node *temp=(node *) malloc(sizeof(node));
    temp->numero=*val;
    temp->proximo=NULL;  

    if (*head==NULL){
        *head=temp;
    }
    else {

        if(aux->numero<temp->numero){
            
            while(aux->proximo!=NULL){
                if(aux->proximo->numero>temp->numero){
                    break;
                }
                else{
                    aux=aux->proximo;
                }
            }
            temp->proximo=aux->proximo;
            aux->proximo=temp;
        }
        else {
            temp->proximo=aux;
            *head=temp; 
        }

        
    }
       
}


void imprimir_lista(node *head){

    int i=1;
    printf("\n");
    for(node *ptr=head; ptr!=NULL; ptr=ptr->proximo, i++){
        printf("No %d : %d\n", i, ptr->numero);
    }
    printf("\n");
}

void libertar_memoria(node *head){
    node *pntr=head;

    while( head != NULL){

        head=pntr->proximo;
        free(pntr);
        pntr=head;
    }
}


int main() {
    node *head = NULL;

    for(int i=0, nr;i<10;i++){
        printf("Insira um número: ");
        scanf("%d", &nr);
        inserir_no(&head, &nr);
    }
    imprimir_lista(head);
    libertar_memoria(head);




return 0;
}
