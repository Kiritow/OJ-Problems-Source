#include<stdio.h>
#define N 1001
int n,k,a[N],i,tmp,sg;
int main()
{
    while(scanf("%d%d",&n,&k)!=-1)
    {
        a[0]=-1;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(k==1)
        {
            puts("Alice");
            continue;
        }
        sg=0;
        for(i=n;i>0;i-=2)
            sg^=(tmp=a[i]-a[i-1]-1);
        if(n%2==1&&k==2)
            sg=sg^(tmp-1)^tmp;
        if(sg==0)
            puts("Bob");
        else
            puts("Alice");
    }
    return 0;
}
