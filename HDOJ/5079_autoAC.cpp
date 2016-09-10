#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <memory>
#include <utility>
#include <string>
#include <sstream>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
typedef double lf;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<lf,lf> pdd;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int inf=1000000007;
const ll linf=1000000000000000000LL;
const ull ulinf=(1ULL<<63)-10ULL;
const lf eps=0.000000001;
const lf pi=3.14159265358979323846;
template <class T> T abs(T a){return a>=0?a:-a;}
template <class T> int sign(T a){return a>eps?1:a<-eps?-1:0;}
template <class T> T sqr(T a){return a*a;}
template <class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template <class T> T mod(T a,T b){T ret=a%b;if(ret<0)ret+=b;return ret;}
template <class T> T lowbit(T x){return x&-x;}
ll addmod(ll a,ll b,ll c){return ((a+b)%c+c)%c;}
ll mulmod(ll a,ll b,ll c){if(b==0LL)return 0LL;ll ret=mulmod(a,b>>1,c);ret=(ret+ret)%c;if(b&1LL)ret=(ret+a)%c;return ret;}
ll powmod(ll a,ll b,ll c){if(b==0LL)return 1LL;ll ret=powmod(a,b>>1,c);ret=ret*ret%c;if(b&1LL)ret=ret*a%c;return ret;}
ll modinv(ll a,ll b){return powmod(a,b-2LL,b);}
template <class T> void maxe(T &a,T b){if(a<b)a=b;}
template <class T> void mine(T &a,T b){if(a>b)a=b;}
int iszero(lf a){return a<=eps&&a>=-eps;}
template <class T> void geti(T &a){a=0;T b=1;char c=getchar();if(c=='-')b=-1;else a=c-48;while((c=getchar())!=' '&&c!='\n')a=a*10+c-48;a*=b;}
#define DEBUG(X) 
const int N=11;
const int M=111111;
const int K=33;
const ll md=inf;
int test;
int n,m,k,ans;
int cnt;
char s[N];
int a[N];
int flag[N];
int dp[N][M];
int powsz[N];
int aa[N];
int main()
{ 
    scanf("%d",&test);
    for(int tc=1;tc<=test;tc++)
    {
        scanf("%d",&n);
        m=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s);
            a[i]=0;
            for(int j=0;j<n;j++)
                if(s[j]=='o')
                    m=m*2%md;
                else
                    a[i]|=1<<j;
        }
        aa[0]=1;
        aa[1]=(m-1+md)%md;
        for(int sz=2;sz<=n;sz++)
        {
            int cntst=1;
            powsz[0]=1;
            k=n+1-sz;
            for(int i=1;i<=k;i++)
                powsz[i]=cntst*=sz;
            dp[0][0]=1;
            for(int st=1;st<cntst;st++)
                dp[0][st]=0;
            for(int i=1;i<=n;i++)
            {
                for(int st=0;st<cntst;st++)
                    dp[i][st]=0;
                for(int cur=0;cur<(1<<n);cur++)
                {
                    if(cur&a[i])
                        continue;
                    for(int j=0;j<k;j++)
                        flag[j]=0;
                    for(int bit=0;bit<n;bit++)
                    {
                        if(cur&(1<<bit))
                            continue;
                        for(int j=0;j<k;j++)
                            if(bit>=j&&bit<j+sz)
                                flag[j]=1;
                    }
                    for(int st=0;st<cntst;st++)
                    {
                        if(!dp[i-1][st])
                            continue;
                        int newst=0;
                        for(int j=0;j<k;j++)
                        {
                            int t=st/powsz[j]%sz;
                            if(flag[j])
                                t=0;
                            else if(t!=sz-1)
                                t++;
                            else
                            {
                                newst=-1;
                                break;
                            }
                            newst+=t*powsz[j];
                        }
                        if(newst==-1)
                            continue;
                        dp[i][newst]=(dp[i][newst]+dp[i-1][st])%md;
                    }
                }
            }
            aa[sz]=0;
            for(int st=0;st<cntst;st++)
                aa[sz]=(aa[sz]+dp[n][st])%md;
            aa[sz]=(m-aa[sz]+md)%md;
            aa[sz-1]=(aa[sz-1]-aa[sz]+md)%md;
        }
        for(int sz=0;sz<=n;sz++)
            printf("%d\n",aa[sz]);
    }
    return 0;
}
