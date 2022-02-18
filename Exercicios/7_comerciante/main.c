#include <stdio.h>
#include <stdlib.h>

int main()
{
    float preco, custo, lucro;

    printf("Introduza o preço de custo do produto:");
    scanf("%f", &custo);

    if (custo < 5.5 && custo > 0) {
        lucro=custo*0.45;
        preco=lucro+custo;
        printf("\nPreço recomendado para produto é de %.2lf€, sendo que a percentagem de lucro será de 45%, o que equivale a %.2lf€ de margem, tendo em conta que o produto é adquirido a um valor nominal de %.2lf€\n", preco, lucro, custo);
    }
    else if (custo >= 5.5) {
        lucro=custo*0.3;
        preco=lucro+custo;
        printf("\nPreço recomendado para produto é de %.2lf€, sendo que a percentagem de lucro será de 30%, o que equivale a %.2lf€ de margem, tendo em conta que o produto é adquirido a um valor nominal de %.2lf€\n", preco, lucro, custo);
    }
    else {printf("\nValor de custo do produto invalido. O preço tem de tem um custo superior a 0 para poder ser calculada a margem de lucro.\n");}

    return 0;
}
