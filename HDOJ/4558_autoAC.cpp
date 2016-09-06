#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#define MP make_pair
#define SQ(x) ((x)*(x))
typedef long long int64;
const double PI = acos(-1.0);
const int MAXN = 110;
const int INF = 0x3f3f3f3f;
using namespace std;
const int MOD = 1000000007;
int n, m;
int f[2][480][22][2];
int mat[480][480];
char str[1000];
int main(){
    int nCase, cas=1;
    scanf("%d", &nCase);
    while(nCase--){
        scanf("%d%d%*c", &n, &m);
        for(int i=1; i<=n; ++i){
            gets(str);
            for(int j=1; j<=m; ++j)
                mat[i][j] = str[j-1]-'0';
        }
        memset(f, 0, sizeof(f));
        int ans = 0;
        bool p = 0;
        for(int i=1; i<=n; ++i){
            p = !p;
            memset(f[p], 0, sizeof(f[p]));
            for(int j=1; j<=m; ++j){
                for(int k=0; k<=10; ++k){
                    int x1 = (k+mat[i][j])%11;
                    int x2 = (k-mat[i][j]+11)%11;
                    f[p][j][k][0] += ((f[!p][j][x1][1]+f[p][j-1][x1][1])%MOD)%MOD;
                    f[p][j][k][1] += ((f[!p][j][x2][0]+f[p][j-1][x2][0])%MOD)%MOD;
                }
                ++f[p][j][11-mat[i][j]][0]; 
            }
            for(int j=1; j<=m; ++j){
                ans += (f[p][j][0][0] + f[p][j][0][1])%MOD;
                ans %= MOD;
            }
        }
        printf("Case %d: %d\n",cas++, ans);
    }
    return 0;
}
