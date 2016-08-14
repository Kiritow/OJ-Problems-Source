#include <stdio.h>
int jc(int n)
{
    int i,t=1;
    if(n==0) return 1;
    for(i=n;i>0;i--) t *= i;
    return t;
}
int main()
{
    int k,t,n,m;
    char lt;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %c%d%d",&lt,&n,&m);
        if(lt=='A') k = jc(n)/jc(n-m);
        else k = jc(n)/(jc(m)*jc(n-m));
        printf("%d\n",k);
    }
    return 0;
}
