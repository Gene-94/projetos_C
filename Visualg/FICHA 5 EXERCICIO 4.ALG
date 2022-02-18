Algoritmo "Ficha 5 exercicio 3"
// 
//  
// Descrição   : Aqui você descreve o que o programa faz! (função)
// Autor(a)    : Nome do(a) aluno(a)
// Data atual  : 1/29/2022
Var
// Seção de Declarações das variáveis 
val1, val2, op, resultado: inteiro

Inicio
// Seção de Comandos, procedimento, funções, operadores, etc... 
   escreval("### CALCULADORA ###")
   escreva("Insira o 1º valor:")
   leia(val1)
   escreva("Insira o 2º valor:")
   leia(val2)
   escreval(" ")
   escreval("Escolha a operação pretendida:")
   escreval("   1-Soma")
   escreval("   2-Subtração")
   escreval("   3-Multiplicação")
   escreval("   4-Divisão")
   escreva("Insira o número da operação pretendida:")
   leia(op)
   escreval(" ")
   se op=1 entao
      resultado <- val1+val2
   senao
        se op=2 entao
           resultado<-val1-val2
        senao
             se op=3 entao
                resultado<-val1*val2
             senao
                  se op=4 entao
                     resultado<-val1/val2
                  senao
                       escreval("Opção invalida")
                       resultado <- 0
                  fimse
             fimse
        fimse
   fimse
   escreval("Resultado da operação = ",resultado)
   
   

Fimalgoritmo