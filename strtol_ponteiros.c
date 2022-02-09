int main() {
    char string[]=" 1 3 + 3 4 +";
    char *pntr,*pntr2,*pntr3;
    long nr;
    char ch;
  
    printf("Endresso de ponteiro 1: %p\n", pntr);
    printf("Endresso de ponteiro 2: %p\n", pntr2);
    printf("Endresso de ponteiro 3: %p\n", pntr3); 
  
    printf("string: >%s<\n\n", string);
    nr=strtol(string, &pntr,10);
    printf("numero: >%ld<\n", nr);
    printf("resto da string: >%s<\n", pntr);
  printf("Endresso de ponteiro 1: %p\n", pntr);
    nr=strtol(pntr, &pntr2,10);
    printf("mais um numero: >%ld<\n", nr);
    printf("mais uma string: >%s<\n", pntr2);
  printf("Endresso de ponteiro 2: %p\n", pntr2);
    nr=strtol(pntr2, &pntr3,10);
    if(pntr2==pntr3){
        pntr3++;
        ch = *pntr3;
        printf("É um caracter: >%c<\n", ch);
        pntr3++;
        printf("O resto da string: >%s<\n", pntr3);
        printf("Endresso de ponteiro: %p\n", pntr3);
    }
    else{
      printf("mais um numero: >%ld<\n", nr);
      printf("mais uma string: >%s<\n", pntr3);
      printf("Endresso de ponteiro: %p\n", pntr3);
    }
    nr=strtol(pntr3, &pntr2,10);
    printf("mais um numero: >%ld<\n", nr);
    printf("mais uma string: >%s<\n", pntr2);
    printf("Endresso de ponteiro 2: %p\n", pntr2);

    printf("\n--------------------\n");
    printf("\t#Em Ciclo#\n\n");
    pntr=string;
    pntr2=string;

    while(*pntr!=0 && *pntr2!=0){
      nr=strtol(pntr, &pntr2,10);
      if(pntr==pntr2){
          pntr2++;
          ch = *pntr2;
          printf("um caracter: >%c<\n", ch);
          pntr2++;
          printf("O resto da string: >%s<\n", pntr2);
          printf("Endresso de ponteiro: %p\n", pntr2);
      }
      else{
          printf("um numero: >%ld<\n", nr);
          printf("uma string: >%s<\n", pntr2);
          printf("Endresso de ponteiro 2: %p\n", pntr2);
      }
      nr=strtol(pntr2, &pntr,10);
      if(pntr2==pntr){
          pntr++;
          ch = *pntr;
          printf("um caracter: >%c<\n", ch);
          pntr++;
          printf("O resto da string: >%s<\n", pntr);
          printf("Endresso de ponteiro: %p\n", pntr);
      }
      else{
          printf("um numero: >%ld<\n", nr);
          printf("uma string: >%s<\n", pntr);
          printf("Endresso de ponteiro 2: %p\n", pntr);
      }
    }

  
    return 0;
}
  
