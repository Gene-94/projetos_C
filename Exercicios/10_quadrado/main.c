#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char op;

int quadrado (float x,float y,float z) {

    printf("\nO resultado para a opção escolhida (%c) é %lf .\n\n", op, pow(x,2)+y+z);
    return 0;
}


int main()
{
    float val1, val2, val3;

    do {

        printf("Insira três valores.\n");
        printf("Valor 1:");
        scanf("%f", &val1);
        printf("Valor 2:");
        scanf("%f", &val2);
        printf("Valor 3:");
        scanf("%f", &val3);

        printf("\nEscolha uma das seguintes opções.");
        printf("\nA – calcular o quadrado do primeiro valor, somado aos outros dois valores");
        printf("\nB – calcular o quadrado do segundo valor, somado aos outros dois valores");
        printf("\nC – calcular o quadrado do terceiro valor, somado aos outros dois valores");
        printf("\nS – sair do programa");
        printf("\n\nopção:");
        scanf(" %c", &op);

        switch(op) {
            case 'A':
            case 'a':
                quadrado(val1,val2,val3);
                break;
            case 'B':
            case 'b':
                quadrado(val2,val1,val3);
                break;
            case 'C':
            case 'c':
                quadrado(val3,val2,val1);
                break;
            case 'S':
            case 's':
                //empty - exiting
                return 0;
                break;
            default:
                printf("\nOpção invalida\n\n");
        }

        printf("\n--------------------------------------\n\n\n");

    }while(op!='s' || op!="S");
    return 0;
}




