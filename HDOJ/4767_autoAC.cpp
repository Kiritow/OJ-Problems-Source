#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x7ffffffffffLL
#define N 50
#define LL long long
#define mod 95041567
using namespace std;
LL num[N][N], q[N];
int p[5] = {31, 37, 41, 43, 47}, arr[5];
void Preprocessing(){
    q[0] = q[1]= 1;
    num[0][0] = num[1][0] = 1, num[1][1] = 2;
    for(int i = 2; i < 50; ++i){
        q[i] = num[i][0] = num[i - 1][i - 1];
        for(int j = 1; j <= i; ++j)
            num[i][j] = (num[i - 1][j - 1] + num[i][j - 1]) %mod; 
    }
}
int cal(int x, LL n){
    int _q[N];
    for(int i = 0; i <= x; ++i) _q[i] = q[i] % x;
    int len = 0;
    int _mod[15];
    while(n){
        _mod[len++] = n % x;
        n /= x;
    }
    int _arr[N];
    for(int i = 1; i < len; ++i)
        for(int j = 1; j <= _mod[i]; ++j){
            for(int k = 0; k < x; ++k)
                _arr[k] = (_q[k] * i + _q[k + 1]) % x;
            _arr[x] = (_arr[0] + _arr[1]) % x;
            for(int k = 0; k <= x; ++k) _q[k] = _arr[k];
        }
    return _arr[_mod[0]];
}
void gcd(LL a, LL b, LL &x, LL &y){
    if(!b){
        x = 1;
        y = 0;
        return;
    }
    gcd(b, a % b, y, x);
    y -= a / b * x;
}
LL china(){
    LL d, y, x = 0;
    for(int i = 0; i < 5; ++i){
        LL w = mod / p[i];
        gcd(p[i], w, d, y);
        x = (x + y * w * arr[i]) % mod;
    }
    return (x + mod) % mod;
}
int main()
{
    Preprocessing();
    int t;
    scanf("%d", &t);
    while(t--){
        LL n;
        scanf("%I64d", &n);
        if(n < 50){
            printf("%I64d\n", q[n]);
            continue;
        }
        for(int i = 0; i < 5; ++i)
            arr[i] = cal(p[i], n);
    printf("%I64d\n", china());
    }
    return 0;
}
