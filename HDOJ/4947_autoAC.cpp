#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
typedef long long LL;
const int N = 200000+20;
bool check[N];
int mu[N],prime[N];
vector<int> fac[N];
LL f[N];
int l,q;
void Mobius()
{
    CLR(check, 0);
    mu[1] = 1;
    int tot = 0;
    for(int i = 2; i < N ; i++){
        if(!check[i]){
            prime[tot ++] = i;
            mu[i] = -1;
        }
        for(int j = 0 ;j < tot; j ++){
            if(i * prime[j] >= N)break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            }else{
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for(int i = 1 ;i < N ; i++){
        for(int j = i ; j < N ; j += i){
            fac[j].push_back(i);
        }
    }
}
inline LL sum(int p){
    LL s = 0;
    while(p > 0){
        s += f[p];
        p -= p & (-p);
    }
    return s;
}
inline void add(int p,int v){
    while(p <= l){
        f[p] += v;
        p += (p) & (-p);
    }
}
void update(int n,int d,int v){
    if(n % d != 0)return;
    n = n/d;
    for(int i = 0 ;i < fac[n].size() ; i++){
        int q = fac[n][i];
        add(q * d, v * mu[q]);
    }
}
LL query(int p)
{
    LL ans = 0;
    for(int i = 1,last = i ; i <= p ; i = last + 1){
        last = p/(p/i);
        ans += (LL)(p/i) * (sum(last) - sum(i-1)) ;
    }
    return ans;
}
int main()
{
    Mobius();
    int cas = 0;
    while(~scanf("%d%d",&l,&q)){
        if(l == 0 && q == 0)break;
        CLR(f, 0);
        cas ++;
        printf("Case #%d:\n",cas);
        while(q--){
            int t;
            scanf("%d",&t);
            if(t == 1){
                int n,d,v;
                scanf("%d%d%d",&n,&d,&v);
                update(n, d, v);
            }else{
                int x;
                scanf("%d",&x);
                printf("%I64d\n",query(x));
            }
        }
    }
    return 0;
}
