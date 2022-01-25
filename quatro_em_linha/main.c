#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// No Windows trocar as declarações de limpeza de ecrâ
#define CLEAR_SCREEN system("clear") //system("cls");
#define I 7
#define J 8
#define PRIMEIRA 1

char base[I][J], nome1[50], nome2[50];
int brains=0, empate=0;

void intro () {
    printf("\nBem vindo ao QUATRO EM LINHA !!!\n\n");
    printf("Insira o seu nome de jogador: ");
    scanf("%50s", nome1);
    printf("\nNeste jogo escolhe uma coluna onde deixar cair a sua peça, caindo do topo da coluna escolhida ela irá ocupar a ultima casa disponivel.\n");
    printf("\nGanha o preimeiro a conseguir colocar quatro das suas peças em linha (tanto na vertical, horizontal, como nas diagonais).\n\n");
    printf("Fichas do Jogador 1 - O\n");
    printf("Fichas do Jogador 2 - X\n");


    //Escolha de jogo, a dois ou solo
    printf("\n%s, pretende jogar contra:\n", nome1);
    printf("1 - Humano\t\t");
    printf("2 - Computador\n\n");
    do {
        printf("Opção: ");
        scanf("%d", &brains);
        if (brains == 1 ){
            printf("\nInsira o nome do Jogador 2: ");
            scanf("%50s", nome2);
        }
        else if (brains == 2) {
            strcpy(nome2, "Skynet");
        }
        else {
            printf("\nInsira uma opção valida! \n\n");
        }
    }while (brains != 1 && brains != 2);

    printf("\nJogador 1 é %s\n", nome1);
    printf("E o Jogador 2 é %s\n\n", nome2);
    printf("(prima enter para começar)");
    getchar();
    getchar();
    CLEAR_SCREEN;
}

void reset_tabuleiro (){
    //pupular o array com espaços em branco para preparar o jogo
    for(int i=PRIMEIRA; i<I; i++) {
        for(int j=PRIMEIRA; j<J; j++) {
            base[i][j] = ' ';
        }
    }
    //Labels
    for(int j=0; j<J; j++ ) {
        base[0][j] = j;
    }
    for(int i=0; i<I; i++ ) {
        base[i][0] = ' ';
    }
}

//void imprime (){
// //impressão do "tabuleiro"
// // função descontinuada em prol de imprime_numerado()
//    for(int i=PRIMEIRA; i<I; i++) {
//        for(int j=PRIMEIRA; j<J; j++) {
//            printf("[%c]", base[i][j]);
//        }
//        printf("\n");
//    }
//}

void imprime_numerado () {

    CLEAR_SCREEN;
    printf("Para jogar insira o número da coluna onde pretende largar a peça.\n\n");
    for(int i=0; i<I; i++) {
        for(int j=0; j<J; j++) {
            if(j==0 && i==0) {
                printf("  ");
            }
            else if (j==0){
                printf("%C ", base[i][j]);
            }
            else if (i==0){
                printf(" %d ", base[i][j]);
            }
            else {
                printf("[%c]", base[i][j]);
            }

        }
        printf("\n");
    }
}

void jogador_1 () {

    int p;

    printf("\nJogada de %s (O): ", nome1);
    scanf("%d", &p);

    if (p>0 && p<8) {

        for(int i=I-1; i>=0; i--){
            if(base[i][p]==' '){
                base[i][p]='O';
//                CLEAR_SCREEN;
//                imprime_numerado ();
                break;
            }
            else if (i == 0){
                printf("\nA coluna selecionada esta cheia, escolha outra coluna.");
                jogador_1();
            }
        }

    }
    else {
        printf("\nA jogada introduzida não é valida!");
        printf("\nPara jogar insira o número da coluna onde pretende largar a peça.\n");
        jogador_1();
    }


}

//subtituido pela função sleep()
//void delay(){
//    unsigned int segundos = 1;
//    while(segundos)
//     segundos = sleep(segundos);
//}

