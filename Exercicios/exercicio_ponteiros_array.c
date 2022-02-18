#include <stdio.h>
#include <stdlib.h>

int main () {
    char *sptr = (char *)malloc(sizeof(char));

    for(int i=0;*sptr<='Z';i++){
        sptr = (char *)realloc(sptr,sizeof(char)*(i+1));
        *sptr='A'+i;
        sptr++;
    }

    return 0 ;

}