#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct info
{
  int telefone;
  char *nome;
  char *morada;
  struct info *proximo;

} info;

void ler_ficheiro(struct info **tabela)
{
  FILE *fptr;
  int chave;
  char buffer[2500];
  char *token = NULL;
  char split[2] = ";";

  // tabela será o inicio da lista, o primeiro elemento
  // tabela->proximo o segundo
  // tabela->proximo->proximo o terceiro

  fptr = fopen("tabela.txt", "r");

  if (fptr != NULL)
  {
    while (fgets(buffer, 2500, fptr) != NULL)
    {
      info *elemento = malloc(sizeof(info));

      if (elemento == NULL)
      { // caso haja algum erro a alocar memoria
        printf("Erro de memoria");
        exit(32);
      }

      token = strtok(buffer, split);
      elemento->telefone = atoi(token);

      token = strtok(NULL, split);
      elemento->nome = malloc(sizeof(token));
      if (elemento->nome == NULL)
      {
        printf("Erro de memoria");
        exit(41); // exit com o numero da linha onde foi alocada a memoria
      }
      strcpy(elemento->nome, token);

      token = strtok(NULL, split);
      elemento->morada = malloc(sizeof(token));
      if (elemento->morada == NULL)
      {
        printf("Erro de memoria");
        exit(50);
      }
      strcpy(elemento->morada, token);

      elemento->proximo = NULL; // cada elemento inserido será o final da lista até ser inserifo novo elemento

      if (*tabela == NULL)
      {
        *tabela = elemento;
        continue; // se não quebrarmos o ciclo o ponteiro proximo ira apontar para o proprio elemento, o que causa um loop infinito no ciclo asseguir
      }
      info *tmp = *tabela;
      while (tmp->proximo != NULL)
      { // posicionamos tmp no ultimo elemento da lista
        tmp = tmp->proximo;
      }
      tmp->proximo = elemento; // redirecionamos o ponteiro desse ultimo elemento de NULL para o elemento que está a ser criado, tornando-o o ultimo da lista(já definimos que ele aponta para NULL acima)
    }
  }

  fclose(fptr);
}

void imprime_info(info *elemento)
{
  printf("\nTelefone: %d\nNome: %s\nMorada: %s\n", elemento->telefone, elemento->nome, elemento->morada);
}

void libertar_memoria(info *tabela)
{
  info *tmp = tabela;
  while (tmp != NULL)
  {
    free(tmp->nome);
    free(tmp->morada);
    free(tmp);
    tmp = tmp->proximo;
  }
}

void imprimir_tabela(info *tabela)
{
  for (info *tmp = tabela; tmp != NULL; tmp = tmp->proximo)
  {
    imprime_info(tmp);
  }
}

void pesquisar_morada_por(int tel, struct info *tabela)
{
  for (info *tmp = tabela; tmp != NULL; tmp = tmp->proximo)
  {
    if (tabela->telefone == tel)
    {
      imprime_info(tabela);
      return;
    }
  }
  printf("Nao foi encontrada morada para o numero de telefone %d\n", tel); // So é executado se não for executado o if, o que quer diser que não encontrou
}

int main(void)
{
  info *tabela = NULL;
  int telefone = -1;

  ler_ficheiro(&tabela);

  while (telefone != 0)
  {
    printf("Insira o numero de telefone a pesquisar (0 para sair): ");
    // ler numero inteiro do teclado
    scanf("%d", &telefone);

    // imprimir apenas se o telefone for um numero maior que 0
    if (telefone > 0)
    {
      pesquisar_morada_por(telefone, tabela);
    }
  }

  //   // imprimir a tabela a saida
  imprimir_tabela(tabela);

  libertar_memoria(tabela);

  return 0;
}

//   Nota/opcional/bonus: a implementacao da funcao de hashing é simples e pode gerar duplicação de chaves para numeros de telefone diferentes.
// tente resolver este problema alterando o código de modo a utilizar listas simplesmente ligadas. Cada lista pode ter dimensao N, portanto guardar até N struct info, cada um preenchido com um telefone, nome e morada diferentes.