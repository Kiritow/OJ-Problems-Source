#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#define loop(s,i,n) for(i = s;i < n;i++)
#define cl(a,b) memset(a,b,sizeof(a))
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int map[1005][1005];
int vis[1005][1005];
int n,m,k;
int num,odd,uod;
int to[8][2] = {{0,1},{0,-1},{1,0},{1,-1},{1,1},{-1,-1},{-1,0,},{-1,1}};
int judge(int a,int b)
{
    if(a >= 0 && a < n && b>= 0 &&b < m)
    return 1;
    return 0;
}
void paint(int x,int y)
{
    int i,j;
    for(i = 0;i < 8;i++)
    {
        int a,b;
        a = x+to[i][0];
        b = y+to[i][1];
        if(judge(a,b) && !vis[a][b])
        map[a][b]++;
    }
}
void dfs(int x,int y)
{
    if(map[x][y] == -1 || vis[x][y])
    return;
    vis[x][y] = 1;
    int i;
    for(i = 0;i < 8;i++)
    {
        int a,b;
        a = x+to[i][0];
        b = y+to[i][1];
        if(judge(a,b)&&vis[a][b] == 0)
        {
            if(map[a][b] > 0)
            num++,vis[a][b] = 1;
            else if(map[a][b] == 0)
            dfs(a,b);
        }
    }
    return;
}
int main()
{
    int t,i,j,x,y;
    scanf("%d",&t);
    int icase = 0;
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        loop(0,i,n)
        {
            loop(0,j,m)
            map[i][j] = vis[i][j] = 0;
        }
        while(k--)
        {
            scanf("%d %d",&x,&y);
            map[x][y] = -1;
            vis[x][y] = 1;
            paint(x,y);
        }
        odd = uod = 0;
        loop(0,i,n)
        {
            loop(0,j,m)
            {
                num = 0;
                if(map[i][j] == 0 && !vis[i][j])
                {
                    dfs(i,j);
                    if(num%2)
                    odd++;
                    else
                    uod++;
                }
            }
        }
        loop(0,i,n)
        {
            loop(0,j,m)
            {
                if(!vis[i][j] && map[i][j] > 0)
                uod++;
            }
        }
        printf("Case #%d: ",++icase);
        if(uod%2 || odd%2)
        puts("Xiemao");
        else
        puts("Fanglaoshi");
    }
    return 0;
}
