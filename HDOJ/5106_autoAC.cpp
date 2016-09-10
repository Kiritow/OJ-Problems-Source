#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,-1,sizeof(x))
using namespace std;
typedef long long LL;
const int maxn = 1005;
const double eps = 1e-3;
const int inf = 0x7fffffff;
char p[maxn];
const LL mod = 1000000007;
LL c[maxn][maxn];
LL q[maxn];
void init()
{
    for(int i = 0 ; i < maxn ; ++i){
        c[i][0] = 1;
    }
    for(int i = 1 ; i < maxn ; i++){
        for(int j = 1 ; j <= i ; ++j){
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
        }
    }
    q[0] = 1;
    for(int i = 1;i < maxn;++i){
        q[i] = (q[i - 1]*2)%mod;
    }
}
int main()
{
    init();
    int n,k;
    while(~scanf("%d%s",&n,p)){
        int m = strlen(p);
        int k = 0;
        LL ans = 0,tmp = 0;
        for(int st = 0;st < m;++st){
            if(p[st] == '1'){
                ans += ((m-st-2>=0&&n-k-1>=0?c[m - st - 2][n - k - 1]:0) * (q[m - st - 1] - 1))%mod;
                ans += (tmp * q[m - st]%mod * (m-st-1>=0&&n-k>=0?c[m - st - 1][n - k]:0))%mod;
                ans %= mod;
            }
            tmp = (tmp*2 + p[st] - '0')%mod;
            k += p[st] - '0';
        }
        if(ans < 0) ans += mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
