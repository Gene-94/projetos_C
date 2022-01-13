#include <stdio.h>
#include <stdlib.h>


void intro ()
{
    char galo[3][3] = {'_','_','_','_','_','_',' ',' ',' '};
    int k=1;
    printf("Bem vindo ao jogo do galo!\n\n");
    printf("Para jogar digite um numero de 1 a 9 para marcar a X na respectiva casa.\n");
    printf("Mapeamento da numeração correspondente as casa:\n");

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            galo[i][j] = k ;
            k++;
        }
    }
    printf("\t_%d_|_%d_|_%d_\n", galo[0][0],galo[0][1],galo[0][2]);
    printf("\t_%d_|_%d_|_%d_\n",galo[1][0],galo[1][1],galo[1][2]);
    printf("\t %d | %d | %d \n",galo[2][0],galo[2][1],galo[2][2]);

    printf("\n\n");





}

int main ()
{
    static char galo[3][3] = {'_','_','_','_','_','_',' ',' ',' '};
    int jogada, maquina;

    srand(time(NULL));

    intro();

    while (1) {
        printf("Jogo atual: \n");
        printf("\t_%c_|_%c_|_%c_\n", galo[0][0],galo[0][1],galo[0][2]);
        printf("\t_%c_|_%c_|_%c_\n",galo[1][0],galo[1][1],galo[1][2]);
        printf("\t %c | %c | %c \n",galo[2][0],galo[2][1],galo[2][2]);
        if ((galo[0][0] == 'X' && galo[0][1] == 'X' && galo[0][2] == 'X') || (galo[1][0] == 'X' && galo[1][1] == 'X' && galo[1][2] == 'X') || (galo[2][0] == 'X' && galo[2][1] == 'X' && galo[2][2] == 'X') || (galo[0][0] == 'X' && galo[1][0] == 'X' && galo[2][0] == 'X') || (galo[0][1] == 'X' && galo[1][1] == 'X' && galo[2][1] == 'X') || (galo[0][2] == 'X' && galo[1][2] == 'X' && galo[2][2] == 'X') || (galo[0][0] == 'X' && galo[1][1] == 'X' && galo[2][2] == 'X') || (galo[0][2] == 'X' && galo[1][1] == 'X' && galo[2][0] == 'X')) {
            printf("PARABÈNS !!! Ganhou.");
            return 0;
        }
        else if ((galo[0][0] == 'O' && galo[0][1] == 'O' && galo[0][2] == 'O') || (galo[1][0] == 'O' && galo[1][1] == 'O' && galo[1][2] == 'O') || (galo[2][0] == 'O' && galo[2][1] == 'O' && galo[2][2] == 'O') || (galo[0][0] == 'O' && galo[1][0] == 'O' && galo[2][0] == 'O') || (galo[0][1] == 'O' && galo[1][1] == 'O' && galo[2][1] == 'O') || (galo[0][2] == 'O' && galo[1][2] == 'O' && galo[2][2] == 'O') || (galo[0][0] == 'O' && galo[1][1] == 'O' && galo[2][2] == 'O') || (galo[0][2] == 'O' && galo[1][1] == 'O' && galo[2][0] == 'O')) {
            printf("PERDEU ...");
            return 0;
        }

        HUMAN: ;
        printf("Jogada : ");
        scanf("%d", &jogada);
        //Jogada do utilizador
        switch (jogada) {
            case 1:
                if(galo[0][0] == 'X' || galo[0][0] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[0][0]);
                    goto HUMAN;
                }
                galo[0][0] = 'X';
                break;
            case 2:
                if(galo[0][1] == 'X' || galo[0][1] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[0][1]);
                    goto HUMAN;
                }
                galo[0][1] = 'X';
                break;
            case 3:
                if(galo[0][2] == 'X' || galo[0][2] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[0][2]);
                    goto HUMAN;
                }
                galo[0][2] = 'X';
                break;
            case 4:
                if(galo[1][0] == 'X' || galo[1][0] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[1][0]);
                    goto HUMAN;
                }
                galo[1][0] = 'X';
                break;
            case 5:
                if(galo[1][1] == 'X' || galo[1][1] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[1][1]);
                    goto HUMAN;
                }
                galo[1][1] = 'X';
                break;
            case 6:
                if(galo[1][2] == 'X' || galo[1][2] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[1][2]);
                    goto HUMAN;
                }
                galo[1][2] = 'X';
                break;
            case 7:
                if(galo[2][0] == 'X' || galo[2][0] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[2][0]);
                    goto HUMAN;
                }
                galo[2][0] = 'X';
                break;
            case 8:
                if(galo[2][1] == 'X' || galo[2][1] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[2][1]);
                    goto HUMAN;
                }
                galo[2][1] = 'X';
                break;
            case 9:
                if(galo[2][2] == 'X' || galo[2][2] == 'O') {
                    printf("Essa casa já tem um %C, escolha outra casa.\n\n", galo[2][2]);
                    goto HUMAN;
                }
                galo[2][2] = 'X';
                break;
            default:
                printf("Numero invalido, insira um número de 1 a 9.\n\n");
                goto HUMAN;
        }

        //o utilizador é o utimo a jogar em caso de empate

        if (galo[0][0] != '_' && galo[0][1] != '_' && galo[0][2] != '_' && galo[1][0] != '_' && galo[1][1] != '_' && galo[1][2] != '_' && galo[2][0] != ' ' && galo[2][1] != ' ' && galo[2][2] != ' ' ) {
            printf("Jogo atual: \n");
            printf("\t_%c_|_%c_|_%c_\n", galo[0][0],galo[0][1],galo[0][2]);
            printf("\t_%c_|_%c_|_%c_\n",galo[1][0],galo[1][1],galo[1][2]);
            printf("\t %c | %c | %c \n",galo[2][0],galo[2][1],galo[2][2]);
            // Serve para mostrar o resultado final sem voltar a entrar no loop
            printf("\nEmpate !");
            return 0;
        }

        // Jogada da maquina

