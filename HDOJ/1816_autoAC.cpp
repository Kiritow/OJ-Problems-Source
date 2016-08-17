#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=2000+50;
int n,m;
int a[maxn],b[maxn];
int c[maxn],d[maxn];
struct TwoSAT
{
    int n;
    vector<int> G[maxn*2];
    int S[maxn*2],c;
    bool mark[maxn*2];
    bool dfs(int x)
    {
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for(int i=0;i<G[x].size();i++)
            if(!dfs(G[x][i])) return false;
        return true;
    }
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<2*n;i++) G[i].clear();
        memset(mark,0,sizeof(mark));
    }
    void add_clause(int x,int xval,int y,int yval)
    {
        x=x*2+xval;
        y=y*2+yval;
        G[x].push_back(y);
    }
    bool solve()
    {
        for(int i=0;i<2*n;i+=2)
        if(!mark[i] && !mark[i+1])
        {
            c=0;
            if(!dfs(i))
            {
                while(c>0) mark[S[--c]]=false;
                if(!dfs(i+1)) return false;
            }
        }
        return true;
    }
}TS;
bool ok(int mid)
{
    TS.init(n);
    for(int i=0;i<n/2;i++)
    {
        TS.add_clause(a[i],0,b[i],1);
        TS.add_clause(b[i],0,a[i],1);
    }
    for(int i=0;i<mid;i++)  
    {
        TS.add_clause(c[i],1,d[i],0);
        TS.add_clause(d[i],1,c[i],0);
    }
    return TS.solve();
}
int main()
{
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        n*=2;
        for(int i=0;i<n/2;i++)  scanf("%d%d",&a[i],&b[i]);
        for(int i=0;i<m;i++)    scanf("%d%d",&c[i],&d[i]);
        int L=0, R=m;
        while(R>L)
        {
            int mid = L+(R-L+1)/2;
            if(ok(mid)) L=mid;
            else R=mid-1;
        }
        printf("%d\n",L);
    }
    return 0;
}
