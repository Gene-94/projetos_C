#include <stdio.h>
#include <stdlib.h>

long double c=0;

void oprt() {

printf("\n\n O resultado é %lf", c);

}


int main()
{
    long double a, b;
    char op;
    printf("Introduza dois numeros e escolha o operador.\n");
    printf("\nNumero 1:");
    scanf("%lf", &a);
    printf("\nNumero 2:");
    scanf("%lf", &b);
    printf("\nEcolha o operador (+ , - , : ou x):");
    scanf("%c", op);

    if (op == '+') {

        c=a+b;
        oprt();

    }

    else if (op=="-"){

        c=a-b;
        oprt();
    }

    else if ((op=="x") || (op=="X") || (op=="*") ){

        c=a*b;
        oprt();
    }

    else if ((op==":") || (op=="/")){

        c=a/b;
        oprt();
    }


    else {

        printf("\nOperador inserido invalido");
    }

    return 0;
}
