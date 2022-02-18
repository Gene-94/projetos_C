#include <stdio.h>
#include <locale.h>

int main()
{
    int num1, num2;
    int *p1, *p2;

    printf("insira um número inteiro : ");
    scanf("%d", &num1);
    printf("Insira outro número inteiro : ");
    scanf("%d", &num2);

    p1=&num1;
    p2=&num2;

    printf("A soma do primeiro número inserido com o segundo número é %d", *p1+*p2);
    printf("\nEndresso de ponteiro 1: %p", p1);
    printf("\nEndresso de ponteiro 1: %p", p2);


    return 0;
}


