#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//include ncurses here to acess the clear screen function

int main()
{
    char user[20 + 1], pass[20 + 1];
    char buffer[1024],db[16][3][21];
    int linhas=0, colunas=0;
    char *token;

    FILE *filepoint;

    filepoint = fopen("db.csv", "r");

    printf("   ########## LOGIN ##########\n\n");
    printf("Username:  (user)\b\b\b\b\b\b\b");
    scanf("%20s", user);
    printf("Password:  (pass)\b\b\b\b\b\b\b");
    scanf("%20s", pass);
    printf("\n\n");

    if(!filepoint){
        printf("Ocorreu um erro, não foi possivel conectar ao servidor de autenticação.\n\n");
        sleep(1);
        printf("A terminar...\n");
        sleep(1);
        return 0;
    }

//    strcpy(db[0][0],"palavra");
//    printf("%s\n",db[0][0]);
//    printf("%c\n",db[0][0][0]);
//    printf("%s",db[0]);
//
    int i=0,j=0;
    while(fgets(buffer, 1024, filepoint)){

        token = strtok(buffer, ";");
        while(token!=NULL){
            strcpy(db[j][i],token);
            token=strtok(NULL,";");
            printf("\n%s", db[j][i]);
            i++;
        }
        j++;


        //printf("%s - %s",token,user);

//        if(token=="user"){
//            continue;
//        }
//        (token==user)?printf("SUCEsso"):printf("ERRO!");
//        getchar();
//        getchar();
//        while(token != NULL){
//            if(token==user){
//                printf("Utilizador, Sucesso!");
//                token= strtok(NULL, ";");
//                if(token==pass){
//                    printf("Utilizador autenticado com sucesso !\n\n");
//                    token= strtok(NULL, ";");
//                    printf("\n\tBem Vindo %s", token);
//                }
//            }
//            else{token=NULL;}
//
//        }
    }
    printf("-----------------------\n");
    printf("%s\n", db[0][0]);
    printf("%s\n", db[0][1]);
    printf("%s\n", db[0][2]);
    printf("-----------------------\n");
    printf("%s\n", db[1][0]);
    printf("%s\n", db[1][1]);
    printf("%s\n", db[1][2]);




    //printf("\t\tWelcome %s!\n", user);


    return 0;
}
