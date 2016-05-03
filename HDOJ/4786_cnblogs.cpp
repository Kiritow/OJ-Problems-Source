#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 100100
using namespace std;

struct edge{
    int u,v;
}a[2][maxn];

int s[2];
int n,m,c,t,uu,vv,cc,MM,mm,cas=0;
int f[maxn],g[maxn];
bool flag;

void init() { for (int i=1; i<=n; i++) f[i]=i; }

void build(int xx,int yy) { f[f[xx]]=f[yy]; }

int getf(int x)
{
    if (f[x]!=x) f[x]=getf(f[x]);
    return f[x];
}

void addedge(int x)
{
    int tot=0;
    init();
    for (int i=1; i<=s[x]; i++)
        if (getf(a[x][i].u)!=getf(a[x][i].v)) tot++,build(a[x][i].u,a[x][i].v);
    if (x==0) mm=n-1-tot;
        else MM=tot;
}

int main()
{
    g[1]=1,g[2]=2;
    for (int i=2; g[i]<=maxn; i++) g[i+1]=g[i]+g[i-1];
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        s[0]=s[1]=0;
        for (int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&uu,&vv,&cc);
            a[cc][++s[cc]].u=uu;
            a[cc][s[cc]].v=vv;
        }
        init();
        for (int i=1; i<=s[0]; i++)
            if (getf(a[0][i].u)!=getf(a[0][i].v)) build(a[0][i].u,a[0][i].v);
        for (int i=1; i<=s[1]; i++)
            if (getf(a[1][i].u)!=getf(a[1][i].v)) build(a[1][i].u,a[1][i].v);
        flag=true;
        for (int i=2; i<=n; i++)
            if (getf(i)!=getf(i-1)) { flag=false; break; }
        if (!flag) 
        {
            printf("Case #%d: No\n",++cas);
            continue;
        }
        addedge(0),addedge(1);
        //cout<<" MM && mm : " <<mm<<' '<<MM<<endl;
        flag=false;
        for (int i=1; g[i]<=n; i++)
            if (g[i]<=MM && g[i]>=mm) { flag=true; break; }
        if (flag) printf("Case #%d: Yes\n",++cas);
            else printf("Case #%d: No\n",++cas);
    }
    return 0;
}
