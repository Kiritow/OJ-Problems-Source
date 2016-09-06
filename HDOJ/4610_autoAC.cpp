#include<cstdio>
#include<iostream>
#include<bitset>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = (int)4e6+10;
const int M = (int)1e6+10;
typedef pair<int,int> pii;
bool p[N];
int prime[M];
void init(){
    memset(p,true,sizeof(p));
    p[0] = p[1] = false;
    for(int i=2;i*i<N;i++)
        for(int j=i;j*i<N;j++)
            p[i*j] = 0;
    prime[0] = 0;
    for(int i=2;i<N;i++)
        if(p[i])prime[++prime[0]] = i;
}
vector<pii>factor;
void div(int n){
    factor.clear();
    for(int i=1;prime[i] * prime[i] <= n;i++){
        if(n % prime[i]  == 0){
            int cnt = 0;
            while(n % prime[i] == 0){
                n /= prime[i];
                ++cnt;
            }
            factor.push_back(make_pair(prime[i],cnt));
        }
    }
    if(n > 1)factor.push_back(make_pair(n,1));
}
ll Pow(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1)ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
bool isPrime_amount(int n){
    if(factor.size() > 1|| n==1 )return false;
    return p[factor[0].second + 1];
}
bool isPrime_sum(int n){
    if(factor.size() > 1|| n== 1)return false;
    int a = factor[0].first,b = factor[0].second;
    int sum = 1LL*(Pow(a,b+1) - 1) / (a - 1);
    return p[sum];
}
bool isSquare(ll n){
    ll _ = sqrt(n*1.0);
    return _ * _ == n;
}
bool isSquare_product(int n){
    int all = 1;
    for(int i=0;i<factor.size();i++)
        all *= factor[i].second + 1;
    ll sq = sqrt(n*1.0);
    ll cur = 1;
    int p = all >> 1;
    if(p & 1)cur *= n;
    if(all & 1)cur *= sq;
    return isSquare(cur);
}
int extra[5];
int V[16],cur[5],hash[16];
int have[16];
int main(){
    for(int i=0;i<16;i++){
        int all = 0;
        for(int j=0;j<4;j++)
            if(!(i&(1<<j)))++all;
        have[i] = all;
    }
    init();
    int T,n,K;
    scanf("%d",&T);
    while(T--){
        memset(V,0,sizeof(V));
        scanf("%d%d",&n,&K);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int flag = 15,cnt = 0;
            div(a);
            if(p[a])flag ^= 1<<0 ,cnt ++;
            if(isPrime_amount(a)) flag ^= 1<<1,cnt ++;
            if(isPrime_sum(a))flag ^= 1<<2,cnt ++;
            if(isSquare_product(a)) flag ^= 1<<3,cnt++;
            V[flag] += b;
            if(i!=1)printf(" ");
            printf("%d",cnt);
        }
        puts("");
        int ans = -(~0u>>2);
        for(int i=0;i< 4;i++)scanf("%d",&extra[i]);
        for(int i=0;i < 1<<16;i++){
            memset(cur,0,sizeof(cur));
            int res = K,number = 0,all = 0;
            int flag = 15;
            for(int j = 0;j < 16;j++){
                if(i&(1<<j)){
                    if(V[j] > 0){
                        flag &= j;
                        res --;
                        all += have[j];
                        cur[have[j]] += V[j] - 1;
                    }else{
                        res = -1;
                        break;
                    }
                }
            }
            if(res < 0 )continue;
            for(int k=4;k >= 0 && res > 0;k--){
                if(cur[k] <= res){
                    all += k * cur[k];
                    res -= cur[k];
                }else{
                    all += res * k;
                    res =0;
                }
            }
            if(res == 0){
                for(int j=0;j<4;j++)
                    if(flag & (1<<j))all += extra[j];
                ans = max(ans,all);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
