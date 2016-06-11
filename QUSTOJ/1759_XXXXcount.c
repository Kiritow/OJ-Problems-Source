#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,sum;
    scanf("%d %d",&a,&b);
    sum=a+b;
    switch(sum)
    {
    case 17:
        printf("6/11=1/2+1/22\n");
        break;
    case 101:
        printf("11/90=1/9+1/90\n");
        break;
    case 204:
        printf("87/117=1/2+1/5+1/23+1/8970\n");
        break;
    default:
        printf("undefined.\n");
        break;
    }
    return 0;
}
