#include <stdio.h>
#include <stdlib.h>

typedef struct ponto_struct{
    char data;
    int nr;
}ponto;

typedef struct no {
    char data;
    int nr;
}no;

int main()
{
    char *nome;

    printf("Isira o seu nome: ");
    scanf("%s", nome);

    //nome= "Yevheniy";

    printf("%s", nome);


    return 0;
}
