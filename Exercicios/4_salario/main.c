#include <stdio.h>
#include <stdlib.h>

int main()
{
    float val_hora, nr_horas,seg_soc, sal_iliq, sal_liq, desc;
    printf("Calculo salárial. Insira os seguintes valores:\n\n");
    printf("Numero de horas tabalhada ao longo do mês: ");
    scanf("%f", &nr_horas);
    printf("\nValor recebido por hora: ");
    scanf("%f", &val_hora);
    printf("\nPercentagem de desconto de impostos e segurança social (0-100): ");
    scanf("%f", &seg_soc);



    if (seg_soc >= 0 && seg_soc <= 100) {

        seg_soc = seg_soc / 100;
    }

    else {
        printf("Erro. Insira uma percentagem valida.");
        return 0;
    }


    sal_iliq = nr_horas*val_hora;
    desc=sal_iliq*seg_soc;
    sal_liq=sal_iliq-desc;

    printf("\n\nValor do salario iliquido: %.2lf€", sal_iliq);
    printf("\nValor descontado em impostos: %.2lf€", desc);
    printf("\nValor do salario liquido: %.2lf€", sal_liq);


    return 0;
}