void jogador_2 () {

    int p;

    printf("\nJogada de %s (X): ", nome2);

    if (brains == 1 ){
        scanf("%d", &p);
    }
    else if (brains == 2 ){

        srand(time(NULL));
        do {
            p = rand()%8;
        }while (p==0);

        printf("%d", p);

        printf("\n");

        sleep(1);

    }


    if (p>0 && p<8) {

        for(int i=I-1; i>=0; i--){
            if(base[i][p]==' '){
                base[i][p]='X';
//                CLEAR_SCREEN;
//                imprime_numerado ();
                break;
            }
            else if (i == 0){
                printf("\nA coluna selecionada esta cheia, escolha outra coluna.");
                jogador_2();
            }
        }

    }
    else {
        printf("\nA jogada introduzida não é valida!");
        printf("\nPara jogar insira o número da coluna onde pretende largar a peça.\n");
        jogador_2();
    }


}



int teste () {
    int somatorio =0;

    // Testa na vertical
    for (int j=1; j<J; j++ ){
        for(int i=1; i<4; i++){
            if(base[i][j] == 'O' && base[i+1][j] == 'O' && base[i+2][j] == 'O' && base[i+3][j] == 'O'){
                printf("O %s ganhou !", nome1);
                return 0;
            }
            else if(base[i][j] == 'X' && base[i+1][j] == 'X' && base[i+2][j] == 'X' && base[i+3][j] == 'X'){
                printf("O %s ganhou !", nome2);
                return 0;
            }
        }
    }
    // Testa na horizontal
    for (int i=1; i<I; i++ ){
        for(int j=1; j<5; j++){
            if(base[i][j] == 'O' && base[i][j+1] == 'O' && base[i][j+2] == 'O' && base[i][j+3] == 'O'){
                printf("O %s ganhou !", nome1);
                return 0;
            }
            else if(base[i][j] == 'X' && base[i][j+1] == 'X' && base[i][j+2] == 'X' && base[i][j+3] == 'X'){
                printf("O %s ganhou !", nome2);
                return 0;
            }
        }
    }
    // Testa na diagonal -> \ como a barra
    for (int i=1; i<4; i++ ){
        for(int j=1; j<5; j++){
            if(base[i][j] == 'O' && base[i+1][j+1] == 'O' && base[i+2][j+2] == 'O' && base[i+3][j+3] == 'O'){
                printf("O %s ganhou !", nome1);
                return 0;
            }
            else if(base[i][j] == 'X' && base[i+1][j+1] == 'X' && base[i+2][j+2] == 'X' && base[i+3][j+3] == 'X'){
                printf("O %s ganhou !", nome2);
                return 0;
            }
        }
    }
    // Testa na diagonal -> /
    for (int i=1; i<4; i++ ){
        for(int j=1; j<5; j++){
            if(base[i+3][j] == 'O' && base[i+2][j+1] == 'O' && base[i+1][j+2] == 'O' && base[i][j+3] == 'O'){
                printf("O %s ganhou !", nome1);
                return 0;

            }
            else if(base[i+3][j] == 'X' && base[i+2][j+1] == 'X' && base[i+1][j+2] == 'X' && base[i][j+3] == 'X'){
                printf("O %s ganhou !", nome2);
                return 0;
            }
        }
    }
    //Testa empate
    for (int j=1; j<J; j++) {

        somatorio = somatorio+base[1][j];

        if(somatorio >= 553 && somatorio <= 616) {
            printf("Empate !! não restam mais espaços livres.");
            return 0;
        }
    }

    return 1;
}

int main()
{
    int op;

    intro () ;

    do {
        reset_tabuleiro();

        imprime_numerado ();

        do {

            jogador_1();

            imprime_numerado ();

            teste();
            if (teste() == 0 ){
                break;
            }

            jogador_2();

            imprime_numerado ();

            teste();
            if (teste() == 0 ){
                break;
            }

        }while(1);

        printf("\n\nQuer jogar novamente?\n");
        printf("1-Sim\t 2-Não\n");
        do {
            printf("Opção: ");
            scanf("%d", &op);
            if(op != 1 && op != 2){ printf("\nIsira uma opção valida (sim - 1 | não -2)");}
        }while(op != 1 && op != 2);

    }while(op != 2);


    return 0;
}
