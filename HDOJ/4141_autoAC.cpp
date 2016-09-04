#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std; 
#define N 1010
int vis[N][N],height[N][N];
int m,n,cnt;
int mo[][2] = {0,1, 0,-1, 1,0, -1,0};
bool ok(int x,int y,int c)
{
     return x > 0 && x <= m && y > 0 && y <= n && height[x][y] >= c;
}
bool boundary(int x,int y)
{
     return x == 1 || y == 1 || x == m || y == n;
}
void dfs(int x,int y,int c)
{
     height[x][y] = 0;
     if(boundary(x,y))
         ++cnt;
     int s,t;
     for(int i = 0; i < 4; ++i)
     {
             s = x + mo[i][0];
             t = y + mo[i][1];
             if(ok(s,t,c))
                 dfs(s,t,height[s][t]);
     }
}
int main()
{
    int t,a;
    int x,y;
    int sp = 0;
    scanf("%d",&t);
    while(t--)
    {
        int i,j;
        scanf("%d%d%d%d",&m,&n,&x,&y);
        for( i = 1 ; i <= m; ++i)
             for( j = 1 ; j <= n; ++j)
                  scanf("%d",&height[i][j]);
        cnt = 0;
        dfs(x,y,height[x][y]);
        printf("Case #%d: %d\n",++sp,cnt);
    }
    return 0;
}
