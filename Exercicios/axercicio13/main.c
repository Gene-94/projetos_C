#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    float resultado=0;

    switch(argv[1][0]){
        case '+':
            for(int i=2;i<argc;i++){
                resultado += atoi(argv[i]);
            }
            break;
        case '-':
            resultado = atoi(argv[2]);
            for(int i=3;i<argc;i++){
                resultado = resultado-atoi(argv[i]);
            }
            break;
        case ':':
        case '/':
            resultado = atoi(argv[2]);
            for(int i=3;i<argc;i++){
                resultado = resultado/atoi(argv[i]);
            }
            break;
        case 'x':
        case 'X':
        case '*':
            resultado = atoi(argv[2]);
            for(int i=3;i<argc;i++){
                resultado = resultado*atoi(argv[i]);
            }
            break;
        default:
            printf("Operador invalido.");
            return 1;
    }
    printf("Resultado = %.3f", resultado);

    return 0;
}
