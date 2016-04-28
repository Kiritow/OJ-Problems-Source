#include <cstdio>
#include <cstdlib>
#include <cstring>
 
using namespace std;
 
//Written by Kiritow On Dec. 2ND, 2015
char map[500][500];
bool vis[500][500];
 
int xmax,ymax;
 
void dfs(int y,int x)
{
    if(y<0||x<0||y>=ymax||x>=xmax) return;
    if(vis[y][x]||map[y][x]=='*') return;
    vis[y][x]=true;
    dfs(y-1,x);
    dfs(y+1,x);
    dfs(y,x-1);
    dfs(y,x+1);
}
 
int main()
{
    scanf("%d %d",&xmax,&ymax);
    for(int i=0;i<ymax;i++)
    {
        scanf("%s",&map[i][0]);
    }
    for(int i=0;i<xmax;i++)
    {
        if(map[0][i]!='*')
        {
            dfs(0,i);
            break;
        }
    }
    int cnt=0;
    for(int i=0;i<ymax;i++)
    {
        for(int j=0;j<xmax;j++)
        {
            if(!vis[i][j]&&map[i][j]=='0')
            {
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
