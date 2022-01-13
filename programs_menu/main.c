#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define PI 3,14159265358979323846

void hello();
void soma();
void troca();
void mult();
void arith();
void metros();
void temperaturas();
void tamanho();
void ascii();
void area_c();
void area_q();
void area_r();
void areas ();
void dias();
void mash();
void length();

int main()
{

    setlocale(LC_ALL, "Portuguese");

    area_c();

    /*

    hello();
    printf("\n--------------------------------------------------\n");
    soma();
    printf("\n--------------------------------------------------\n");
    troca();
    printf("\n--------------------------------------------------\n");
    mash();
    printf("\n--------------------------------------------------\n");
    length();
    printf("\n--------------------------------------------------\n");
    temperaturas();
    printf("\n--------------------------------------------------\n");

    */


    /*


        int opt=1 ;
        while(opt != 0) {
            system("clear");
            system("cls");
            printf("MAIN MENU \n\n");
            printf("### Escolha a função que quer executar introduzindo o numero indicado antes do nome da mesma.\n\n");
            printf("1 - Hello\n");
            printf("2 - Soma\n");
            printf("3 - Trocar Valores\n");
            printf("4 - Multiplicação\n");
            printf("5 - Operações Aritmeticas\n");
            printf("6 - Pes -> Metros\n");
            printf("9 - Tamanhos de tipos\n");
            printf("10 - Conversor ASCII\n");
            printf("12 - Area Quadrado\n");
            printf("13 - Area Retangulo\n");
            printf("14 - Conversor Dias\n");
            printf("0 - Sair");
            printf("\n\nOpção pretendida:");
            scanf("%d", &opt);
            system("clear");
            system("cls");

            switch (opt) {

               case 1:
                    hello ();
                    break;
               case 2:
                    soma ();
                    break;
               case 3:
                    swap();
                    break;
               case 4:
                    mult ();
                    break;
               case 5:
                    arith ();
                    break;
               case 6:
                    metros ();
                    break;
                case 9:
                    tamanho ();
                    break;
                case 10:
                    ascii();
                    break;
                case 12:
                    area_q();
                    break;
                case 13:
                    area_r();
                    break;
                case 14:
                    dias();
                    break;
                case 0:
                    exit ();
                    break;
                default: printf("\nEssa opção não existe");
                }
                getchar();
                getchar();
    }


    */

    return 0;
}

//Basic C programs

void hello() {
    printf("\nOlá Mundo !");
    printf("\n");
    printf("\nTodos as funções presentes neste programa encontam se disponiveís em https://techstudy.org/clanguage/c-programming-example-and-solutions/ para consulta e analize.\n");
}


void soma() {
    int a, b;
    printf("\nEsta função soma dois números inteiros\n");
    printf("\nInsira um número:");
    scanf("%d", &a);
    printf("Insira outro número:");
    scanf("%d", &b);
    printf("\nA soma de ambos os números é = %d\n", a+b);
}

void troca() {
    int nr1, nr2, tmp;
    printf("\nEsta função troca os valores de dois números inteiros.\n");
    printf("\nInsira o valor para o numero 1:");
    scanf("%d", &nr1);
    printf("Insira o valor para o número 2:");
    scanf("%d", &nr2);

    printf("*troca*");
    tmp=nr1;
    nr1=nr2;
    nr2=tmp;
    printf("\nAgora o valor do número 1 é = %d e o valor do número 2 é = %d\n", nr1, nr2);


}

void mult () {

    double num1, num2, total;
    printf("Esta função multiplica numeros com casas decimais.\n\n");
    printf("Insira dois numeros: ");
    scanf("%lf %lf", &num1, &num2);
    total = num1 * num2;
    printf("Resultado = %.2lf", total);

}

void arith () {

    printf("Esta função gera diverças operações aritmeticas \n\n");
    int num1, num2;
    int sum, sub, mult, mod;
    float div;
    printf("Insira o primeiro numero : ");
    scanf("%d", &num1);
    printf("Insira o segundo numero : ");
    scanf("%d", &num2);
    sum = num1 + num2;
    sub = num1 - num2;
    mult = num1 * num2;
    mod = num1 % num2;
    div = (float)num1 / num2;
    printf("Soma of num1 and num2 = %d \n", sum);
    printf("Differença de num1 and num2 = %d \n", sub);
    printf("Produto de num1 and num2 = %d \n", mult);
    printf("Resto de num1 and num2 = %d \n", mod);
    printf("Quociente de num1 and num2 = %f ", div);

}