//        maquina = rand()%10;
//        if (maquina == 0) {
//            maquina = 1;
//        }
//          a probabilidade de sair 1 seria maior

        MAQ: ;

        do {
            maquina = rand()%10;
        }while (maquina==0);


        switch (maquina) {
            case 1:
                if(galo[0][0] == 'X' || galo[0][0] == 'O'){
                    goto MAQ;
                }
                galo[0][0] = 'O';
                break;
            case 2:
                if(galo[0][1] == 'X' || galo[0][1] == 'O'){
                    goto MAQ;
                }
                galo[0][1] = 'O';
                break;
            case 3:
                if(galo[0][2] == 'X' || galo[0][2] == 'O'){
                    goto MAQ;
                }
                galo[0][2] = 'O';
                break;
            case 4:
                if(galo[1][0] == 'X' || galo[1][0] == 'O'){
                    goto MAQ;
                }
                galo[1][0] = 'O';
                break;
            case 5:
                if(galo[1][1] == 'X' || galo[1][1] == 'O'){
                    goto MAQ;
                }
                galo[1][1] = 'O';
                break;
            case 6:
                if(galo[1][2] == 'X' || galo[1][2] == 'O'){
                    goto MAQ;
                }
                galo[1][2] = 'O';
                break;
            case 7:
                if(galo[2][0] == 'X' || galo[2][0] == 'O'){
                    goto MAQ;
                }
                galo[2][0] = 'O';
                break;
            case 8:
                if(galo[2][1] == 'X' || galo[2][1] == 'O'){
                    goto MAQ;
                }
                galo[2][1] = 'O';
                break;
            case 9:
                if(galo[2][2] == 'X' || galo[2][2] == 'O'){
                    goto MAQ;
                }
                galo[2][2] = 'O';
                break;
        }

    }
return 0;
}
