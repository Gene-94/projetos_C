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
    struct no_lista *proximo;
    char valor;
}no;

void imprimir_lista(no *inicio) {
    no *temporario;
    temporario = inicio;

    while (temporario != NULL) {
        printf("%s", temporario->valor);
        temporario = temporario->proximo;
    }
}

no *criar_novo_no(char valor ) {
    no *resultado;
    resultado = malloc(sizeof(no));
    resultado->valor=valor;
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
    //char in; // em vez de ler carater a carater, linha a linha quero que o utilizador possa intoduzir a equação, do tamanho que desejar toda numa linha
    char *eq_polaca=NULL; //Ler input de utilizador com scanf com o modificador 'm' para alocar a memoria dinamicamente
    char* token;

#if 0
//Varios testes para entender progressivamento o funcionamento da lista e ganhar um maior nivel de controlo


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

//    for(int i=0;i<3;i++){
//        printf("Input: ");
//        scanf(" %c", &in);
//        temp=criar_novo_no(in);
//        inserir_inicio(&inicio,temp);
//    }
//
//    imprimir_lista(inicio);
//
//    printf("\n\n\n");

    //inserir_depois_de_no(temp, criar_novo_no(in));

//    for(int i=0;i<3;i++){
//        printf("Input: ");
//        scanf(" %c", &in);
//        inserir_depois_de_no(temp, criar_novo_no(in));
//    }

    //temp= pesquisa(inicio,'+');

    //printf("\n\n Encontri o node com %c", temp->valor);

//    do{
//
//        printf("Input: ");
//        scanf(" %c", &in);
//        temp=criar_novo_no(in);
//        inserir_inicio(&inicio,temp);
//
//    }while(in!='!');
#endif // 0

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

    //teste para passar valores de arrays
//    char array1[]= "Array1";
//    char array2 = array1;
//    printf("%s", array1);
//    printf("\n%s- mas 2", array1);
//
//    return 0;

    printf("Insira a equação em notação polaca: ");
    scanf("%m[^\n]", &eq_polaca );//le linha toda e aloca memoria dinamicamente


    //carregar o array eq_polaca[] para a lista

    //printf("array eq_polaca: %s", eq_polaca);
    token=strtok(eq_polaca," ");

    while(token!=NULL){
        printf("%s\n", token);
        char temp_val=token;
        temp=criar_novo_no(temp_val);
        inserir_inicio(&inicio,temp);
        token=strtok(NULL," ");
    }


    free(eq_polaca);//depois de carregado para a lista já podemos libertar a memoria


    imprimir_lista(inicio);



    return 0;
}

