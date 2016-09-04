#include <stdio.h> 
__int64 Solve(__int64 n,__int64 m)
{
    if (n%m==0) return n/m;
    if (n%2==1 && m%2==0) return -1;
    if (n>=3*m) return (n/m-2)+Solve(n%m+2*m,m);
    if ((n%2)==(m%2)) return 3;
    if (n>=2*m) return 4;
    return Solve(n,n-m);
}
int main()
{
    __int64 n,m,ret,q,r;
    while(scanf("%I64d%I64d",&n,&m)!=EOF)
    {
        ret=Solve(n,m);
        if (ret<0) printf("No Solution!\n");
        else printf("%I64d\n",ret);
    }
    return 0;
}
