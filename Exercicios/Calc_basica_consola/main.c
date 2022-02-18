#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int resultado=0;
    int num1, num2;

    num1= atoi(argv[1]);
    num2= atoi(argv[3]);

    switch(argv[2][0]){
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case ':':
        case '/':
            resultado = num1 / num2;
            break;
        case 'x':
        case '*':
            resultado = num1 * num2;
            break;
        default :
            printf("Operador invalido.");
            return 1;

    }

    printf("O resultado é %d", resultado);


    return 0;
}
