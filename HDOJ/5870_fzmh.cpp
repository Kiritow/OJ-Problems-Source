#include<cstdio>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
using namespace std;
const int N = 201010;
const int M = 2010101;
const int inf = 2100000000;
typedef pair<int,int> P; 
priority_queue<P,vector<P>,greater<P> > Q;
int n,m,i,a,b,c,dis[N],cnt[N],dis1[N],cnt1[N],dis2[N],cnt2[N],X;
int id[N],ID[N],Id[N];
vector<P> e[N];
void gao(int x)
{
    int i;
    for (i=1;i<=n;i++)
    dis[i]=inf,cnt[i]=0;
    dis[x]=0;
    cnt[x]=1;
    Q.push(mp(0,x));
    while (!Q.empty())
    {
        P tmp=Q.top();
        Q.pop();
        x=tmp.sc;
        if (dis[x]!=tmp.fi) continue;
        for (i=0;i<e[x].size();i++)
        if (dis[x]+e[x][i].sc<dis[e[x][i].fi])
        {
            dis[e[x][i].fi]=dis[x]+e[x][i].sc;
            cnt[e[x][i].fi]=cnt[x];
            Q.push(mp(dis[e[x][i].fi],e[x][i].fi));
        }
        else
        if (dis[x]+e[x][i].sc==dis[e[x][i].fi])
        {
            cnt[e[x][i].fi]+=cnt[x];
            if (cnt[e[x][i].fi]>X) cnt[e[x][i].fi]=X;
        }
    }
}

int ls[M],rs[M],s[M],tot,root[N];
void build(int &x,int a,int b)
{
    x=++tot;
    ls[x]=rs[x]=s[x]=0;
    if (b-a>1)
    {
        int m=(a+b)>>1;
        build(ls[x],a,m);
        build(rs[x],m,b);
    }
}
void insert(int y,int &x,int a,int b,int l,int r)
{
    x=++tot;
    ls[x]=ls[y];rs[x]=rs[y];s[x]=s[y]+1;
    if ((a<=l)&&(r<=b))
    return;
    int m=(l+r)>>1;
    if (a<m) insert(ls[y],ls[x],a,b,l,m);
    if (m<b) insert(rs[y],rs[x],a,b,m,r);
}
int query(int x,int a,int b,int l,int r)
{
    if ((a<=l)&&(r<=b))
    return s[x];
    int m=(l+r)>>1,ans=0;
    if (a<m) ans+=query(ls[x],a,b,l,m);
    if (m<b) ans+=query(rs[x],a,b,m,r);
    return ans;
}
bool cmp(int a,int b)
{
    return dis2[a]<dis2[b];
}
bool CMP(int a,int b)
{
    return cnt2[a]>cnt2[b];
}
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
    if (n+m==0) return 0;
    for (i=1;i<=n;i++) e[i].clear();
    scanf("%d",&X);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        e[a].pb(mp(b,c));
        e[b].pb(mp(a,c));
    }
    gao(1);
    for (i=1;i<=n;i++)
    dis1[i]=dis[i],cnt1[i]=cnt[i];
    gao(n);
    for (i=1;i<=n;i++)
    dis2[i]=dis[i],cnt2[i]=cnt[i];
    
    tot=0;
    build(root[0],0,n);
    for (i=1;i<=n;i++)
    id[i]=i;
    sort(id+1,id+1+n,cmp);
    for (i=1;i<=n;i++)
    ID[id[i]]=i;
    
    for (i=1;i<=n;i++)
    Id[i]=i;
    sort(Id+1,Id+1+n,CMP);
    for (i=1;i<=n;i++)
        insert(root[i-1],root[i],ID[Id[i]]-1,ID[Id[i]],0,n);
    long long ans=0;
    for (i=1;i<=n;i++)
    {
        int l=1,r=n;
        while (l<=r)
        {
            m=(l+r)>>1;
            if (dis2[id[m]]+dis1[i]+1<=dis1[n]) l=m+1;else r=m-1;
        }
        int j=r;

        l=1;r=n;
        while (l<=r)
        {
            m=(l+r)>>1;
            if (1LL*cnt1[i]*cnt2[Id[m]]>=X) l=m+1;else r=m-1;
        }
        
        if (j) ans=ans+query(root[r],0,j,0,n);
        
        
        for (int k=0;k<e[i].size();k++)
        if (dis2[e[i][k].fi]+1+dis1[i]<=dis1[n])
        if (1LL*cnt1[i]*cnt2[e[i][k].fi]>=X) ans--;
    
        if (dis1[i]+dis2[i]+1<=dis1[N])
        if (1LL*cnt1[i]*cnt2[i]>=X) ans--;
        
    }
    printf("%lld\n",ans);
    }
}
