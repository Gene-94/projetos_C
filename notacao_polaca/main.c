#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//#define SPC ' '
 //p->a == (*p).a

 //a criar uma lista para ler toda a equação de uma vez ate encontrar caracter de escape
 //apos ler a equação percorer a equação da direita para a esquerda ate encontrar um operador
 //apos encontrar um operador, identificar o tipo de operação a aplicar e aplicar a operação nos dois nos mais a direita da equação, que serão necessariamente numeros
 //depois de realizar a operação substituir o valor do no do operador pelo resultado da operação e eleminar os dois nos mais a direita, assim simplicando fazeadamente a equação da direita para esquerda, tendo em conta as prioridades de operação
 //poderiamos fazer com um array, mas haveria situações em que os numeros envolvidos na operação não seriam os que estão mais a direita, necessitando assim de remover os operandos depois de cada opeação, para poder manter a regra e continuar a dar sweep da direita para a esquerda
typedef struct no_lista {
    //que tipo de dados uso para guardar elementos de tamanho variavel na lista?
    //flexible array member??
    char operador;
    float numero;
    struct no_lista *proximo;
}no;


no *criar_novo_no(no * ) {
    no *resultado;
    resultado = malloc(sizeof(no));
    strcpy(resultado->valor,valor);
    //resultado->valor=valor;
    resultado->proximo=NULL;
    return resultado;
}

//de momento esta a ser usada para criar pilha, de forma a dar sweep no input começando pelo ultimo intoduzido, que será um caracter de escape
no *inserir_inicio(no **inicio, no *no_x){
    no_x->proximo=*inicio;
    *inicio = no_x;
    return no_x;
}


//de momento sem uso, pode ser usada para inverter a lista e permitir escolher entre polaca e polaca inversa
void inserir_depois_de_no(no *no_anterior, no *novo_no){
    novo_no->proximo = no_anterior->proximo;
    no_anterior->proximo=novo_no;
}

no *pesquisa (no *inicio, no *valor) {
    no *tpm = inicio;
    while (tpm != NULL){
        if (tpm->valor==valor) return tpm;
        tpm=tpm->proximo;
    }
    return NULL;
}

void imprimir_lista(no *inicio) {
    no *temporario;
    temporario = inicio;

    while (temporario != NULL) {
        printf("%s", temporario->valor);
        temporario = temporario->proximo;
    }
}

int main () {
    no *temp;
    //no *n1,*n2,*n3;
    no *inicio=NULL;
    //char in; // em vez de ler carater a carater, linha a linha quero que o utilizador possa intoduzir a equação, do tamanho que desejar toda numa linha
    char *eq_polaca=NULL; //Ler input de utilizador com scanf com o modificador 'm' para alocar a memoria dinamicamente
    char* token;


//
//    char* ptr = NULL;
//    scanf("%m[^0]", &ptr );
//    printf("%s %d\n", ptr, strlen(ptr));
//    for(int i=0; i<strlen(ptr);i++){
//        printf("\nnumero do elemento no array: %d | conteudo: %c",i,ptr[i]);
//    }
//    token = strtok(ptr, " ");
//    printf("\n%s", token);
//    getchar();
//    getchar();


    printf("Insira a equação em notação polaca: ");
    scanf("%m[^\n]", &eq_polaca );//le linha toda e aloca memoria dinamicamente


    //carregar o array eq_polaca[] para a lista

    token=strtok(eq_polaca," ");

    while(token!=NULL){
        printf("%s\n", token);
        temp=criar_novo_no(token);
        inserir_inicio(&inicio,temp);
        token=strtok(NULL," ");
    }


    free(eq_polaca);//depois de carregado para a lista já podemos libertar a memoria


    imprimir_lista(inicio);//vai imprimir na ordem inversa a introduzida



    return 0;
}

