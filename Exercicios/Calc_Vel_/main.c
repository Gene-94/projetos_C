#include <stdio.h>
#include <stdlib.h>

int main()
{

    int duration;
    float km, fuel, preco_comb, vel_med, consumo, gasto_med, gasto;
    printf("Calculo do custo de viagem.\n\n");
    printf("Insira o tempo de duração da viagem (em minutos): ");
    scanf("%d", &duration);
    printf("Insira a quantidade de quilómetros percorridos: ");
    scanf("%f", &km);
    printf("Quantidade de combustivel gasto (em litros): ");
    scanf("%f", &fuel);
    printf("Preço do litro de combustivel a data da viagem: ");
    scanf("%f", &preco_comb);

    vel_med = km / duration;
    printf("\n\nA viagem foi realizada a uma velocidade mdia de %lf km/minuto. ", vel_med);

    consumo = fuel / (km/100);
    printf("\nDurante a viagem deu-se um consumo medio de %.3lf litros por cada 100km. ", consumo);

    gasto_med = consumo * preco_comb;
    printf("\nO gasto medio por cada 100km foi de %.2lf€ .", gasto_med);

    gasto = preco_comb * fuel;
    printf("\nE o gasto total da viagem foi de %.2lf€ .", gasto);

    return 0;
}
