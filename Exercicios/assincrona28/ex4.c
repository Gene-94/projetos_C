#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <curses.h>

typedef struct _node {
    int numero;
    char *nome;
    struct _node *proximo;
}node;


int inserir_no(node **head, long *val, char *nome){
    node *aux=*head;

    node *temp=(node *) malloc(sizeof(node));
    temp->numero=*val;
    temp->nome=nome;
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
        else if(aux->numero==temp->numero){
            printf("\nJá exite um funcionario com o número de funcioário introduzido !\n");
            printf("Confirme se o número de funcionário corresponde ao funcionário que esta a tentar inserir e volte a tentar.\n");
            return 1;
        }
        else {
            temp->proximo=aux;
            *head=temp; 
        }

        
    }
    return 0;   
}


void imprimir_lista(node *head){

    int i=1;
    printf("\n\t### Lista de funcionarios ###\n");
    printf("Número de funcionario\t|\tNome de funcionario\n");
    printf("-------------------------------------------------------------");
    for(node *ptr=head; ptr!=NULL; ptr=ptr->proximo, i++){
        printf("\n\t\t%d \t|\t %s",ptr->numero, ptr->nome);
    }
    printf("\n");
}

void libertar_memoria(node *head){
    node *pntr=head;

    while( head != NULL){

        head=pntr->proximo;
        free(pntr->nome);
        free(pntr);
        pntr=head;
    }
}


int main() {
    node *head = NULL;
    char *nome = NULL, *buff = NULL, *point = NULL, continuar='S';
    long nr=0;
    int k;

    printf("          *Adicionar funcionarios a base de dados*\n");
    printf("( o número de funcionario é unico e exclusivo a cada funcionario\n");
    printf("                  >> para sair insira: ! << \n");
    do{

        printf("\nInsira o número de funcionario: ");
        scanf(" %ms", &buff);
        nr = strtol(buff,&point,10);
        if(buff==point){
            printf("\nNúmero iserido invalido!\n");
            continue;
        }
        printf("Insira o nome de funcionario: ");
        scanf(" %m[^\n]", &nome);
        k = inserir_no(&head, &nr, nome);
        if(k==1){
            continue;
        }

        do{
            printf("\nContinuar a inserir (S/N)?");
            scanf(" %c", &continuar);
            fflush(stdin);
            if(continuar!='S' && continuar!='s' && continuar!='N' && continuar!='n'){
                printf("\nResposta invalida, por favor responda digitando S ou N.");
            }
        }while(continuar!='S' && continuar!='s' && continuar!='N' && continuar!='n');
        

        
        fflush(stdin);
        printf("\n");
    }while(continuar=='s' || continuar=='S');
    imprimir_lista(head);
    libertar_memoria(head);
    free(buff);
    free(nome);
return 0;
}
