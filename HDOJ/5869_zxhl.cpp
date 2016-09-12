#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

#pragma comment(linker, "/STACK:102400000,102400000")
#define ls i<<1
#define rs ls | 1
#define mid ((ll+rr)>>1)
#define pii pair<int,int>
#define MP make_pair

typedef long long LL;
const long long INF = 1e18;
const double Pi = acos(-1.0);
const int N = 1e6+10, M = 1e2+11, mod = 1e9+7, inf = 2e9;

int n,q,a[N],ans[N];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b);}
vector<pii> G[N];
struct QQ{
        int l,r,id;
        bool operator < (const QQ &a) const {
             return a.r > r;
        }
}Q[N];
int C[N],vis[N];
void update(int x,int c) {
        for(int i =x; i < N; i+=i&(-i)) C[i] += c;
}
int ask(int x) {
        int s =0 ;
        for(int i = x; i; i-= i & (-i))s += C[i];
        return s;
}
int main() {
        while(scanf("%d%d",&n,&q)!=EOF) {
            for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
            for(int i = 0; i <= n; ++i) G[i].clear();
            for(int i = 1; i <= n; ++i) {
                    int x = a[i];
                    int y = i;
                    for(int j = 0; j < G[i-1].size(); ++j) {
                        int res = gcd(x,G[i-1][j].first);
                        if(x != res) {
                                G[i].push_back(MP(x,y));
                                x = res;
                                y = G[i-1][j].second;
                        }
                    }
                    G[i].push_back(MP(x,y));
            }
            memset(C,0,sizeof(C));
            memset(vis,0,sizeof(vis));
            for(int i = 1; i <= q; ++i) {scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].id = i;}
            sort(Q+1,Q+q+1);
            for(int R = 0, i = 1; i <= q; ++i) {
                    while(R < Q[i].r) {
                        R++;
                        for(int j = 0; j < G[R].size(); ++j) {
                            int res = G[R][j].first;
                            int ids = G[R][j].second;
                            if(vis[res]) update(vis[res],-1);
                            vis[res] = ids;
                            update(vis[res],1);
                        }
                    }
                    ans[Q[i].id] = ask(R) - ask(Q[i].l-1);
            }
            for(int i = 1; i <= q; ++i) cout<<ans[i]<<endl;
        }
        return 0;
}
