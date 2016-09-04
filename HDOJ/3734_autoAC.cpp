#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream> 
using namespace std;
const int Mn = 100010;
const int Mod = 1e9 + 7;
int a[Mn], b[Mn], n;
int s[4][Mn];
pair<int, int >c[Mn];
inline int query(int k, int num){
    int res(0);
    for(;k;k -= k &-k)
        res = (res+s[num][k]) %Mod;
    return res;
}
inline void update(int k, int val, int num){
    for(; k <= n; k += k & -k){
        s[num][k] = (s[num][k] + val) % Mod;
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        memset(s, 0, sizeof(s));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]),b[i] = a[i];
        sort(b+1, b+n+1);
        for(int i = 1; i <= n; ++i){
            a[i] = lower_bound(b+1, b+n+1,a[i]) - b;
            c[i] = make_pair(a[i],i);
        }
        sort(c+1, c+n+1);
        long long ans(0);
        for(int i= 1; i <= n; ++i){
            long long t0 = query(c[i].second, 0);
            long long t1 = query(c[i].second, 1);
            long long t2 = query(n-c[i].second+1,2);
            long long t3 = query(n-c[i].second+1,3);
            ans = (ans+(t0-(1+t1) * t1 /2) % Mod *(t2-(1+t3)*t3/2)%Mod) %Mod;
            update(c[i].second, c[i].second, 0);
            update(c[i].second, 1, 1);
            update(n-c[i].second+1, n-c[i].second+1,2);
            update(n-c[i].second+1,1,3);
        }
        printf("%d\n", (int)(ans%Mod+Mod) %Mod);
    }
    return 0;
}
