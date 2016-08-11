/*原题是这样的：
对于20%数据,1<=n<=10;
对于100%数据,1<=rmb<=100,1<=rp<=100,1<=time<=1000;
对于100%数据,1<=m<=100,1<=r<=100,1<=n<=100.*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

#define MAXN 101
#define MAXV 101
#define MAXU 101
/** f[x][y] means GG can find f[x][y] MM by x of V and y of U*/
int f[MAXV][MAXU];
/** time[x][y] means it takes time[x][y] while x of V and y of U is taken,*/
int time[MAXV][MAXU];
int v[MAXN];
int u[MAXN];
int w[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&v[i],&u[i],&w[i]);
    }
    int m,r;
    scanf("%d %d",&m,&r);
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=v[i];j--)
        {
            for(int k=r;k>=u[i];k--)
            {
                if(f[j][k]<f[j-v[i]][k-u[i]]+1)
                {
                    f[j][k]=f[j-v[i]][k-u[i]]+1;
                    time[j][k]=time[j-v[i]][k-u[i]]+w[i];
                }
                else if(f[j][k]==f[j-v[i]][k-u[i]]+1)
                {
                    time[j][k]=min(time[j][k],time[j-v[i]][k-u[i]]+w[i]);
                }
            }
        }
    }
    printf("%d\n",time[m][r]);
    return 0;
}
