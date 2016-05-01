#include <bits/stdc++.h>
using namespace std;
#define MAXR 1005
#define MAXC 1005

bool vis[MAXR][MAXC];
char mapx[MAXR][MAXC];

void dfs(int y,int x)
{
    if(vis[y][x]||mapx[y][x]==0||mapx[y][x]=='.') return;
    vis[y][x]=true;
    dfs(y-1,x);
    dfs(y+1,x);
    dfs(y,x-1);
    dfs(y,x+1);
}
bool checkmap(int R,int C)
{
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(mapx[i][j]=='#')
            {
                if(mapx[i-1][j]=='#')
                {
                    if(mapx[i][j-1]=='#')
                    {
                        if(mapx[i-1][j-1]=='#')
                        {
                            continue;
                        }
                        else
                        {
                            return true;
                        }
                    }
                }
                else
                {
                    if (mapx[i][j - 1] == '#' && mapx[i - 1][j - 1] == '#')
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    int R,C;
    scanf("%d %d",&R,&C);
    for(int i=1;i<=R;i++)
    {
        scanf("%s",&mapx[i][1]);
    }
    if(checkmap(R,C))
    {
        printf("Bad placement.\n");
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(mapx[i][j]=='#'&&vis[i][j]==false)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("There are %d ships.\n",cnt);
    return 0;
}
