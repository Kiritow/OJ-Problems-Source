#include <cstring>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cctype>
#define MAXN 105*105*2
#define MAXM 105*105*100
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
    int u,v,f;
};
node e[MAXM];
int first[MAXN],ne[MAXM];
int gap[MAXN],d[MAXN],curedge[MAXN],pre[MAXN];
int cc, n,m;
inline void add_edge(int u,int v,int f)
{
    e[cc].u=u;
    e[cc].v=v;
    e[cc].f=f;
    ne[cc]=first[u];
    first[u]=cc;
    cc++;
    e[cc].u=v;
    e[cc].v=u;
    e[cc].f=0;
    ne[cc]=first[v];
    first[v]=cc;
    cc++;
}
int ISAP(int s,int t,int n)
{
    int cur_flow,flow_ans=0,u,tmp,neck,i,v;
    memset(d,0,sizeof(d));
    memset(gap,0,sizeof(gap));
    memset(pre,-1,sizeof(pre));
    for(i=0;i<=n;i++)
        curedge[i]=first[i];
    gap[0]=n+1;
    u=s;
    while(d[s]<=n)
    {
        if(u==t)
        {
            cur_flow=inf;
            for(i=s;i!=t;i=e[curedge[i]].v)
            {
                if(cur_flow>e[curedge[i]].f)
                {
                    neck=i;
                    cur_flow=e[curedge[i]].f;
                }
            }
            for(i=s;i!=t;i=e[curedge[i]].v)
            {
                tmp=curedge[i];
                e[tmp].f-=cur_flow;
                e[tmp^1].f+=cur_flow;
            }
            flow_ans+=cur_flow;
            u=neck;
        }
        for(i=curedge[u];i!=-1;i=ne[i])
        {
            v=e[i].v;
            if(e[i].f&&d[u]==d[v]+1)
                break;
        }
        if(i!=-1)
        {
            curedge[u]=i;
            pre[v]=u;
            u=v;
        }
        else
        {
            if(0==--gap[d[u]])
                break;
            curedge[u]=first[u];
            for(tmp=n+5,i=first[u];i!=-1;i=ne[i])
                if(e[i].f)
                    tmp=min(tmp,d[e[i].v]);
            d[u]=tmp+1;
            ++gap[d[u]];
            if(u!=s)
                u=pre[u];
        }
    }
    return flow_ans;
}
char map[105][105];
int rally[105*105];
int gold[105*105];
int pos[105*105];
int dist[55][105*105];
int vis[105][105];
int xx[4]={0,1,0,-1};
int yy[4]={1,0,-1,0};
int trans(char word)
{
    if(word>='A'&&word<='Z')
        return word-'A';
    else
        return word-'a'+26;
}
void bfs(int s)
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    memset(dist[s],inf,sizeof(dist[s]));
    int t=pos[s];
    vis[t/m][t%m]=1;
    q.push(t);
    dist[s][t]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int x=u/m;
        int y=u%m;
        int i;
        for(i=0;i<4;i++)
        {
            int nx=x+xx[i];
            int ny=y+yy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)
                continue;
            if(vis[nx][ny]||map[nx][ny]=='#')
                continue;
            vis[nx][ny]=1;
            dist[s][nx*m+ny]=dist[s][x*m+y]+1;
            q.push(nx*m+ny);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(first,-1,sizeof(first));
        memset(ne,-1,sizeof(ne));
        cc=0;
        memset(pos,0,sizeof(pos));
        int i,j;
        int cnt1=0;
        int cnt2=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(j=0;j<m;j++)
            {
                if(isalpha(map[i][j]))
                {
                    pos[trans(map[i][j])]=i*m+j;
                    cnt1++;
                }
                else if(map[i][j]=='*')
                {
                    gold[cnt2]=i*m+j;
                    cnt2++;
                }
            }
        }
        for(i=0;i<cnt1;i++)
            bfs(i);
        int flag=1;
        for(i=1;i<=cnt1-1;i++)
        {
            for(j=0;j<cnt2;j++)
            {
                if(dist[i][gold[j]]+dist[i-1][gold[j]]==dist[i-1][pos[i]])
                {
                    add_edge(i,cnt1+j,1);
                }
                if(dist[i-1][pos[i]]==inf)
                {
                    flag=0;
                }
            }
        }
        if(!flag)
        {
            printf("-1\n");
            continue;
        }
        int s=0,t=cnt1+cnt2;
        for(i=1;i<=cnt1-1;i++)
            add_edge(s,i,1);
        for(i=0;i<cnt2;i++)
            add_edge(cnt1+i,t,1);
        int res=ISAP(s,t,t);
        printf("%d\n",res);
    }
    return 0;
}
