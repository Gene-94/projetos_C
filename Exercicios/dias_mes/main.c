#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char meses [][10] = { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "julho", "Agosto", "Setembro", "Outubro", "November","Dezember"};


    for (i=0; i < 12; i++) {
        printf("\nEm %s o número de dias é %d.", meses+i, dias[i]);
    }

    return 0;
}
