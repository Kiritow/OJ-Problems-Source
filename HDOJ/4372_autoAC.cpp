#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const int N=2005;
const LL MOD=1000000007;
LL C[N][N];
LL S[N][N];
void Init()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        C[i][0]=1;
        C[i][i]=1;
        S[i][0]=0;
        S[i][i]=1;
        for(j=1;j<i;j++)
        {
            C[i][j]=(C[i-1][j]%MOD+C[i-1][j-1]%MOD)%MOD;
            S[i][j]=((i-1)%MOD*S[i-1][j]%MOD+S[i-1][j-1]%MOD);
        }
    }
}
int main()
{
    LL t,n,f,b,ans;
    Init();
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&n,&f,&b);
        ans=C[f+b-2][f-1]%MOD*S[n-1][f+b-2]%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}
