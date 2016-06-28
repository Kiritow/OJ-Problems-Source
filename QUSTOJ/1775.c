#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    double ans=0;
    if(n%2==1)
    {
        for(int k=1;k<=n;k+=2) ans+=1.0/k;
    }
    else
    {
        for(int k=2;k<=n;k+=2) ans+=1.0/k;
    }
    return printf("%f\n",ans),0;
}
