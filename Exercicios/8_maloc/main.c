#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nr_val,sum=0 , *valores;

    printf("Quantos valores ira introduzir? ");
    scanf("%d", &nr_val);
    valores = (int *)calloc(nr_val,sizeof(int));
    printf("introduza os %d numeros inteiros\n", nr_val);
    for(int i=0; i<nr_val;i++){
        printf("introduza o valor #%d: ",i+1);
        scanf("%d", &valores[i]);
        sum=sum+valores[i];
    }

    printf("Sum: %d\n",sum);
    printf("Valores introduzidos:");
    for(int i=0;i<nr_val;i++){
        printf(" %d", valores[i]);
    }


    return 0;
}
