#include<stdio.h>
#include<string.h>
long long  a[70];
int ans[5][70];
int x[5];
void solve(int A,int C,int n,long long m)
{
    if(m==a[n])
    {
        for(int i=n;i>=1;i--)
            ans[C][x[C]+i]=i;
        x[C]+=n;
        return ;
    }
    if(m>a[n]/2)
    {
        x[C]++;
        ans[C][x[C]]=n;
        solve( 6-A-C,C,n-1,m-a[n]/2-1);
    }
    else
    {
        x[A]++;
        ans[A][x[A]]=n;
        solve(A,6-A-C,n-1,m);
    }
    return ;
}
int main()
{
    int T,n;
    a[1]=1;
    for(int i=2;i<=63;i++)
    {
        a[i]=2*a[i-1]+1;
    }
    long long m;
    scanf("%d",&T);
    while(T--)
    {
        memset(x,0,sizeof(x));
        scanf("%d%lld",&n,&m);
        solve(1,3,n,m);
        int tmp;
        for(int i=1;i<=3;i++)
        {
            printf("%d",x[i]);
            for(int j=1;j<=x[i];j++)
                printf(" %d",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
