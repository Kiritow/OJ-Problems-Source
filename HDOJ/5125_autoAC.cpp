#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <iostream>  
#include <string>  
#include <vector>  
#include <cmath>  
#include <queue>  
#include <map>  
#include <set>  
using namespace std;   
#define INF 1000000000  
//typedef __int64 LL;   
#define N 1005  
int t, n, m, a[N], b[N], c[N][2*N], nn, num[2*N];   
int lowbit(int x) {  
    return x & (-x);   
}  
int get_max(int x, int k) {  
    int ret = 0;   
    while(x > 0) {  
        ret = max(ret, c[k][x]);   
        x -= lowbit(x);   
    }  
    return ret;   
}  
void add(int x, int ad, int k) {  
    while(x <= nn) {  
        c[k][x] = max(ad, c[k][x]);   
        x += lowbit(x);   
    }  
}  
int main() {  
#ifndef ONLINE_JUDGE  
    freopen("in.txt", "r", stdin);   
#endif // ONLINE_JUDGE  
    scanf("%d", &t);   
    while(t--) {  
        scanf("%d%d", &n, &m);   
        nn = 0;   
        for(int i = 1;i <= n;i ++) {  
            scanf("%d%d", &a[i], &b[i]);   
            nn ++; num[nn] = a[i];   
            nn ++; num[nn] = b[i];   
        }  
        sort(num+1, num+1+nn);   
        nn = unique(num+1, num+1+nn) - num - 1;   
        for(int i = 1; i<= n; i++) {  
            a[i] = lower_bound(num+1, num+1+nn, a[i]) - num;   
            b[i] = lower_bound(num+1, num+1+nn, b[i]) - num;  
        }  
        memset(c, 0, sizeof(c));   
        int ans = 0;   
        for(int i = 1; i <= n; i++) {  
            for(int j = 0; j <= m; j++) {  
                int temp;   
                temp = get_max(a[i] - 1, j) + 1;   
                add(a[i], temp, j);   
                ans = max(ans, temp);   
                if(j!=m) {  
                    temp = get_max(b[i] - 1, j+1) + 1;   
                    add(b[i], temp, j);   
                    ans = max(ans, temp);   
                }  
            }  
        }  
        printf("%d\n", ans);   
    }  
    return 0;   
}
