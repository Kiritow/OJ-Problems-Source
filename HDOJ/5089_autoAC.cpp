#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
#define clr1(x) memset(x,-1,sizeof(x))
#define eps 1e-9
const double pi = acos(-1.0);
typedef long long LL;
typedef unsigned long long ULL;
const int modo = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int inf = 0x3fffffff;
const LL _inf = 1e18;
const int maxn = 55,maxm = 1<<12;
int n,k;
bool vis[maxn];
double p[maxn];
int pos[maxn],s[maxn];
int main()
{
    int _,_g;RD(_);
    while(_--){
        RD2(n,k);
        clr0(vis);
        for(int i = 0;i < n;++i){
            RD(s[i]);
            p[i] = ((double)s[i])/100.0;
        }
        double mx = 0;
        for(int g = 0;g <= k;++g){//╁g涓k - g涓
            double _p,res = 0;
            int cnt = 0;
            for(int i = 0;i < g;++i)
                pos[cnt++] = i;
            for(int i = 1;i <= k - g;++i)
                pos[cnt++] = n - i;
            for(int i = 0;i < cnt;++i){
                _p = 1;
                for(int j = 0;j < cnt;++j){
                    if(j != i)
                        _p *= p[pos[j]];
                    else
                        _p *= (1 - p[pos[j]]);
                }
                res += _p;
            }
            if(mx - res < eps){
                mx = res;
                _g = g;
            }
        }
        for(int i = 0;i < _g;++i)
            vis[i] = 1;
        for(int i = n - (k - _g);i < n;++i){
            for(int j = i;j >= 0;--j){
                if(vis[j] || s[j] > s[i])
                    break;
                _g = j;
            }
            vis[_g] = 1;
        }
        _g = 1;
        for(int i = 0;i < n;++i)
            if(vis[i])
                printf("%d%c",i+1," \n"[_g == k]),_g++;
    }
    return 0;
}
