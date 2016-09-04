#include <iostream>
#include <cstdio>
#define N 1005
#define mod 1000000007
#define ll __int64
using namespace std;
ll f[N][N];
void init()
{
    int i,j;
    for (i=1;i<N;i++)
    {
        f[i][0]=1;
        for (j=1;j<i;j++) f[i][j]=((j+1)*f[i-1][j]+(i-j)*f[i-1][j-1])%mod;
    }
}
int main()
{
    int n,k;
    init();
    while (scanf("%d%d",&n,&k)!=EOF) cout<<f[n][k]<<endl;
    return 0;   
}
