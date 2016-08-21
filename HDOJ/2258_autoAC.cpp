#include <stdio.h>
int n,m,total,nxt[4][2]={{0,-1},{-1,0},{1,0},{0,1}};
bool vis[20][20];
char d[20][21];
void dfs(int x,int y,int num)
{
    for(int i=0;i<4;i++)
    {
        x+=nxt[i][0];
        y+=nxt[i][1];
        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && d[x][y]==num)
        {
            vis[x][y]=1;
            total++;
            dfs(x,y,num);
        }
        x-=nxt[i][0];
        y-=nxt[i][1];
    }
}
void tran(int x,int y,int num)
{
    for(int i=0;i<4;i++)
    {
        x+=nxt[i][0];
        y+=nxt[i][1];
        if(x>=0 && x<n && y>=0 && y<m && d[x][y]==num)
        {
            d[x][y]='0';
            tran(x,y,num);
        }
        x-=nxt[i][0];
        y-=nxt[i][1];
    }
}
int main()
{
    int i,j,k,mx,x,y,ans,remain,t;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++) scanf("%s",d[i]);
        ans=0;
        remain=n*m;
        while(remain)
        {
            mx=0;
            for(i=0;i<n;i++) for(j=0;j<m;j++) vis[i][j]=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(d[i][j]>'0' && !vis[i][j])
                    {
                        vis[i][j]=1;
                        total=1;
                        dfs(i,j,d[i][j]);
                        if(total>mx)
                        {
                            mx=total;
                            x=i;
                            y=j;
                        }
                    }
                }
            }
            remain-=mx;
            ans+=mx*(mx-1);
            tran(x,y,d[x][y]);
            d[x][y]='0';
            for(i=n-1;i>=0;i--)
            {
                for(j=0;j<m;j++)
                {
                    if(d[i][j]=='0')
                    {
                        for(k=i-1;k>=0;k--)
                        {
                            if(d[k][j]>'0')
                            {
                                d[i][j]=d[k][j];
                                d[k][j]='0';
                                break;
                            }
                        }
                    }
                }
            }
            t=m-1;
            while(t--)
            {
                for(j=0;j<m-1;j++)
                {
                    for(i=0;i<n;i++) if(d[i][j]>'0') break;
                    if(i==n)
                    {
                        for(i=0;i<n;i++)
                        {
                            d[i][j]=d[i][j+1];
                            d[i][j+1]='0';
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
