#include <cstdio>
#include <cstring>
#define N 1005
#define M 505
#define CLR(a,v) memset(a,v,sizeof(a))
struct Edge
{
    int v,next;
}edge[N*M];
int ehead[N];
int ecnt;
inline void AddEdge(int u,int v)
{
    edge[ecnt]={v,ehead[u]};
    ehead[u]=ecnt++;
}
int match[M][N];
int mcnt[N];
bool vis[M];
int limit;
bool Find(int u)
{
    for(int i=ehead[u];~i;i=edge[i].next)
    {
        int v=edge[i].v;
        if(vis[v])continue;
        vis[v]=true;
        if(mcnt[v]<limit)
        {
            match[v][mcnt[v]++]=u;
            return true;
        }
        for(int j=0;j<mcnt[v];j++)if(Find(match[v][j]))
        {
            match[v][j]=u;
            return true;
        }
    }
    return false;
}
bool Match(int n)
{
    CLR(mcnt,0);
    for(int i=0;i<n;i++)
    {
        CLR(vis,false);
        if(!Find(i))return false;
    }
    return true;
}
bool lof;
bool Int(int &a)
{
    if(lof)return lof=false;
    char c;
    for(c=getchar();c<'0'||c>'9';c=getchar())if(c=='\n')return false;
    a=c-'0';
    for(c=getchar();c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
    lof=c=='\n';
    return true;
}
char s[20];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n)
    {
        CLR(ehead,-1);ecnt=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            int a;
            lof=false;
            while(Int(a))AddEdge(i,a);
        }
        int l=1,r=n;
        while(l<r)
        {
            int m=(l+r)/2;
            limit=m;
            if(Match(n))
                r=m;
            else
                l=m+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
