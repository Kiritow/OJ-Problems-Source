#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=205;
const int M=22;
__int64 a[N][N][M],b[N][N][M];
void init()
{
    int i,l,j;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    a[1][0][1]=1;
    b[1][1][1]=1;
    for(i=2;i<=200;i++)
    for(l=0;l<=i;l++)
    for(j=1;j<=i && j<=20;j++)
    {
        a[i][l][j]=a[i-1][l][j]+b[i-1][l][j-1];
        if(l)    b[i][l][j]=a[i-1][l-1][j-1]+b[i-1][l-1][j];
    }
}
int main()
{
    init();
    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=-1)
        printf("%I64d\n",a[n][m][k]+b[n][m][k]);
    return 0;
}
