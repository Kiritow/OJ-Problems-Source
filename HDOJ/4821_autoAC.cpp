#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int HASH;
const int MAXN = 100010;
int now ;
struct HASHMAP
{
    int head[10007],next[MAXN],size;
    unsigned long long state[MAXN];
    int f[MAXN];
    void init()
    {
        size = 0;
        for(int i = 0;i < HASH ;i++)
            head[i] = -1;
    }
    int insert(unsigned long long val,int _id)
    {
        int h = val % HASH;
        for(int i = head[h];i != -1;i = next[i])
        {
            if(val == state[i])
            {
                int tmp = f[i];
                f[i] = _id;
                return tmp;
            }
        }
        f[size] = _id;
        state[size] = val;
        next[size] = head[h];
        head[h] = size++;
        return 0;
    }
}H;
const int SEED = 13331;
unsigned long long P[MAXN];
unsigned long long S[MAXN];
unsigned long long a[MAXN];
char str[MAXN];
int main()
{
    P[0] = 1;
    for(int i = 1;i < MAXN;i++)
        P[i] = P[i-1]*SEED;
    int M,L;
    now = -1;
    while(scanf("%d%d",&M,&L) == 2)
    {
        now --;
        scanf("%s",str);
        int n = strlen(str);
        S[0] = 0;
        for(int i = 1;i <= n;i++)
            S[i] = S[i-1]*SEED + str[i-1];
        int ans = 0;
        if(L>= 300)
            HASH = 10007;
        else
            HASH = 107;
        for(int st = 1;st <= L;st++)
        {
            H.init();
            int tmp = 1;
            int cnt = 0;
            for(int i = st; i + L - 1 <= n;i += L)
                a[++cnt] = S[i+L - 1] - S[i-1] * P[L];
            for(int i = 1;i <= cnt;i++)
            {
                int l = H.insert(a[i],i);
                if(i - l >= M)continue;
                ans += max(0, i - M - tmp + 1);
                tmp = max(tmp,l + 1);
            }
            ans += max(0,cnt+1 - M - tmp+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
