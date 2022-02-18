#include <stdio.h>
#include <stdlib.h>

int main()
{

    double numero;
    printf("Esta função lê um número e calcula a sua potência de 5 (x^5 )\n");
    printf("\nInsira um número:");
    scanf("%lf", &numero);
    printf("\n\nResultado: %lf", pow(numero, 5));


    return 0;
}
