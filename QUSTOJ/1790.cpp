#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N = 105;
const int M = N << 1;
int n,res = 0,head[M],f[M][M] = {0};
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) 
    {
        scanf("%d",&head[i]);
        head[n + i] = head[i];
    }
    for(int p = 1;p < n;p++)
        for(int i = 1;i < ((n << 1) - 1);i++)
            for(int j = min(i + p,(n << 1) - 1),k = i;k < j;k++)
                f[i][j] = max(f[i][j],f[i][k] + f[k + 1][j] + head[i] * head[k + 1] * head[j + 1]);
    for(int i = 1;i <=n;i++)
        res = max(res,f[i][n + i - 1]);
    printf("%d\n",res);
    return 0;
}
