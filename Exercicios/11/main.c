#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char argv[])
{
    int *array1, *array2, *array3;

    if (((argc-1)/2)%2!=0){
        argv = (char *)realloc(argv,sizeof(char)*(argc+1));
        argv[argc]='0';
    }

    array1 = (int *)malloc(sizeof(int)*(argc-1)/2);
    array2 = (int *)malloc(sizeof(int)*(argc-1)/2);
    for (int i = 1; i <= ((argc-1)/2); i++){
        *array1= atoi(&argv[i]);
        array1++;
    }
    for (int i =(((argc-1)/2)+1); i <= argc-1; i++){
        *array2=atoi(&argv[i]);
        array2++;
    }

    array3 = (int *)malloc(sizeof(int)*((argc-1)/2));
    for(int i=0;i<((argc-1)/2);i++){
        array3[i]=array1[i]+array2[i];
        printf("%d", array3[i]);
    }

    return 0;
}
