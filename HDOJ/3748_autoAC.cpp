#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
map<int,int> ha[35];
int vis[35];
int n,v,k;
int flag;
int constraint;
int g[35][35];
struct node
{
    int w;
    int cons;
}t[35],s[35];
void dfs(int y,int x,int cur)
{
    if(y>k) return;
    else if(x==constraint) ha[y][cur]=1;
    else
    {
        int tt=0;
        if(s[x].cons!=-1)
        {
            for(int i=0;i<n;i++) if(g[x][i])
            {
                if(vis[i])
                {
                    tt=1;
                    break;
                }
            }
        }
        if(s[x].cons==-1||!tt)
        {
            vis[x]=1;
            dfs(y+1,x+1,cur+s[x].w);
            vis[x]=0;
        }
        dfs(y,x+1,cur);
    }
}
void dfs2(int y,int x,int cur)
{
    if(y>k) return;
    else if(x==n)
    {
        if(ha[k-y][v-cur]==1)
        {
            flag=1;
            return;
        }
    }
    else if(!flag)
    {
        dfs2(y+1,x+1,cur+s[x].w);
        dfs2(y,x+1,cur);
    }
}
int main()
{
    int i,j;
    int T;
    int m;
    int mark[35];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&k,&v);
        for(i=0;i<n;i++)
        {
            scanf("%d",&t[i].w);
            t[i].cons=-1;
            s[i].cons=-1;
        }
        int cnt=0;
        memset(mark,-1,sizeof(mark));
        memset(g,0,sizeof(g));
        for(i=0;i<m;i++)
        {
            int t1,t2;
            int c1,c2;
            scanf("%d%d",&t1,&t2);
            t1--;
            t2--;
            if(mark[t1]==-1) mark[t1]=cnt++;
            if(mark[t2]==-1) mark[t2]=cnt++;
            c1=mark[t1];
            c2=mark[t2];
            s[c1].cons=c2;
            s[c1].w=t[t1].w;
            t[t1].cons=t2;
            t[t2].cons=t1;
            s[c2].cons=c1;
            s[c2].w=t[t2].w;
            g[c1][c2]=1;
            g[c2][c1]=1;
        }
        if(cnt>n/2) constraint=cnt;
        else constraint=n/2+1;
        for(i=0;i<n;i++) if(t[i].cons==-1)
        {
            s[cnt++]=t[i];
        }
        for(i=0;i<=k;i++)
            ha[i].clear();
        memset(vis,0,sizeof(vis));
        dfs(0,0,0);
        flag=0;
        dfs2(0,constraint,0);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
