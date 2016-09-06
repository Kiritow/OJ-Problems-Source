#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define P 10567201
#define N 1010
using namespace std;
long long c[1010][1010], two[1010];
int n, m, v;
long long f[N+5], inv[N+5];  
using namespace std;
void get_inv(){
    inv[1] = 1;
    for (int i = 2; i < N; ++i)
        inv[i] = (P - P / i) * inv[P % i] % P;
}
void pre_do(){
     get_inv();
     two[0] = 1;
     for (int i = 1; i < N; ++i){
         two[i] = (two[i-1] << 1);
         if (two[i] >= P) two[i] -= P;
    }
    for (int i = 1; i < N; ++i){
         c[i][0] = 1;
         for (int j = 1; j < N; ++j)
             c[i][j] = c[i][j-1] * (two[i]-j+1) % P * inv[j] % P;    
    }
}
void solve(){
     if (v == 0) f[0] = 1;
     else f[0] = 0;
     f[1] = 1;
     for (int i = 2; i <= m; ++i){
        long long same = f[i-2] * (two[n]-i+2) % P;
        f[i] = (c[n][i-1] - same) * inv[i] % P;
     }
     f[m] += (f[m] < 0 ? P : 0); 
     printf("%I64d\n", f[m]);
}
int main(){
    pre_do();
    while (scanf("%d%d%d", &n, &m, &v) != EOF){
         if (!(n+m+v)) break;
         solve();
    }
    return 0;
}
