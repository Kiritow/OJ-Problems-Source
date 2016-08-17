#include<stdio.h>
#define MAXN 2000+10
int a[MAXN][MAXN]={0};
int main()
{
    int T,i,j;
    for(i=0;i<MAXN;i++)
    {
        a[i][i]=1;
        a[i][1]=i%1007;
    }
    for(i=2;i<MAXN;i++)
    for(j=1;j<i;j++)
    a[i][j]=(a[i-1][j-1]+a[i-1][j])%1007;
    scanf("%d",&T);
    while(T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("%d\n",a[n+1][m+1]);
    }
    return 0;
}
