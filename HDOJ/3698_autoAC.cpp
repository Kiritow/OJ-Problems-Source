#include<cstdio>
#include<cstring>
using namespace std;
#define inf 1073741823
#define N 105
#define M 5005
int t[N][M];
int f[N][M];
int dp[N][M];
int summ[M<<2],add[M<<2];
inline int min(int a,int b)
{
    return a<b?a:b;
}
void push_down(int idx)
{
    if(add[idx]!=inf)
    {
        add[idx<<1]=min(add[idx<<1],add[idx]);
        add[idx<<1|1]=min(add[idx<<1|1],add[idx]);
        summ[idx<<1]=min(summ[idx<<1],add[idx<<1]);
        summ[idx<<1|1]=min(summ[idx<<1|1],add[idx<<1|1]);
        add[idx]=inf;
    }
}
void build(int l,int r,int idx)
{
    summ[idx]=inf;
    add[idx]=inf;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(l,mid,idx<<1);
    build(mid+1,r,idx<<1|1);
}
void update(int a,int b,int w,int l,int r,int idx)
{
    if(a<=l&&r<=b)
    {
        add[idx]=min(w,add[idx]);
        summ[idx]=min(add[idx],summ[idx]);
        return;
    }
    int mid=(l+r)>>1;
    push_down(idx);
    if(a<=mid) update(a,b,w,l,mid,idx<<1);
    if(mid<b)  update(a,b,w,mid+1,r,idx<<1|1);
    summ[idx]=min(summ[idx<<1],summ[idx<<1|1]);
}
int query(int a,int b,int l,int r,int idx)
{
    if(a<=l&&r<=b)
       return summ[idx];
    int mid=(l+r)>>1;
    push_down(idx);
    int res=inf;
    if(a<=mid) res=min(res,query(a,b,l,mid,idx<<1));
    if(mid<b)  res=min(res,query(a,b,mid+1,r,idx<<1|1));
    return res;
}
inline void scan(int &n)
{
    char cc ;
    for(;cc=getchar(),cc<'0'||cc>'9';);
    n=cc-'0';
    for(;cc=getchar(),cc>='0'&&cc<='9';)
        n=n*10+cc-'0';
}
int main()
{
    int n,m;
    for(;scanf("%d%d",&n,&m)&&(n!=0||m!=0);)
    {
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scan(t[i][j]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                scan(f[i][j]);
        for(int i=1;i<=m;++i)
            dp[1][i]=t[1][i];
        for(int i=2;i<=n;++i)
        {
            build(1,m,1);
            for(int j=1;j<=m;++j)
                update(j-f[i-1][j],j+f[i-1][j],dp[i-1][j],1,m,1);
            for(int j=1;j<=m;++j)
                dp[i][j]=query(j-f[i][j],j+f[i][j],1,m,1)+t[i][j];
        }
        int ans=inf;
        for(int i=1;i<=m;++i)
            ans=min(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
