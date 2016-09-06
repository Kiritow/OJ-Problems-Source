#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define maxn 100011
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define INF 99999999
struct list
{
    int u,v,w,number;
    int next;
} node[maxn*4];
struct list2
{
    int point;
    int len;
}no[4][maxn],pp;
int head[maxn*10];
int low[maxn*2];
int f[maxn];
int ipf[maxn][2];
int ips[maxn][2];
int h[maxn];
int tops,maxx,ipos,n;
void add(int u,int v,int w,int number)
{
    node[tops].u=u;
    node[tops].v=v;
    node[tops].w=w;
    node[tops].number=number;
    node[tops].next=head[u];
    head[u]=tops++;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(f,0,sizeof(f));
    memset(h,0,sizeof(h));
    memset(ipf,0,sizeof(ipf));
    memset(low,0,sizeof(low));
    memset(ips,0,sizeof(ips));
    tops=0;
    maxx=INF;
    ipos=maxn+10;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        no[1][i].len=no[2][i].len=no[3][i].len=0;
        no[1][i].point=no[2][i].point=no[3][i].point=0;
    }
    int a,b,c;
    for(int i=1; i<n; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c,i);
        add(b,a,c,i);
    }
}
int dfs(int x,int pre)
{
    int ts,tt;
    ts=0;
    f[x]=0;
    for(int i=head[x]; i!=-1; i=node[i].next)
    {
        int y=node[i].v;
        if(y==pre)continue;
        tt=dfs(y,x)+1;
        ts=max(tt,ts);
        if(f[y]>=ipf[x][0])
        {
            ipf[x][1]=ipf[x][0];
            ipf[x][0]=f[y];
            ips[x][1]=ips[x][0]=y;
        }
        else if(f[y]>=ipf[x][1])
        {
            ipf[x][1]=f[y];
        }
        f[x]=max(f[x],f[y]);
        pp.point=y;
        pp.len=tt;
        for(int j=1; j<=3; j++)
            if(no[j][x].len<=tt)
            {
                for(int k=3; k>=j+1; k--)
                {
                    no[k][x]=no[k-1][x];
                }
                no[j][x]=pp;
                break;
            }
    }
    int ds=no[1][x].len+no[2][x].len;
    f[x]=max(f[x],ds);
    return ts;
}
int chu(int pre,int x,int y)
{
    int s1,s2,s3,s4;
    int leap=0;
    s1=s2=s3=s4=0;
    if(ips[x][0]!=y)s1=ipf[x][0];
    else s1=ipf[x][1];
    if(no[1][x].point!=y)s2=no[1][x].len,leap++;
    if(no[2][x].point!=y)s2+=no[2][x].len,leap++;
    if(no[3][x].point!=y&&leap==1)s2+=no[3][x].len,leap++;
    s3=h[x];
    if(no[1][pre].point!=x)s4=no[1][pre].len;
    else s4=no[2][pre].len;
    s4=max(s4,low[pre]);
    if(no[1][x].point!=y)s4+=no[1][x].len;
    else s4+=no[2][x].len;
    if(pre!=0)s4++;
    return max(max(s1,s2),max(s3,s4));
}
void spfa(int x,int pre)
{
    int visit[maxn];
    memset(visit,0,sizeof(visit));
    queue<int>q;
    queue<int>qp;
    q.push(x);
    qp.push(pre);
    visit[x]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        pre=qp.front();
        qp.pop();
        for(int i=head[x]; i!=-1; i=node[i].next)
        {
            int y=node[i].v;
            if(y==pre)continue;
            h[y]=chu(pre,x,y);
            int ss=max(h[y],f[y])*node[i].w;
            if(ss<maxx)
            {
                maxx=ss;
                ipos=node[i].number;
            }
            else if(ss==maxx)ipos=min(ipos,node[i].number);
            q.push(y);
            qp.push(x);
        }
    }
}
void panlow(int x,int pre)
{
    for(int i=head[x]; i!=-1; i=node[i].next)
    {
        int y=node[i].v;
        if(y==pre)continue;
        if(y!=no[1][x].point)
        {
            low[y]=max(no[1][x].len+1,low[x]+1);
        }
        else low[y]=max(no[2][x].len+1,low[x]+1);
        panlow(y,x);
    }
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        init();
        if(dfs(1,0));
        panlow(1,0);
        spfa(1,0);
        printf("Case #%d: %d\n",t,ipos);
    }
    return 0;
}
