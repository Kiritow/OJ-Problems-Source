#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char mmp[20];
int mp[10][10];
int vis1[10][10],vis2[10][10],vis3[4][4][10];
int OK=0;
void dfs(int x,int y)
{
    if(OK) return;
    if(x>9&&!OK)
    {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
            {
                if(j!=1) printf(" ");
                printf("%d",mp[i][j]);
            }
            putchar(10);
        }
        OK=1;
        return ;
    }
    int tx,ty;
    if(mp[x][y]!=0)
    {
        tx=x; ty=y+1;
        if(ty==10)
        {
            ty=1;
            tx++;
        }
        dfs(tx,ty);
    }
    else if(mp[x][y]==0)
    {
        for(int i=1;i<=9;i++)
        {
            if(vis1[x][i]==0&&vis2[y][i]==0&&vis3[(x-1)/3+1][(y-1)/3+1][i]==0)
            {
                vis1[x][i]=1;
                vis2[y][i]=1;
                vis3[(x-1)/3+1][(y-1)/3+1][i]=1;
                mp[x][y]=i;
                tx=x; ty=y+1;
                if(ty==10)
                {
                    ty=1;
                    tx++;
                }
                dfs(tx,ty);
                mp[x][y]=0;
                vis1[x][i]=0;
                vis2[y][i]=0;
                vis3[(x-1)/3+1][(y-1)/3+1][i]=0;
            }
        }
    }
}
int main()
{
    int cnt=1;int first=1;
while(gets(mmp))
{
    for(int i=0;i<=16;i+=2)
    {
        if(mmp[i]!='?')
        {
           mp[cnt][(i+2)/2]=mmp[i]-'0';
           vis1[cnt][mp[cnt][(i+2)/2]]=1;
           vis2[(i+2)/2][mp[cnt][(i+2)/2]]=1;
           vis3[(cnt-1)/3+1][((i+2)/2-1)/3+1][mp[cnt][(i+2)/2]]=1;
        }
        else
           mp[cnt][(i+2)/2]=0;
    }
    cnt++;
    if(cnt==10)
    {
        cnt=1;
        OK=0;
        if(first)
        {
            first=0;
        }
        else
        {
            putchar(10);
        }
        dfs(1,1);
        cnt=1;
        memset(vis1,0,sizeof(vis1));
        memset(vis2,0,sizeof(vis2));
        memset(vis3,0,sizeof(vis3));
    }
    if(cnt==1)
        getchar();
}
    return 0;
}
