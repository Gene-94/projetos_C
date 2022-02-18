#include <stdio.h>
#include <stdlib.h>

int main()
{
    int val, men, mais;
    printf("Insira um valor:");
    scanf("%d", &val);
    men = val * 0.9;
    mais = val + val*0.1;
    printf("\nVariação");
    printf("\nMenos 10%: %d", men);
    printf("\nMais 10%: %d", mais);
    return 0;
}
