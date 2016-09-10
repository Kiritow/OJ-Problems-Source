#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define ll long long
#define db double
#define PB push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;
const int N = 55;
const db eps = 1e-8;
const db PI = acos(-1.0);
const ll MOD = 1000000007;
int n,m,mp[N][N];
bool mk[N];
ll c;
int sgn(db t)
{
    return t<-eps?-1:t>eps;
}
ll inv(ll t)
{
    ll res=1,k=MOD-2;
    while(k)
    {
        if(k&1) res=(res*t)%MOD;
        t=(t*t)%MOD;
        k>>=1;
    }
    return res;
}
struct E
{
    int a,b;
    void input()
    {
        scanf("%d%d",&a,&b);
    }
} ed[N*N];
struct P
{
    db x,y;
    int id;
    void input()
    {
        int _x,_y;
        scanf("%d%d",&_x,&_y);
        x=_x,y=_y;
    }
    P(db _x=0,db _y=0):x(_x),y(_y){}
    P rot(db thta)
    {
        return P(x*cos(thta)-y*sin(thta),
                 x*sin(thta)+y*cos(thta));
    }
    P rotByP(P center,db thta)
    {
        P tmp(x-center.x,y-center.y);
        P ans=tmp.rot(thta);
        ans=ans+center;
        return ans;
    }
    P operator + (const P &t) const
    {
        return P(x+t.x,y+t.y);
    }
    bool operator == (const P &t) const
    {
        return sgn(x-t.x)==0&&sgn(y-t.y)==0;
    }
}p[N],pb,np[N];
int pt[N];
ll g,ans;
bool check()
{
    for(int i=0;i<m;i++)
    {
        int a=ed[i].a,b=ed[i].b;
        a=pt[a],b=pt[b];
        if(mp[a][b]&&mp[b][a]){}
        else return false;
    }
    return true;
}
bool fl[N];
int find_t()
{
    memset(fl,false,sizeof(fl));
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(!fl[i])
        {
            res++;
        }
        int t=i;
        while(!fl[t]) fl[t]=true,t=pt[t];
    }
    return res;
}
void dfs(int k)
{
    if(k==n)
    {
        if(check())
        {
            int t=find_t();
            g++;
            ll res=1;
            for(int i=0;i<t;i++) res=res*c%MOD;
            ans=(ans+res)%MOD;
        }
    }else
    {
        for(int i=0;i<n;i++)
            if(!mk[i]&&np[k]==p[i])
        {
            mk[i]=true;
            pt[k]=i;
            dfs(k+1);
            mk[i]=false;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%I64d",&n,&m,&c);
        pb.x=pb.y=0.0;
        for(int i=0;i<n;i++)
        {
            p[i].input();
            p[i].id=i;
            pb.x+=p[i].x,pb.y+=p[i].y;
        }
        pb.x/=(db)n,pb.y/=(db)n;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<m;i++)
        {
            ed[i].input();
            ed[i].a--,ed[i].b--;
            mp[ed[i].a][ed[i].b]=mp[ed[i].b][ed[i].a]=1;
        }
        ans=0,g=0;
        memset(mk,false,sizeof(mk));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<n;j++)
                np[j]=p[j].rotByP(pb,i*PI/2.0);
            dfs(0);
        }
        printf("%I64d\n",ans*inv(g)%MOD);
    }
    return 0;
}
