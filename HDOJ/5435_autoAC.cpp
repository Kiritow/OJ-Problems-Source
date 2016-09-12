#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;
const ll mod = 1e9 + 7;
int T,LA,LB;
char A[MAXN],B[MAXN];
int dp[100010][16];
int Solve(char *s,int L,int p,int f,int xsum){
    if(p > L) return xsum;
    if(f){
        int len = L - p + 1;
        int res = 0;
        for(int i = 0; i < 16; ++i)
            res = (res + 1ll * (xsum ^ i) * dp[len][i]) % mod;
        return res;
    }
    int top = s[p] - '0';
    int res = 0;
    for(int i = 0; i <= top; ++i)
        res = (res + 1ll * Solve(s,L,p + 1,f | (i < top),xsum ^ i)) % mod;
    return res;
}
void Pre(){
    dp[0][0] = 1;
    for(int i = 1; i < 100010; ++i)
        for(int j = 0; j < 16; ++j)
            for(int k = 0; k < 10; ++k)
                dp[i][j] = (dp[i][j] + 1ll * dp[i - 1][j ^ k]) % mod;
}
int main(){
    Pre();
    scanf("%d",&T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%s%s",A + 1,B + 1);
        LA = strlen(A + 1);
        LB = strlen(B + 1);
        int tmp = 0;
        for(int i = 1; i <= LA; ++i) tmp ^= (A[i] - '0');
        int ansA = Solve(A,LA,1,0,0);
        int ansB = Solve(B,LB,1,0,0);
        printf("Case #%d: %d\n",tt,(int)
                (((1ll * ansB - ansA + tmp) % mod + mod) % mod));
    }
    return 0;
}
