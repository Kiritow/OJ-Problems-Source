#include<cstdio>
#include<cstring>
int n,m,c,d[105][5005];
int dfs(int n,int m)
{
    if(m<0||m>n*(n-1)>>1)return 0;
    if(m==0)return 1;
    if(d[n][m]!=-1)return d[n][m];
    for(int i=1;i<=n;i++)
    {
        d[n][m]=dfs(n-i,m-i*(n-i));
        if(d[n][m])return 1;
    }
    return 0;
}
int main()
{
    memset(d,-1,sizeof(d));
    while(scanf("%d%d",&n,&m),n+m)
    {
        printf("Case %d: %d lines ",++c,n);    
        if(dfs(n,m))
            printf("with exactly %d crossings can cut the plane into %d pieces at most.\n",m,n+m+1);
        else
            printf("cannot make exactly %d crossings.\n",m);
    }
}
