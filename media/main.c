#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float val, total=0;

    int i=0;

    char sn;

    printf("Este programa calcula a a media dos valores inseridos. Insira o valor 0 para terminar a leitura de valores.\n\n");
    do {
        printf("Valor %d : ", i+1);
        scanf("%f", &val);
        total = total + val;
        i++;

        /*
        //Confirmar se o 0 é um valor a ser considerado na media ou é para ser usado como carater de escape

        if (val == 0) {
            JUMP: ;
            printf("Deseja sair ou considerar o 0 como valor de entrada?\n");
            printf("Sair?(S/N) : ");
            scanf("%c", sn);
            if (sn == 'N' || sn == 'n') {
                continue;
            }
            else if (sn == 'Y' || sn == 'n') {

            }
            else {
                printf("Por favor responda digitando um S ou um N.\n\n");
                goto JUMP;
            }
        }

        //por alguma razão o sn é assumido como integer e obtenho um segmentation fault

        */
    }while (val!=0);
    i--;
    total= total/i;
    printf("\nA media dos valores inseridos é %.3lf.", total);

    return 0;
}
