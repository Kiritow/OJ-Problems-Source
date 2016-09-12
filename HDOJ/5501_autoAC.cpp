#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<time.h>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<map>
#include<set>
#include<bitset>
#define eps 1e-5
#define INF 0x7fffffff
#define FOR(i,a) for((i)=0;i<(a);(i)++)
#define MEM(a) (memset((a),0,sizeof(a)))
#define sfs(a) scanf("%s",a)
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfI(a) printf("%I64d\n",a)
#define pfs(a) printf("%s\n",a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,num) scanf("%d%d%d",&a,&b,&num)
#define for1(i,a,b) for(int i=(a);i<b;i++)
#define for2(i,a,b) for(int i=(a);i<=b;i++)
#define for3(i,a,b)for(int i=(b);i>=a;i--)
#define MEM1(a) memset(a,0,sizeof(a))
#define MEM2(a) memset(a,-1,sizeof(a))
#define ll long long
const double PI=acos(-1.0);
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
using namespace std;
int n,m,L;
#define N 50005
#define M 1000100
#define Mod 1000000007
#define p(x,y) make_pair(x,y)
int dp[5010];
struct Node{
    int a,b,c;
    bool operator <(const Node &x) const{
        return (ll)b*x.c>(ll)x.b*c;
    }
}e[1010];
int main(){
    int T;
    sf(T);
    while(T--){
        int t;
        sfd(n,t);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
        }
        sort(e+1,e+n+1);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=t;j>=e[i].c;j--){
                dp[j] = Max(dp[j],dp[j-e[i].c]+Max(0,e[i].a-j*e[i].b));
            }
        }
        int ans=-INF;
        for(int i=0;i<=t;i++)
            ans = Max(ans,dp[i]);
        pf(ans);
    }
    return 0;
}
