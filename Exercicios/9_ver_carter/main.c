#include <stdio.h>
#include <stdlib.h>
char ch;


int verifica_tamanho_da_letra()
{
    if (ch >= 65 && ch <= 90) {
        printf("a letra %c introduzida é maiúscula\n\n", ch);
        return 1;
    }
    else {
        printf("a letra %c introduzida é minúscula\n\n", ch);
        return 0;
    }


}


int main()
{
    printf("Validação de carateres. ('!' ira terminar a leitura)\n\n");
    do {
        printf("Insira uma letra:");
        scanf(" %c", &ch);
        if ((ch >= 65 && ch <= 90)||(ch>=97 && ch<=122) ) {

            verifica_tamanho_da_letra();

        }
        else{
            printf("Carater inválido\n\n");
        }

    }while (ch !=33);

    return 0;
}
