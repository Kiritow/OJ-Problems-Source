#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 30050
struct Q
{
    int r,idx;
    Q(int _r=0,int _idx=0):r(_r),idx(_idx){}
};
vector<Q>que[N];
vector<int>edge[N];
int fa[N][200],scc[200],rr[200];
int ta[N],first[N],ans[N];
int n,m,tot,every;
int find(int i,int pos)
{
    return fa[i][pos]==i?i:fa[i][pos]=find(fa[i][pos],pos);
}
void init()
{
    for(int i=0;i<=n;++i)
        edge[i].clear(),que[i].clear();
    memset(scc,0,sizeof(scc));
    every=tot=sqrt(n*1.0);
    if(n*n!=tot) tot++;
    for(int i=0;;++i)
    {
        rr[i]=i*every;
        if(i*every>=n) break;
    }
    for(int i=0;i<=tot;++i)
        for(int j=0;j<=n;++j)
        fa[j][i]=j;
    memset(first,-1,sizeof(first));
}
int main ()
{
    int T;scanf("%d",&T);
    for(int kk=1;kk<=T;++kk)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1,u,v;i<=m;++i)
        {
            scanf("%d%d",&u,&v);
            if(u==v) continue;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        int q;scanf("%d",&q);
        for(int i=1,u,v;i<=q;++i)
        {
            scanf("%d%d",&u,&v);
            que[u].push_back(Q(v,i));
        }
        int run_clock=0;
        for(int u=n;u>=1;--u)
        {
            for(int j=1;j<=tot;++j)
            {
                if(u>rr[j]) continue;
                scc[j]++;
                int inc=0;
                for(int i=0;i<edge[u].size();++i)
                {
                    int v=edge[u][i];
                    if(u<v&&v<=rr[j])
                    {
                        int u1=find(u,j);
                        int v1=find(v,j);
                        if(u1!=v1)
                        {
                            inc++;
                            fa[v1][j]=u1;
                        }
                    }
                }
                scc[j]-=inc;
            }
            for(int z=0;z<que[u].size();++z)
            {
                run_clock++;
                int right=que[u][z].r;
                int pos;int inc=0;
                for(pos=0;pos<tot;++pos)
                    if(rr[pos]<right&&right<=rr[pos+1]) break;
                for(int i=max(u+1,rr[pos]+1);i<=right;++i)
                {
                    if(first[i]!=run_clock)
                    {
                        first[i]=run_clock;
                        fa[i][tot+1]=i;
                    }
                    for(int j=0;j<edge[i].size();++j)
                        if(u<=edge[i][j]&&edge[i][j]<i)
                        {
                            int v1=find(edge[i][j],pos);
                            if(first[v1]!=run_clock)
                            {
                                first[v1]=run_clock;
                                fa[v1][tot+1]=v1;
                            }
                            if(find(i,tot+1)!=find(v1,tot+1))
                            {
                                fa[find(v1,tot+1)][tot+1]=find(i,tot+1);
                                inc++;
                            }
                        }
                }
                ans[que[u][z].idx]=scc[pos]+right-max(rr[pos],u-1)-inc;
            }
        }
        printf("Case #%d:\n",kk);
        for(int i=1;i<=q;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
