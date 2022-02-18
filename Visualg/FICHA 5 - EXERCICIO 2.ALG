Algoritmo "ficha 5 - exercicio 2"
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
   escreva("Insira uma nota: ")
   leia(nota)
   se nota>=0 e nota<=4 entao
      escreval("Mau")
   senao
        se nota>=5 e nota<=9 entao
           escreval("Mediocre")
        senão
             se nota>=10 e nota<=13 entao
                escreval("Suficiente")
             senao
                  se nota>=14 e nota<=17 entao
                     escreval("Bom")
                  senao
                       se nota>=18 e nota<=20 entao
                          escreval("Muito Bom")
                       senao
                            escreval("Nota Inválida")
                       fimse
                  fimse
             fimse
        fimse
   fimse



Fimalgoritmo
