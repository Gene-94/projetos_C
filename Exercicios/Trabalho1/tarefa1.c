#include <stdio.h>
#include <stdlib.h>

/*
 * Pesquisa em array de inteiros
 *
 * Parâmetros:
 *   - int elementos, array a pesquisar
 *   - int pesquisa, valor a pesquisar no array
 *   - int total_de_numeros, numero de elemntos no array
 *
 * retorna:
 *   - um valo inteiro >=0 se encontrar o valor pesquisado no array.
 *   - -1 caso não encontre o valor pesquisado no array
 */
int pesquisar(int *elementos, float pesquisa, int total_de_numeros){
    for (int i = 0; i < total_de_numeros; i++) {
        if (pesquisa == elementos[i])
            return i;
    }
    return -1;
}

int main(){
    int total_de_numeros, n;

    printf("Quantos elementos? ");
    scanf("%d", &total_de_numeros);

    int *numeros = (int *) malloc(total_de_numeros * sizeof(int));

    printf("Insira os numeros: ");
    for (int i = 0; i < total_de_numeros; i++) {
        scanf("%d", numeros + i);
    }

    printf("Procurar: ");
    scanf("%d", &n);

    int posicao = pesquisar(numeros, n, total_de_numeros);

    if ( posicao != -1)
        printf("Numero encontrado na posicao %d", posicao);
    else
        printf("Numero nao encontrado");

    // liberta memoria alocada para guardar os numeros
    free(numeros);

    return 0;
}

