#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    START:
    printf("Introduza um número de 0 a 5:");
    scanf("%d", &num);
    switch (num) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("A sua opção é %d", num);
            break;
        case 0:
            printf("\nAdeusinho");
            break;
        default:
            printf("\nOpção invalida\n\n");
            goto START;

    }
    return 0;
}
