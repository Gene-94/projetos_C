#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char frase [] = "O rat0 r0eu a r0lha da garrafa d0 Rei da Russia";

    printf("O array defenido é \"%s\".\n", frase);
    printf("O tamanho do array é de %d", strlen(frase));



    for (int i=0; i<strlen(frase);i++) {
        if (frase[i] == '0') {
            frase[i] = 'o';
        }
    }
    printf("\n\nforam substituidos os '0' e inseridos 'o' em seu lugar.\n");
    printf("novo array: %s\n", frase);

    for (int i=0; i<strlen(frase);i++) {
        if (frase[i] >= 'a' && frase[i] <= 'z') {
            frase[i] = frase[i]-32;
        }
    }
    printf("\nForam substituidas todas as letras do array por maiusculas.\n");
    printf("novo array: %s\n", frase);



    return 0;
}
