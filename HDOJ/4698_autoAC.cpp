#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <stack>  
#include <queue>  
#include <set>  
#define LL long long  
#define mod 1000000007  
#define M 1005  
#define INF 0x7fffffff  
using namespace std;  
struct Point  
{  
    int x, y;  
    bool operator < (const Point &temp) const  
    {  
        if(x!=temp.x) return x<temp.x;  
        else return y<temp.y;  
    }  
    int readPoint()  
    {  
        return scanf("%d%d", &x, &y);  
    }  
} p[M];  
int n, m, k;  
int val[M];  
set<int>sset;  
set<int>::iterator it;  
int main ()  
{  
    while(~scanf("%d%d%d", &n, &m, &k))  
    {  
        for(int i = 1; i <= k; ++i)  
        {  
            p[i].readPoint();  
            val[i] = p[i].x;  
        }  
        sort(p+1, p+1+k);  
        sort(val+1, val+1+k);  
        int tot = unique(val+1, val+1+k) - val;  
        val[0] = 0;  
        val[tot] = n+1;  
        LL ans = 0;  
        for(int i = 1; i < tot; ++i)  
        {  
            LL tt = 0;  
            int pre = val[i]-val[i-1];  
            int r;  
            for(r = 1; r <= k && p[r].x < val[i]; ++r);  
            sset.clear();  
            sset.insert(0);  
            sset.insert(m+1);  
            for(int j = i; j < tot; ++j)  
            {  
                int top, bottom;  
                for( ; r <= k && p[r].x == val[j]; ++r)  
                {  
                    if(sset.count(p[r].y)) continue;  
                    it = sset.lower_bound(p[r].y);  
                    top = *it;  
                    bottom = *(--it);  
                    tt = (tt+(LL)(top-p[r].y)*(p[r].y-bottom)%mod)%mod;  
                    sset.insert(p[r].y);  
                }  
                int rear = val[j+1]-val[j];  
                ans = (ans+tt*rear%mod*pre%mod)%mod;  
            }  
        }  
        printf("%I64d\n", ans);  
    }  
    return 0;  
}
