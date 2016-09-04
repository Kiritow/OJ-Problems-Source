#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<deque>
#include<map>
#include<queue>
#define iinf 2000000000
#define linf 1000000000000000000LL
#define dinf 1e200
#define eps 1e-5
#define lng long long
#define sqr(a) ((a)*(a))
#define pi 3.14159265359
#define ff(i,xi,n) for(int i=xi;i<=(int)(n);++i)
#define ffd(i,xi,n) for(int i=xi;i>=(int)(n);--i)
#define ffl(i,r) for(int i=head[r];i!=-1;i=edge[i].next)
#define cc(i,j) memset(i,j,sizeof(i))
#define two(x)            ((lng)1<<(x))
#define N 11111
#define M 1000000
#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
#define Mod  n
#define Pmod(x) (x%Mod+Mod)%Mod
using namespace std;
typedef vector<int>  vi;
typedef vector<string>  vs;
typedef unsigned int uint;
typedef unsigned lng ulng;
template<class T> inline void checkmax(T &x,T y){if(x<y) x=y;}
template<class T> inline void checkmin(T &x,T y){if(x>y) x=y;}
template<class T> inline T Min(T x,T y){return (x>y?y:x);}
template<class T> inline T Max(T x,T y){return (x<y?y:x);}
template<class T> T gcd(T a,T  b){return (a%b)==0?b:gcd(b,a%b);}
template<class T> T lcm(T a,T b){return a*b/gcd(a,b);}
template<class T> T Abs(T a){return a>0?a:(-a);}
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline bool isPrimeNumber(T n)
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T Minmin(T a,T b,T c,T d){return Min(Min(a,b),Min(c,d));}
int dp[N][2][2],ini[N],head[N],tot,n;
struct pp
{
    int v,next;
}edge[N*2];
inline void add(int u,int v)
{
    edge[tot].v=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
void dfs(int  r,int pre)
{
    int clo=ini[r],rev=1-clo;
    int sum=0,dps[3]={};
    dps[1]=dps[2]=iinf;
    ffl(i,r)
    {
        int v=edge[i].v;
        if(v==pre) continue;
        dfs(v,r);
        sum+=dp[v][clo][0];
        dps[2]=Min(dps[1]+dp[v][rev][1],dps[2]+dp[v][rev][0]);
        dps[1]=Min(dps[0]+dp[v][rev][1],dps[1]+dp[v][rev][0]);
        dps[0]+=dp[v][rev][0];
    }
    dp[r][clo][0]=Minmin(sum,dps[0]+2,dps[1]+2,dps[2]+2);
    dp[r][clo][1]=Min(dps[1]+1,dps[0]+1);
    dp[r][rev][0]=Minmin(sum+1,dps[0]+1,dps[1]+1,dps[2]+1);
    dp[r][rev][1]=Min(dps[0],dps[1]);
}
int main()
{
    int o=0;
    while(scanf("%d",&n)==1)
    {
        cc(head,-1);
        tot=0;
        ff(i,2,n)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
            add(v,u);
        }
        ff(i,1,n)
        scanf("%d",ini+i);
        dfs(1,-1);
        printf("Case %d: %d\n",++o,Min(dp[1][0][0],dp[1][1][0]));
    }
    return 0;
}
