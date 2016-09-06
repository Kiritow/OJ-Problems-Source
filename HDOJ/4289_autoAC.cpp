#include<cstdio>
#include<cstring>
using namespace std;
const int inf=1<<30;
const int nMax=10105;
const int mMax=3000005;
struct Node
{
    int c,u,v,next;
    void insert(int nu,int nv,int nc,int nnext)
    {
        u=nu;
        v=nv;
        c=nc;
        next=nnext;
    }
}edge[mMax];
int ne,head[nMax];
int cur[nMax],ps[nMax],dep[nMax];
void addedge(int u,int v,int w) 
{
    edge[ne].insert(u,v,w,head[u]);
    head[u]=ne++;
    edge[ne].insert(v,u,0,head[v]);
    head[v]=ne++;
}
int dinic(int s, int t){                       
    int tr, res = 0;
    int i, j, k, f, r, top;
    while(1){
        memset(dep, -1, sizeof(dep));
        for(f = dep[ps[0]=s] = 0, r = 1; f != r;)
        {
            for(i = ps[f ++], j = head[i]; j; j = edge[j].next)
            {
                if(edge[j].c && dep[k=edge[j].v] == -1)
                {
                    dep[k] = dep[i] + 1;
                    ps[r ++] = k;
                    if(k == t)
                    {
                        f = r; break;
                    }
                }
            }
        }
        if(dep[t] == -1) break;
        memcpy(cur, head, sizeof(cur));
        i = s, top = 0;
        while(1)
        {
            if(i == t)
            {
                for(tr =inf, k = 0; k < top; k ++)
                {
                    if(edge[ps[k]].c < tr)
                    {
                        tr = edge[ps[f=k]].c;
                    }
                }
                for(k = 0; k < top; k ++)
                {
                    edge[ps[k]].c -= tr;
                    edge[ps[k]^1].c += tr;
                }
                i = edge[ps[top=f]].u;
                res += tr;
            }
            for(j = cur[i]; cur[i]; j = cur[i] =edge[cur[i]].next)
            {
                if(edge[j].c && dep[i]+1 == dep[edge[j].v])
                {
                    break;
                }
            }
            if(cur[i])
            {
                ps[top ++] = cur[i];
                i = edge[cur[i]].v;
            }
            else
            {
                if(top == 0)
                {
                    break;
                }
                dep[i] = -1;
                i = edge[ps[-- top]].u;
            }
        }
    }
    return res;
}
int main()
{
    int i,j,a,b,s,t,m,n;
    while(~scanf("%d%d%d%d",&n,&m,&s,&t))
    {
        ne=2;
        memset(head,0,sizeof(head));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            addedge(i,i+n,a);
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            addedge(a+n,b,inf);
            addedge(b+n,a,inf);
        }
        int res=dinic(s,t+n);
        printf("%d\n",res);
    }
    return 0;
}
