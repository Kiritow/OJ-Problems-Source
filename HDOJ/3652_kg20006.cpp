#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll num[30];
ll dp[30][15][5];
ll dfs(int pos, int mod, int st, bool f){
    if(pos < 1) return st == 2 && mod == 0;
    if(!f && dp[pos][mod][st] != -1) return dp[pos][mod][st];
    int end = f? num[pos] : 9;
    ll res = 0;
    for(int i = 0; i <= end; ++i){
        int nmod = (mod*10 + i) %13;
        bool nf = (f && i == end);
        if(st == 2 || (st == 1 && i == 3)) res += dfs(pos-1, nmod, 2, nf);
        else if(i == 1) res += dfs(pos-1, nmod, 1, nf);
        else res += dfs(pos-1, nmod, 0, nf);
    }
    if(!f) dp[pos][mod][st] = res;
    return res;
}
ll solve(ll n){
    int len = 0;
    while(n){
        num[++len] = n%10;
        n /= 10;
    }
    return dfs(len, 0, 0, 1);
}
int main(){
    ll n;
    while(scanf("%lld", &n) != EOF){
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(n));
    }
}
