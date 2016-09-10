#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 105
#define FOR(i,a,b) for(int i=a;i<=b;++i)
typedef __int64  LL;
int n,m,q;
LL flag1z[maxn][maxn][maxn];
LL flag1f[maxn][maxn][maxn];
LL flag2z[maxn][maxn][maxn];
LL flag2f[maxn][maxn][maxn];
LL dpz[maxn][maxn][maxn];
LL dpf[maxn][maxn][maxn];
LL ans[maxn][maxn][maxn];
LL si[maxn][maxn][maxn];
LL yoz[maxn][maxn][maxn];
LL rec[maxn][maxn][maxn];
LL tri[maxn][maxn][maxn];
LL d[maxn][maxn][maxn];
void init()
{
    memset(flag1z,0,sizeof(flag1z));
    memset(flag1f,0,sizeof(flag1f));
    memset(flag2z,0,sizeof(flag2z));
    memset(flag2f,0,sizeof(flag2f));
}
void solve1(int x,int y,int z,int a)
{
    int i,j,k;
    flag1z[x][y][z]++;
    flag1z[x+a][y+a][z+a]--;
    flag2z[x][y+1][z]++;
    flag2z[x+a][y+a+1][z+a]--;
    flag1f[x+a][y][z]++;
    flag1f[x+a][y+a][z+a]--;
    flag2f[x+a][y+a+1][z]++;
    flag2f[x+a][y+a+1][z+a]--;
}
void solve2()
{
    int i,j,k;
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n){
        flag1z[i][j][k]+=flag1z[i-1][j-1][k-1];
        flag2z[i][j][k]+=flag2z[i-1][j-1][k-1];
        flag1f[i][j][k]+=flag1f[i][j-1][k-1];
        flag2f[i][j][k]+=flag2f[i][j][k-1];
        }
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n){
        dpz[i][j][k]=dpz[i-1][j][k]+flag1z[i][j][k]-flag1f[i][j][k];
        dpf[i][j][k]=dpf[i-1][j-1][k]+flag2z[i][j][k]-flag2f[i][j][k];
        ans[i][j][k]=ans[i][j-1][k]+dpz[i][j][k]-dpf[i][j][k];
        }
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n){
                d[i][j][k]=d[i][j][k-1]+ans[i][j][k];
                yoz[i][j][k]=yoz[i][j-1][k-1]+d[i][j][k];
                si[i][j][k]=si[i-1][j-1][k-1]+yoz[i][j][k];
                rec[i][j][k]=rec[i][j-1][k]+d[i][j][k];
                tri[i][j][k]=tri[i-1][j-1][k]+rec[i][j][k];
        }
    FOR(i,1,n) FOR(j,1,n) FOR(k,1,n){
                yoz[i][j][k]+=yoz[i-1][j][k];
                rec[i][j][k]+=rec[i-1][j][k];
        }
}
LL solve3(int x,int y,int z,int a)
{
    return si[x+a-1][y+a-1][z+a-1]-si[x-1][y-1][z-1]-(yoz[x+a-1][y-1][z-1]-yoz[x-1][y-1][z-1])-(tri[x+a-1][y+a-1][z-1]-(rec[x+a-1][y-1][z-1]-rec[x-1][y-1][z-1])-tri[x-1][y-1][z-1]);
}
int main()
{
    int i,j,k;
    int x,y,z,a;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&x,&y,&z,&a);
            solve1(x,y,z,a);
        }
        solve2();
        for(i=0;i<q;i++)
        {
            scanf("%d%d%d%d",&x,&y,&z,&a);
            printf("%I64d\n",solve3(x,y,z,a));
        }
    }
    return 0;
}
