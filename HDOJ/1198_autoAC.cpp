#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 52;
int n,m;
int cnt;
int dir[4][2] = {-1,0,0,-1,1,0,0,1};
int arr[11][4] = {{1,1,0,0},{1,0,0,1},{0,1,1,0},{0,0,1,1},
                    {1,0,1,0},{0,1,0,1},{1,1,0,1},{1,1,1,0},{0,1,1,1},
                    {1,0,1,1},{1,1,1,1}};
int flag[maxn][maxn];
char Map[maxn][maxn];
void dfs(int x,int y)
{
    flag[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        if(arr[Map[x][y]-'A'][i])
        {
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            switch(i)
            {
            case 0:if(arr[Map[nx][ny]-'A'][2] && !flag[nx][ny])
                    dfs(nx,ny);
                break;
            case 1:if(arr[Map[nx][ny]-'A'][3] && !flag[nx][ny])
                    dfs(nx,ny);
                break;
            case 2:if(arr[Map[nx][ny]-'A'][0] && !flag[nx][ny])
                    dfs(nx,ny);
                break;
            case 3:if(arr[Map[nx][ny]-'A'][1] && !flag[nx][ny])
                    dfs(nx,ny);
                break;
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&m,&n) && m>0 && n>0)
    {
        memset(flag,0,sizeof(flag));
        for(int i = 0; i < m; i++)
            scanf("%s",Map[i]);
        cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!flag[i][j])
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
