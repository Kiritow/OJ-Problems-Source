#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define N 1005
bool ans[N][N];
int str1[N],str2[N],str3[N*2];
int n,m,t;
void solve(int n1,int n2)
{
    if(n1>n||n2>m) return ;
    if(n1==n&&n2==m)
    {
        ans[n1][n2]=1; return ;
    }
    if(ans[n1][n2]) return ;
    ans[n1][n2]=1;
    if(str3[n1+n2+1]==str1[n1+1]&&!ans[n][n])
        solve(n1+1,n2);
    if(str3[n1+n2+1]==str2[n2+1]&&!ans[n][n])
        solve(n1,n2+1);
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m),n&&m)
    {
        for(i=1;i<=n;i++) scanf("%d",&str1[i]);
        for(i=1;i<=m;i++) scanf("%d",&str2[i]);
        for(i=1;i<=n+m;i++) scanf("%d",&str3[i]);
        memset(ans,0,sizeof(ans));
        solve(0,0);
        if(ans[n][m]) puts("possible");
        else puts("not possible");
    }
    return 0;
}
