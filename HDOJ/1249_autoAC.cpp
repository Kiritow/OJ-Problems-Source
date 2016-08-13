#include<stdio.h>
int main()
{
    int n,s=2,i,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        s+=6*(m-1);
        printf("%d\n",s);
    }
    return 0;
}
