#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int nasc_ano, ano_corr;


    printf("\nInsira a seu ano de nascimento:");
    scanf("%d", &nasc_ano);
    printf("\n\nInsira o ano corrente:");
    scanf("%d", &ano_corr);

    printf("\nA sua idade este ano é %d\n\n", ano_corr-nasc_ano);



    //### Obter data automaticamente do computador, pedir a data de nascimento ao utilizador e calcular idade com base no input
//
//    time_t data_local;
//    time(&data_local);
//    printf(ctime(&data_local));

//    double difftime(time_t time1, time_t time2)


    return 0;
}
