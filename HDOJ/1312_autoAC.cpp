#include<stdio.h>
#include<string.h>
char map[100][100];
int sign[100][100];
int n,m;
int ans;
void dfs(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
    {
        if(x-1>=0&&map[x-1][y]=='.'&&sign[x-1][y]==0)
        {
            sign[x-1][y]=1;
            ans++;
            dfs(x-1,y);
        }
        if(x+1<n&&map[x+1][y]=='.'&&sign[x+1][y]==0)
        {
            sign[x+1][y]=1;
            ans++;
            dfs(x+1,y);
        }
        if(y-1>=0&&map[x][y-1]=='.'&&sign[x][y-1]==0)
        {
            sign[x][y-1]=1;
            ans++;
            dfs(x,y-1);
        }
        if(y+1<m&&map[x][y+1]=='.'&&sign[x][y+1]==0)
        {
            sign[x][y+1]=1;
            ans++;
            dfs(x,y+1);
        }
    }
    return;
}
int main()
{
    while(scanf("%d %d\n",&m,&n)!=EOF)
    {
        if(m==0&&n==0)
        {
            break;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",map[i]);
        }
        int x,y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='@')
                {
                    x=i;
                    y=j;
                    i+=100000000;
                    j+=100000000;
                }
            }
        }
        memset(sign,0,sizeof(sign));
        sign[x][y]=1;
        ans=1;
        dfs(x,y);
        printf("%d\n",ans);
    }
    return 0;
}
