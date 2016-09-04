#include<cstdio>
#include<cstring>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 20;
ll dp[N][10][1<<10][11];
int has[1<<10];
int ne[1<<10][10];
int bit[N],K;
int go(int mask,int number){
    int pos = -1;
    for(int i = number;i <=9;i++)
        if(mask & (1<<i)){
            pos = i;
            break;
        }
    if(pos == -1)mask |= 1<<number;
    else{
        mask ^= 1<<pos;
        mask |= 1<<number;
    }
    return mask;
}
void init(){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<1<<10;i++){
        has[i] = 0;
        for(int j=0;j<10;j++)
            if(i&(1<<j))has[i]++;
    }
    for(int i = 0;i < 1<<10;i++)
        for(int j = 0;j < 10;j++)
            ne[i][j] = go(i,j);
    for(int i = 0;i < 15;i++){
        for(int j=0;j<10;j++){
        }
    }
}
ll dfs(int pos,int number,int mask,bool isZero,bool flag){
    if(pos == 0)return has[mask] == K;
    if(flag && ~dp[pos][number][mask][K])return dp[pos][number][mask][K];
    ll ans = 0;
    int u = flag ? 9:bit[pos];
    for(int d = 0;d <= u;d++){
        if(isZero && d == 0)ans += dfs(pos-1,d,0,1,flag || d < u);
        else{
            ans += dfs(pos-1,d,ne[mask][d],0,flag || d < u);
        }
    }
    if(flag)dp[pos][number][mask][K] = ans ;
    return ans;
}
ll solve(ll n){
    int len = 0;
    while(n){
        bit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len,0,0,1,0);
}
int main(){
    init();
    ll L,R;
    int T;cin >> T;
    for(int cas = 1;cas <= T;cas++){
        cin >> L >> R >> K;
        cout<<"Case #"<<cas<<": "<<solve(R) - solve(L - 1)<<endl;
    }
    return 0;
}
