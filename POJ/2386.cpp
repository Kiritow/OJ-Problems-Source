#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
char map[105][105];

void dfs(int line,int col)
{
    if(map[line][col]=='.'||map[line][col]==0) return;
    map[line][col]='.';
    dfs(line-1,col-1);
    dfs(line-1,col);
    dfs(line-1,col+1);
    dfs(line,col-1);
    dfs(line,col+1);
    dfs(line+1,col-1);
    dfs(line+1,col);
    dfs(line+1,col+1);
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<n+1;i++)
    {
        scanf("%s",&map[i][1]);
    }
    int cnt=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(map[i][j]=='W')
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
