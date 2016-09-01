#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX=210;
int n,cnt,ret;
int p[MAX],ran[MAX];
bool ext[MAX];
struct Edge
{
    int from;
    int to;
    int weight;
    bool operator<(const Edge& edge) const
    {
        if(ext[from]==false||ext[to]==false)
            return false;
        if(ext[edge.from]==false||ext[edge.to]==false)
            return true;
        return weight<edge.weight;
    }
}edge[MAX*MAX];
void Init()
{
    for(int i=0;i<210;i++)
    {
        p[i]=i;
        ran[i]=0;
    }
}
void Link(int x,int y)
{
    if(ran[x]<ran[y])
        p[x]=y;
    else
    {
        p[y]=x;
        if(ran[x]==ran[y])
            ran[x]++;
    }
}
int Find(int x)
{
    if(p[x]!=x)
        p[x]=Find(p[x]);
    return p[x];
}
void Union(int x,int y)
{
    Link(Find(x),Find(y));
}
bool Kruskal()
{
    sort(edge,edge+cnt);
    int done=0;
    Init();
    for(int i=0;i<cnt&&done<n-1;i++)
    {
        if(ext[edge[i].from]==false||ext[edge[i].to]==false)
            break;
        if(Find(edge[i].from)!=Find(edge[i].to))
        {
            done++;
            ret+=edge[i].weight;
            Union(edge[i].from,edge[i].to);
        }
    }
    if(done==n-1)
        return true;
    else
        return false;
}
int main()
{
    int t;
    int x,y,w;
    int nn,ee,m;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        ret=0;
        memset(ext,0,sizeof(ext));
        scanf("%d%d",&nn,&ee);
        n=nn;
        for(int i=0;i<nn;i++)
            ext[i]=true;
        for(int i=0;i<ee;i++)
        {
            scanf("%d%d%D",&x,&y,&w);
            edge[cnt].from=x;
            edge[cnt].to=y;
            edge[cnt].weight=w;
            cnt++;
        }
        scanf("%d%d",&nn,&ee);
        for(int i=n;i<n+nn;i++)
            ext[i]=true;
        n+=nn;
        for(int i=0;i<ee;i++)
        {
            scanf("%d%d%D",&x,&y,&w);
            edge[cnt].from=x;
            edge[cnt].to=y;
            edge[cnt].weight=w;
            cnt++;
        }
        scanf("%d",&m);
        n-=m;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            ext[x]=false;
        }
        if(Kruskal())
            printf("%d\n",ret);
        else
            printf("what a pity!\n");
    }
    return 0;
}
