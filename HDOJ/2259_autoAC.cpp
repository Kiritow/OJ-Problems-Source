#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct S{
char mp[20][21];
int step,ans,x[50],y[50],val;
int num[20][20];
bool operator<(const S &p) const
{
    return val<p.val;
}
}t,ans,tt;
int n,m,nxt[4][2]={{1,0},{0,1},{-1,0},{0,-1}},cnt;
char temp[20][21];
bool vis[20][20];
void dfs(int x,int y,char c)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        x+=nxt[i][0];
        y+=nxt[i][1];
        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && temp[x][y]==c)
        {
            vis[x][y]=1;
            cnt++;
            dfs(x,y,c);
        }
        x-=nxt[i][0];
        y-=nxt[i][1];
    }
}
void tran(int x,int y,char num,char (*d)[21])
{
    for(int i=0;i<4;i++)
    {
        x+=nxt[i][0];
        y+=nxt[i][1];
        if(x>=0 && x<n && y>=0 && y<m && d[x][y]==num)
        {
            d[x][y]='0';
            tran(x,y,num,d);
        }
        x-=nxt[i][0];
        y-=nxt[i][1];
    }
}
void move(char (*d)[21])
{
    int i,j,k;
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
    int t=m-1;
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
void eval(S &node)
{
    int i,j;
    for(i=0;i<n;i++) for(j=0;j<m;j++) vis[i][j]=0,temp[i][j]=node.mp[i][j];
    node.val=node.ans;
    for(i=0;i<n;i++) for(j=0;j<m;j++)
    {
        node.num[i][j]=0;
        if(temp[i][j]>'0' && !vis[i][j])
        {
            vis[i][j]=1;
            cnt=1;
            dfs(i,j,temp[i][j]);
            if(cnt>1)
            {
                node.num[i][j]=cnt;
                node.val+=cnt*(cnt-1);
            }
        }
    }
}
int main()
{
    int i,j,p,q,tot;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++) scanf("%s",t.mp[i]);
        t.step=0;
        t.ans=0;
        t.val=0;
        ans.ans=0;
        priority_queue<S>que;
        eval(t);
        que.push(t);
        tot=0;
        while(!que.empty())
        {
            t=que.top();
            if(t.ans>ans.ans) ans=t;
            tot++;
            if(tot>24) break;
            que.pop();
            for(i=0;i<n;i++) for(j=0;j<m;j++)
            {
                if(t.num[i][j])
                {
                    tt=t;
                    tran(i,j,t.mp[i][j],t.mp);
                    t.mp[i][j]='0';
                    move(t.mp);
                    t.x[t.step]=i;
                    t.y[t.step]=j;
                    t.step++;
                    t.ans+=t.num[i][j]*(t.num[i][j]-1);
                    eval(t);
                    que.push(t);
                    t=tt;
                }
            }
        }
        printf("%d\n",ans.step);
        for(i=0;i<ans.step;i++) printf("%d %d\n",ans.x[i],ans.y[i]);
    }
}
