#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<sstream>
#include<string>
#include<bitset>
using namespace std;
typedef long long LL;
const LL LINF = (1LL <<63);
const int INF = 1 << 31;
const int NS = 100010;
const int MS = 19;
const int MOD = 1000000007;
const int EDGE_MAX = NS;
struct graphEdge
{
    int pst;
    int next;
};
struct ForwardStart
{
    int top;
    int head[EDGE_MAX];
    graphEdge edge[EDGE_MAX << 1];
    void init(int len)
    {
        top = 0;
        memset(head, -1, sizeof(int) * len);
    }
    void addEdge(int u, int v)
    {
        edge[top].pst = v;
        edge[top].next = head[u];
        head[u] = top++;
    }
    void printAll()
    {
        printf("top = %d\n", top);
        for(int i = 1; i < EDGE_MAX; i++)
        {
            if(-1 != head[i])
            {
                printf("head[%2d]'son:%2d", i, edge[head[i]].pst);
                for(int j = edge[head[i]].next; j != -1; j = edge[j].next)
                {
                    printf(",%2d", edge[j].pst);
                }
                puts("");
            }
        }
    }
}cTree;
bitset<NS> isPrime;
vector<int> fac[NS];
int miu[NS];
void prepare()
{
    isPrime.set();
    isPrime[1] = false;
    miu[1] = 1;
    for(int i = 2; i < NS; i++)
    {
        if(isPrime[i])
        {
            for(int j = i; j < NS; j+=i)
            {
                isPrime[j] = false;
                int k = j / i;
                if(k % i)
                {
                    miu[j] = -miu[k];
                }
                else
                {
                    miu[j] = 0;
                }
                fac[j].push_back(i);
            }
        }
        else
        {
            if(miu[i] != 0)
            {
                for(int j = i; j < NS; j+=i)
                {
                    fac[j].push_back(i);
                }
            }
        }
    }
}
int n;
int val[NS];
int ans[NS];
int sz[NS];
int dp[NS];
void dfs(int rt, int fa)
{
    vector<int> temp;
    sz[rt] = 1;
    int value = val[rt];
    int len = fac[value].size();
    for(int i = 0; i < len; i++)
    {
        int d = fac[value][i];
        int cnt = dp[d];
        temp.push_back(cnt);
        dp[d] += 1;
    }
    for(int i = cTree.head[rt]; i != -1; i = cTree.edge[i].next)
    {
        int cson = cTree.edge[i].pst;
        if(cson == fa) continue;
        dfs(cson, rt);
        sz[rt] += sz[cson];
    }
    ans[rt] = sz[rt];
    for(int i = 0; i < len; i++)
    {
        int d = fac[value][i];
        int cnt = dp[d] - temp[i];
        if(cnt > 0)
        {
            ans[rt] += miu[d] * cnt;
        }
    }
    return ;
}
int main()
{
    prepare();
    int nCase = 1;
    while(~scanf("%d", &n))
    {
        cTree.init(n + n + 2);
        int u, v;
        for(int i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);
            cTree.addEdge(u, v);
            cTree.addEdge(v, u);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &val[i]);
            if(val[i] < 0)
            {
                val[i] = - val[i];
            }
        }
        memset(dp, 0, sizeof(dp));
        dfs(1, -1);
        printf("Case #%d:", nCase++);
        for(int i = 1; i <= n; i++)
        {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
