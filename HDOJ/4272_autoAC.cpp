#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#define MIN(a , b) ((a) < (b) ? (a) : (b))
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std;
const int maxn = 1300;
int x[maxn],stack[maxn],cnt[maxn];
bool dp[maxn][maxn],vis[maxn][maxn];
int n;
void read()
{
    memset(cnt,0,sizeof(cnt));
    memset(vis,false,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&stack[i]);
        x[i] = stack[i];
    }
    return;
}
bool check()
{
    if(n & 1) return false;
    sort(x , x + n);
    int m = x - unique(x , x + n);
    for(int i=0;i<n;i++)
    {
        int idx = lower_bound(x , x + m , stack[i]) - x;
        cnt[idx]++;
    }
    for(int i=0;i<m;i++)
    {
        if(cnt[i] & 1) return false;
    }
    return true;
}
bool dfs(int dep , int to , int st)
{
    if(vis[dep][st]) return dp[dep][st];
    bool flag = false;
    int use = 0;
    for(int i=dep-1;i>=0 && use < 5;i--)
    {
        if(st & (1 << (dep - i)))
        {
            use++;
            if(stack[dep] == stack[i])
            {
                int cur = st;
                cur ^= 1;
                cur ^= (1 << (dep - i));
                if(cur == 0)
                {
                    flag = true;
                    break;
                }
                int pos = dep;
                while((cur & 1) == 0)
                {
                    cur >>= 1;
                    pos--;
                }
                int end = to-1;
                while(end >= 0 && pos - end < 10)
                {
                    cur |= (1 << (pos - end));
                    end--;
                }
                if(dfs(pos , end+1 , cur))
                {
                    flag = true;
                    break;
                }
            }
        }
    }
    vis[dep][st] = true;
    return dp[dep][st] = flag;
}
int main()
{
    while(~scanf("%d",&n))
    {
        read();
        if(check() == false)
        {
            puts("0");
            continue;
        }
        puts(dfs(n-1 , MAX(n-10 , 0) , (1 << MIN(10 , n)) - 1) ? "1" : "0");
    }
    return 0;
}
