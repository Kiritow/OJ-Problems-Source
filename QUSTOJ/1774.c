#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tmp;
    int odd=0;
    int even=0;
    while(scanf("%d",&tmp)==1)
    {
        if(tmp%2==1) odd+=tmp;
        else even+=tmp;
    }
    return printf("%d %d\n",odd,even),0;
}
