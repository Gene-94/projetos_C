#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1, x=0, y;

    while (i <= 150) {

        x= x+i;
        ++i;
    }

    printf("O total da soma dos 150 primeiros números inteiros é %d\n",x);

    //

    i=1;
    printf("\nLista de todos os números divisíveis por 5 e que sejam menores que 250.\n");
    while (i <= 250) {

        if ( i%5 == 0 ){
            printf("%d, ",i);
        }
       ++i;
    }

    //

    printf("\n\nintroduza valores a serem somados (0 ira terminar a leitura).\n");
    x=0;
    while (i != 0 ) {
        printf("Valor a somar:");
        scanf("%d", &i);
        x=x+i;

    }

    printf("Soma dos valores introduzidos: %d", x);


    //

    printf("\n\nintroduza valores a serem registados, no final irá ser apresentado o maior e o menor valor introduzido, (0 ira terminar a leitura).\n");
    x=0;
    y=0;
    i=1;
    while (i != 0 ) {
        printf("Valor:");
        scanf("%d", &i);

        if (i != 0) {
            if (i > x) {
                x = i;
                if (y ==0 ) {y=x;}
            }
            else if (i < y) {
                y = i;
                if (x ==0 ) {x=y;}
            }
        }
    }

    if ( x==0 || y==0) { printf("Não foram intruzidos valores, para além do 0 (valor que termina a leitura).\n");}
    else if (x==y) {printf("O único valor intoduzido foi o %d, sendo ele mesmo o maior e o menor.\n", x);}
    else {printf("O maior valor inserido foi %d e o menor valor inserido foi o %d .\n", x,y);}

    return 0;
}
