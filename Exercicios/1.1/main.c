#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OPERADORES

typedef struct num {
    int numero;
    struct num *proximo;
}num;

typedef struct op {
    char operador;
    struct op *proximo;
}op;

void criar_no() {

}

int main (int argc, char *argv[]) {



    for (int i=1; i<argc; i++){
       if (argv[i]== /*a um dos operadores*/)
    }

    return 0 ;

}