void metros () {

    printf("Esta função realiza a conversão de pes para metros\n\n");
    float meter,feet;
    printf("Insira valor em pes : ");
    scanf("%f",&feet);
    meter = feet / 3.2808399;
    printf("metros: %f",meter);

}

void temperaturas () {
    int op;
    float c,f;
    printf("Esta função converte a temperaturara em Celcius e Farenheit. \n");
    JUMPER:
    printf("\nPertende converter:\n");
    printf("1- De Celcius para Farenheit.\n");
    printf("2- De Farenheit.\n");
    do {
        printf("\nOpção: ");
        scanf("%d", &op);
        if (op == 1) {
            printf("\nIntroduza a temperatura em Celcius: ");
            scanf("%f", &c);
            f = (1.8 * c) + 32;
            printf("A sua temperatura em Farenheit é %.2lfº", f);
        }
        else if (op == 2) {
            printf("\nIntroduza a temperatura em Farenheit: ");
            scanf("%f", &f);
            c = (f - 32) * 5 / 9;
            printf("\nA sua temperatura em Farenheit é %.2lfº\n", c);
        }
        else if (op == 0){
            goto JUMPER;
        }
        else {
            printf("\nOpção invalida!\n");
            printf("Escolha uma das opções digitando o número correspondente a operação pretendida\n");
            printf("(introduza 0 para ver novamente as opções)\n\n");
        }
    } while( op!=1 && op !=2);
}


void tamanho () {

    char charType;
    short shortType;
    int intType;
    long longType;
    float floatType;
    double doubleType;
    printf("Esta função apresenta od tamanhos de diferentes tipos de dados.\n\n");
    printf("Tamanho de char: %ld byte\n",sizeof(charType));
    printf("Tamanho de Short: %ld bytes\n",sizeof(shortType));
    printf("Tamanho de int: %ld bytes\n",sizeof(intType));
     printf("Tamanho de ong: %ld bytes\n",sizeof(longType));
    printf("Tamanho de float: %ld bytes\n",sizeof(floatType));
    printf("Tamanho de double: %ld bytes\n",sizeof(doubleType));

}

void ascii() {

    char c;
    printf("Esta função converte carateres para o seu valor corespondente em ASCII. \n\n");
    printf("Insira um carater: ");
    scanf("%c", &c);
    printf("Valor ASCII de %c = %d", c, c);

}

void area_c() {
    float raio, area;
    printf("Esta função calcula a área de um quadrado.\n\n");
    printf("Insira o comprimento do raio : ");
    scanf("%lf", &raio);
    area = PI * raio * raio;
    printf("\Area do círculo é : %.3lf", area);
}

void area_q() {

   int side, area;
   printf("Esta função calcula a área de um quadrado.\n\n");
   printf("Insira o comprimento de um dos lados : ");
   scanf("%d", &side);
   area = side * side;
   printf("\nÁrea do quadrado : %d", area);

}

void area_r() {

   int length, breadth, area;
   printf("Esta função calcula a area de um retângulo. \n\n");
   printf("Insira o comprimento do retângulo : ");
   scanf("%d", &length);
   printf("\nInsira a largura do retângulo : ");
   scanf("%d", &breadth);
   area = length * breadth;
   printf("\nArea do retângulo : %d", area);

}

void dias() {

    int days, years, weeks;
    printf("Esta função converte um dado numero de dias em semanas e anos. \n\n");
    printf("Insira dias: ");
    scanf("%d", &days);
    years = (days / 365);
    weeks = (days % 365) / 7;
    days  = days - ((years * 365) + (weeks * 7));
    printf("Anos: %d\n", years);
    printf("Semanas: %d\n", weeks);
    printf("Dias: %d", days);
}

void mash() {
    char str1[50], str2[50];
    printf("\nEsta funação agrega duas palavras diferentes numa.\n\n");
    printf("Insira a primeira palavra:");
    gets(str1);
    printf("Insira a segunda palavra:");
    gets(str2);
    strcat(str1,str2);
    printf("Palavra agregada: %s\n", str1);

}

void length() {
    char str[100];
    int nr_letras;
    printf("\nEsta função mede o comprimento do seu nome.\n");
    printf("\nInsira o seu nome:");
    gets(str);
    nr_letras = strlen(str);
    for (int i=0; i<strlen(str); i++) {
        if (str[i]==' '){
            nr_letras = nr_letras-1;
        }
    }
    printf("O número de letras no seu nome é %d", nr_letras);


}

