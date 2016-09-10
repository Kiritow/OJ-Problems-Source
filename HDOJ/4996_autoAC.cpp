#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <string>  
#include <queue>  
#include <map>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
#define RD(x) scanf("%d",&x)  
#define RD2(x,y) scanf("%d%d",&x,&y)  
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)  
#define clr0(x) memset(x,0,sizeof(x))  
typedef long long LL;  
const int maxn = 1<<20;  
int n,k;  
LL f[20][20],dp[maxn],tmp[maxn];  
int cal(int x)  
{  
    int ans = 0;  
    for(int i = 0;i < 20;++i)  
        if((1<<i)&x)  
            ans++;  
    return ans;  
}  
void init () {  
    dp[1] = f[1][1] = 1;  
    for(int i = 1;i < 18;++i){  
        for(int j = 0;j < (1<<i);++j)  
            tmp[j] = dp[j];  
        for(int j = 0;j < (1<<(i+1));++j)  
            dp[j] = 0;  
        for(int j = 0;j < (1<<i);++j)if(tmp[j]){  
            for(int k = 0;k <= i;++k){  
                int tot = 0,c[20],st = 0;  
                for(int l = 0;l < i;++l){  
                    if((1<<l) & j){  
                        c[tot] = l;  
                        if(c[tot] >= k)  
                            c[tot]++;  
                        tot++;  
                    }  
                }  
                c[tot++] = k;  
                for(int l = 0;l < tot;++l){  
                    if(c[l] > k){  
                        c[l] = k;  
                        break;  
                    }  
                }  
                for(int l = 0;l < tot;++l){  
                    st |= (1<<c[l]);  
                }  
                dp[st] += tmp[j];  
            }  
        }  
        for(int j = 0;j < (1<<(i+1));++j)  
            f[i+1][cal(j)] += dp[j];  
    }  
}  
int main() {  
    init();  
    int _;RD(_);while(_--){  
        RD2(n,k);  
        printf("%I64d\n",f[n][k]);  
    }  
    return 0;  
}
