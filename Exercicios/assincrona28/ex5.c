#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <curses.h>

typedef struct _node {
    int numero;
    char *nome;
    struct _node *proximo;
    struct _node *ant;
}node;


int inserir_no(node **head, long *val, char *nome){
    node *aux=*head;
    

    node *temp=(node *) malloc(sizeof(node));
    temp->numero=*val;
    temp->nome=nome;
    temp->proximo=NULL;
    temp->ant=NULL;  

    if (*head==NULL){
        *head=temp;
    }
    else {

        if(aux->numero<=temp->numero){
            
            while(aux->proximo!=NULL){
                if(aux->proximo->numero>temp->numero){
                    break;
                }
                else{
                    aux=aux->proximo;
                }
            }
            if(aux->numero==temp->numero){
                printf("\nJá exite um funcionario com o número de funcioário introduzido !\n");
                printf("Confirme se o número de funcionário corresponde ao funcionário que esta a tentar inserir e volte a tentar.\n");
                return 1;
            }
            temp->proximo=aux->proximo;
            temp->ant=aux;
            if(aux->proximo!=NULL){
                aux->proximo->ant=temp;
            }
            aux->proximo=temp;
        }
        else {
            temp->proximo=aux;
            aux->ant=temp;
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

void eleminar_no(node **head, long *nr){
    node *p=*head;
    while( p!=NULL ){
        if(p->numero==*nr){
            break;
        }
        p=p->proximo;
    }
    if(p==NULL){
        printf("Número não encontrado !");
    }
    else{
        node *pant=p->ant;
        node *pprox=p->proximo;
        if(p->ant!=NULL){
            pant->proximo=pprox;
        }
        else{
            *head=p->proximo;
        }
        
        if(p->proximo!=NULL){
            pprox->ant=pant;
        }
        else{
            pant->proximo=NULL;
        }
        
        free(p);
    }
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

    printf("\n\nPretende eleminar elementos da lista (S/N)?");
    scanf(" %c", &continuar);
    while(continuar=='S' || continuar=='s'){
        printf("\n\nInsira o número do funcionario que pretende eleminar: ");
        scanf("%ld", &nr);
        eleminar_no(&head, &nr);
        imprimir_lista(head);
        printf("\n\nPretende eleminar mais elementos da lista (S/N)?");
        scanf(" %c", &continuar);
        fflush(stdin);
    }

    libertar_memoria(head);
    free(buff);
    free(nome);
return 0;
}
