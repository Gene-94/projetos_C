#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int _completar(){
  printf("Completar\n");
  return 0;
}

struct info{
  int telefone;
  char nome[255];
  char morada[2000];
};

int funcao_hash(int chave, int dimensao_tabela){
  return _completar();
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
      chave = atoi(token);

      // calcular o indica utilizando a funcao_hash
      indice = _completar();

      tabela[indice].telefone = chave;

      token = strtok(NULL, split);
      // copiar para a tabela[i].nome o token com o nome (utilizar strcpy())
      _completar();

      token = strtok(NULL, split);
      // copiar para a tabela[i].morada o token com a morada (utilizar strcpy())
      _completar();
    }
  }
  
  fclose(fptr);
}

// criar procedimento que recebe um struct info e imprime o seu conteudo: "Indice: %d\nTelefone: %d\nNome: %s\nMorada: %s\n\n"
// identificar no programa onde se utilizar o mesmo formato de string e utilizar o procedimento imprime_info(...)
void imprime_info(struct info informacao){
  _completar();
}

void imprimir_tabela(struct info *tabela, int dimensao_tabela){
  for(int i= 0; i < dimensao_tabela; i++ ){
    // imprimir se o telefone na entrada da tabela posicao i for diferente de 0
    if(_completar()){
      printf("Indice: %d\nTelefone: %d\nNome: %s\nMorada: %s\n\n", i, tabela[i].telefone, tabela[i].nome, tabela[i].morada);
    }
  }
}

void pesquisar_morada_por(int chave, struct info *tabela, int dimensao_tabela){
  int indice = funcao_hash(chave, dimensao_tabela);

  if(tabela[indice].telefone != 0){
    printf("Morada encontrada!\n Indice: %d\nTelefone: %d\nNome: %s\nMorada: %s\n\n", indice, tabela[indice].telefone, tabela[indice].nome, tabela[indice].morada);
  }else{
    printf("Nao foi encontrada morada para o numero de telefone %d\n", chave);
  }
}

int main(void) {
  int dim_tabela = 200;
  struct info tabela[dim_tabela];
  int telefone=-1;

  ler_ficheiro(tabela, dim_tabela);

  while(telefone != 0){
    printf("Insira o numero de telefone a pesquisar (0 para sair): ");
    // ler numero inteiro do teclado
    telefone = _completar();

    // imprimir apenas se o telefone for um numero maior que 0
    if(_completar()){
      pesquisar_morada_por(telefone, tabela, dim_tabela);
    }
  }

  // imprimir a tabela a saida
  _completar();

  return 0;
}

//   Nota/opcional/bonus: a implementacao da funcao de hashing é simples e pode gerar duplicação de chaves para numeros de telefone diferentes.
// tente resolver este problema alterando o código de modo a utilizar listas simplesmente ligadas. Cada lista pode ter dimensao N, portanto guardar até N struct info, cada um preenchido com um telefone, nome e morada diferentes.