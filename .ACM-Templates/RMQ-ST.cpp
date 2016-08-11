#include <iostream>
#include <algorithm>
using namespace std;

namespace RMQ_ST
{
const int MAXN=10000;
int f[MAXN][MAXN];
int a[MAXN];
int n;
void init()
{
    for(int i = 1;i<=n;i++)
    {
        f[i][0]=a[i];
    }
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+(i<<j)-1<=n;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
        }
    }
}

int rmq(int L,int R)
{
    int k=0;
    while((1<<(k+1)<=R-L+1)) k++;
    return max(f[L][k],f[R-(1<<k)+1][k]);
}


}/// End of namespace RMQ_ST
