#include <stdio.h>
#include <stdlib.h>


int main()
{

    int idade;
    float preco_base=5.99 , preco_bilhete;
    printf("Para proceder ao pagamento deve introduzir a sua idade.\n\n");
    printf("(Ira ser aplicado um aplicado um desconto sobre o valor base de 5,99€.)\n\n");
    printf("Idade:");
    scanf("%d", &idade);

    if (idade <= 10) {

        preco_bilhete=preco_base * 0 ;
    }
    else if (11 <= idade && idade <= 17){

        preco_bilhete=preco_base * 0.5;
    }

     else if (18 <= idade && idade <= 64){

        preco_bilhete=preco_base;
    }

    else {

        preco_bilhete=preco_base * 0.6;
    }

    printf("\n\nO preço do seu bilhete é de %.2f€\n\n", preco_bilhete);

    printf("Obrigado.\n\n");

    return 0;
}
