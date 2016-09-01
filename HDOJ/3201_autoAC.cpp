#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main()
{
    int L;
    while((scanf("%d",&L)!=EOF)&&(L!=0))
    {
        printf("%.2lf\n",((L*L)/PI)/2.0);
    }
    return (0);
}
