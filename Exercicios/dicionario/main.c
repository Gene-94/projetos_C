#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


struct info{
  int telefone;
  char nome[255];
  char morada[2000];
};

int funcao_hash(int chave, int dimensao_tabela){
  int ha = chave%dimensao_tabela;
  return ha;
}

void ler_ficheiro(struct info *tabela, int dimensao_tabela){
  FILE *fptr;
  int chave;
  int indice;
  char buffer[2500];
  char *token = NULL;
  char split[2] = ";";

  fptr = fopen("tabela.txt", "r");

  if(fptr != NULL){
    while(fgets(buffer, 2500, fptr) != NULL){
      token = strtok(buffer, split);
      chave = atoi(token); //strofi()

      // calcular o indice utilizando a funcao_hash
      indice = funcao_hash(chave, dimensao_tabela);//a cada linha cria um indice novo e armazena os dados no struct correspondente a esse indice

      tabela[indice].telefone = chave;

      token = strtok(NULL, split);
      // copiar para a tabela[i].nome o token com o nome (utilizar strcpy())
      strcpy(tabela[indice].nome, token);


      token = strtok(NULL, split);
      // copiar para a tabela[i].morada o token com a morada (utilizar strcpy())
      strcpy(tabela[indice].morada, token);
    }
  }

  fclose(fptr);
}

// criar procedimento que recebe um struct info e imprime o seu conteudo: "Indice: %d\nTelefone: %d\nNome: %s\nMorada: %s\n\n"
// identificar no programa onde se utilizar o mesmo formato de string e utilizar o procedimento imprime_info(...)
void imprime_info(struct info *tabela, int indice){
    printf("Indice: %d\nTelefone: %d\nNome: %s\nMorada: %s\n\n",indice ,tabela[indice].telefone,tabela[indice].nome,tabela[indice].morada);
}

void imprimir_tabela(struct info *tabela, int dimensao_tabela){
  for(int i= 0; i < dimensao_tabela; i++ ){
    // imprimir se o telefone na entrada da tabela posicao i for diferente de 0
    if(tabela[i].telefone!=NULL){
      imprime_info(tabela,i);
    }
  }
}

void pesquisar_morada_por(int chave, struct info *tabela, int dimensao_tabela){
  int indice = funcao_hash(chave, dimensao_tabela);

  if(tabela[indice].telefone != 0){
    imprime_info(tabela,indice);
  }else{
    printf("Nao foi encontrada morada para o numero de telefone %d\n", chave);
  }
}

int main(void) {
  int dim_tabela = 200;
  struct info tabela[dim_tabela] ;//por alguma razão ao ser criado, tabela[199] é populada com o valor 32767
  int telefone=-1;


  memset(tabela,0,sizeof(struct info) * dim_tabela);


  ler_ficheiro(tabela, dim_tabela);

  while(telefone != 0){
    printf("Insira o numero de telefone a pesquisar (0 para sair): ");
    // ler numero inteiro do teclado
    scanf("%d", &telefone);

    // imprimir apenas se o telefone for um numero maior que 0
    if(telefone > 0){
      pesquisar_morada_por(telefone, tabela, dim_tabela);
    }
  }

  // imprimir a tabela a saida
  imprimir_tabela(tabela, dim_tabela);

  return 0;
}

//   Nota/opcional/bonus: a implementacao da funcao de hashing é simples e pode gerar duplicação de chaves para numeros de telefone diferentes.
// tente resolver este problema alterando o código de modo a utilizar listas simplesmente ligadas. Cada lista pode ter dimensao N, portanto guardar até N struct info, cada um preenchido com um telefone, nome e morada diferentes.
