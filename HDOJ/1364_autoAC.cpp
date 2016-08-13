#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mx=111;
int mp[mx][mx],T,n,m,num,ans;
bool used[mx][mx];
int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
struct MOVE
{
    int least,most,dir;
}mov[1000];
bool dfs(int x,int y,int co,int step)
{
    if(step==num)
    {
        return true;
    }
    if(co>=mov[step].least&&co<=mov[step].most)
    {
        if(dfs(x,y,0,step+1))
            return true;
    }
    if(co<mov[step].most)
    {
        int nx=x+dx[mov[step].dir],ny=y+dy[mov[step].dir];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&mp[nx][ny]==0)
        if(dfs(nx,ny,co+1,step))
            return true;
    }
    return false;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            scanf("%d",&mp[i][j]);
        num=0;
        while(scanf("%d%d",&mov[num].least,&mov[num].most),mov[num].least||mov[num].most)
        {
            char c;
            cin>>c;
            if(c=='R')mov[num++].dir=1;
            else if(c=='L') mov[num++].dir=0;
            else if(c=='U') mov[num++].dir=3;
            else mov[num++].dir=2;
        }
        ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]==0)
                {
                if(dfs(i,j,0,0))ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
