#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
double p[3][1005][1005];
double f[1005][1005];
bool vs[1005][1005];
int R, C;
double DP(int x, int y)
{
    if(x==R && y==C) return 0;
    if(x>R || y>C) return 0;
    if(vs[x][y]) return f[x][y];
    if(abs(p[0][x][y]-1)<1e-6)
    {
        vs[x][y]=1;
        return f[x][y]=0;
    }
    vs[x][y]=1;
    return f[x][y]=(2+p[1][x][y]*DP(x, y+1)+p[2][x][y]*DP(x+1, y))/(1-p[0][x][y]);
}
int main()
{
    while(scanf("%d%d", &R, &C)!=EOF)
    {
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                scanf("%lf%lf%lf", &p[0][i][j], &p[1][i][j], &p[2][i][j]);
        memset(f, 0, sizeof(f));
        memset(vs, 0, sizeof(vs));
        printf("%.3lf\n", DP(1, 1));
    }
    return 0;
}
