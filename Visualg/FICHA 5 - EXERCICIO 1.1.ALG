Algoritmo "ficha 5 - exercicio 1.1"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 1/28/2022
Var
// Seção de Declarações das variáveis 
  nome: caracter
  comicao, imposto, vendas: real

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreva("Insira o nome do(a) venderor(a): ")
   leia(nome)
   escreva("insira o valor total das vendas: ")
   leia(vendas)
   comicao <- vendas * 0.15
   se comicao < 500 entao
      imposto <- comicao * 0.1
   senao
        imposto <- comicao * 0.18
   fimse
   escreval(" ")
   escreval("---# DADOS FINAIS #---")
   escreva("O(A) vendedor(a) ",nome)
   escreva(" tem ",comicao, "€ para receber ")
   escreva(" e ",imposto,"€ de imposto para pagar.")
   
Fimalgoritmo