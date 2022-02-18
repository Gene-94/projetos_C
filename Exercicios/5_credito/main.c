#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salario, emprestimo, mensalidade;
    int meses;

    printf("Pre-aprovação de crédito.\n\n");
    printf("Insira os seguintes valores\n");
    printf("Rendimento mensal: ");
    scanf("%f", &salario);
    printf("Emprestimo pretendido: ");
    scanf("%f", &emprestimo);
    printf("Númeor de meses para o empréstimo: ");
    scanf("%d", &meses);

    mensalidade = (emprestimo*0.15 + emprestimo) / meses;


    printf("\nA sua mensalidade terá um valor de %.2lf€", mensalidade);

    if (mensalidade > salario*0.20) {

        printf("\n\nCrédito recusado.\n\n");
    }
    else {

        printf("\n\nCrédito aprovado.\n\n");
    }

    return 0;
}
