#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3f3f3f
using namespace std;
const int maxn=60;
const int maxr=maxn*maxn+maxn;
int n,D;
int child[maxn];
int boys;
bool flag;
int map[maxn][maxn];
void init_m()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==j)
            {
                map[i][j]=0;
            }
            else
            {
                map[i][j]=inf;
            }
        }
}
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(map[i][k]+map[k][j]<map[i][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                }
            }
}
struct node
{
    int l,r;
    int u,d;
    int s,c;
};
node dlx[maxr];
int h[maxn];
int limit;
int Q[maxn];
int X[maxr];
int has[maxn];
int head,size;
void init(int r,int c)
{
    head=0;
    for(int i=0; i<=c; i++)
    {
        dlx[i].s=0;
        dlx[i].u=dlx[i].d=i;
        dlx[i].r=i+1;
        dlx[i+1].l=i;
    }
    size=c;
    dlx[c].r=0;
    while(r)
    {
        h[r--]=-1;
    }
}
void link(int r,int c)
{
    int tmp=++size;
    dlx[c].s++;
    dlx[tmp].c=c;
    X[tmp]=r;
    dlx[tmp].d=dlx[c].d;
    dlx[tmp].u=c;
    dlx[dlx[c].d].u=tmp;
    dlx[c].d=tmp;
    if(h[r]<0)
    {
        h[r]=dlx[tmp].l=dlx[tmp].r=tmp;
    }
    else
    {
        dlx[tmp].r=dlx[h[r]].r;
        dlx[tmp].l=h[r];
        dlx[dlx[h[r]].r].l=tmp;
        dlx[h[r]].r=tmp;
    }
}
void remove(int x)
{
    for(int i=dlx[x].d; i!=x; i=dlx[i].d)
    {
        dlx[dlx[i].r].l=dlx[i].l;
        dlx[dlx[i].l].r=dlx[i].r;
        dlx[dlx[i].c].s--;
    }
}
void resume(int x)
{
    for(int i=dlx[x].u; i!=x; i=dlx[i].u)
    {
        dlx[dlx[i].r].l=i;
        dlx[dlx[i].l].r=i;
        dlx[dlx[i].c].s++;
    }
}
int hh()
{
    int ret=0;
    memset(has,0,sizeof(has));
    for(int i=dlx[head].r; i!=head; i=dlx[i].r)
    {
        if(has[i]==false)
        {
            has[i]=true;
            ret++;
            for(int j=dlx[i].d; j!=i; j=dlx[j].d)
            for(int k=dlx[j].r; k!=j; k=dlx[k].r)
            {
                has[dlx[k].c]=true;
            }
        }
    }
    return ret;
}
void dlx_dfs(int k)
{
    if(k+hh()>boys)
    {
        return;
    }
    int ssd=0;
    for(int i=0;i<k;i++)
    {
        ssd+=child[Q[i]];
    }
    if(k-ssd>=limit) return;
    if(dlx[head].r==head)
    {
        flag=true;
        limit=k-ssd;
        return;
    }
    int minn=n+2;
    int tt;
    for(int i=dlx[head].r; i!=head; i=dlx[i].r)
    {
        if(minn>dlx[i].s)
        {
            minn=dlx[i].s;
            tt=i;
        }
    }
    for(int i=dlx[tt].d; i!=tt; i=dlx[i].d)
    {
        Q[k]=X[i];
        remove(i);
        for(int j=dlx[i].r; j!=i; j=dlx[j].r)
        {
            remove(j);
        }
        dlx_dfs(k+1);
        for(int j=dlx[i].l; j!=i; j=dlx[j].l)
        {
            resume(j);
        }
        resume(i);
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        printf("Case #%d: ",cas++);
        scanf("%d%d",&n,&D);
        boys=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&child[i]);
            if(child[i]==1)
            {
                boys++;
            }
        }
        init_m();
        int a,b,c;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=c;
            map[b][a]=c;
        }
        floyd();
        init(n,n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(map[i][j]<=D)
                {
                    link(i,j);
                }
            }
            flag=false;
            limit=inf;
        dlx_dfs(0);
        if(!flag)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",limit);
        }
    }
    return 0;
}
