#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define ll unsigned long long
#define maxn 3000007
int check[maxn];
vector<int> pri;
void init(){
    memset(check,0,sizeof(check));
    pri.clear();
    for(int i = 2;i < maxn; i++){
        if(check[i] == 0) {
            pri.push_back(i);
        }
        for(int j = 0;j < pri.size() ; j++){
            if(i*pri[j] >= maxn) break;
            check[i*pri[j]] = 1;
            if(i%pri[j] == 0) break;
        }
    }
}
int getn(){
    int a = 0;
    char x;
    do{
        x = getchar();
        if(x == ' ' || x == '\n') return a;
        a = a*10+x-'0';
    }while(1);
    return 1;
}
int num[maxn];
int ok[maxn];
vector<int> hehe;
ll mod = 3221225473ll;
int pnum[maxn];
ll cal(int u,int p){
    ll ans = 1;
    ll v = u;
    while(p){
        if(p & 1) ans = ans*v % mod;
        p/=2;
        v = v*v%mod;
    }
    return ans;
}
int main(){
    init();
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        getchar();
        for(int i = 1;i <= n; i++)
            num[i] = getn();
        for(int i = 1;i <= n; i++)
            ok[i] = pnum[i] = 0;
        hehe.clear();
        int mu = 1;
        for(int i = 1;i <= n; i++){
            if(ok[i] != 1){
                int u = i;
                int x = 0;
                while(ok[u] == 0){
                    x++;
                    ok[u] = 1;
                    u = num[u];
                }
                hehe.push_back(x);
            }
        }
        for(int i = 0;i < hehe.size(); i++){
            for(int j = 0;j < pri.size() && pri[j] <= hehe[i]; j++){
                if(hehe[i] % pri[j] == 0){
                    int x = 0;
                    while(hehe[i] % pri[j] == 0){
                        hehe[i] /= pri[j];
                        x++;
                    }
                    pnum[pri[j]] = max(pnum[pri[j]],x);
                    mu = max(mu,pri[j]);
                }
            }
        }
        ll ans = 1;
        for(int i = 1;i <= mu; i++){
            if(pnum[i] != 0)
            ans = ans*cal(i,pnum[i])%mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
