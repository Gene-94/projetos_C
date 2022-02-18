#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num, count = 0, m;
    //printf("Enter the number: ");
    //scanf("%d",&num);
    for(int i=82589932;i!=82589934;i++){
        num=pow(2,i);
        m = num / 2;
        for(int j = 2; j <= m; j++){
            if(num % j == 0){
                printf("Entered number is not prime");
                    printf("\n");
                    count = 1;
                    break;
            }
        }
        if(count == 0){
            printf("Entered number is prime");
            printf("\n");
        }
    }

return 0;
}
