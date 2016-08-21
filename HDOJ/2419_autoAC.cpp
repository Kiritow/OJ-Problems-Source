#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 20010, MAXM = 60010, MAXQ = 300010;
int value[MAXN], query[MAXQ][3];
multiset<PII> e;
multiset<int> v[MAXN];
int pre[MAXN];
int root(int a)
{
    if(pre[a] != a)
        pre[a] = root(pre[a]);
    return pre[a];
}
int unionSet(int a, int b)
{
    multiset<int>::iterator it;
    a = root(a), b = root(b);
    if(a == b)
        return 0;
    if(v[a].size() > v[b].size())
        swap(a, b);
    for    (it = v[a].begin(); it != v[a].end(); it++)
        v[b].insert(*it);
    v[a].clear();
    pre[a] = b;
    return 0;
}
int update(int a, int x)
{
    int ta = a;
    a = root(a);
    v[a].erase(v[a].find(value[ta]));
    v[a].insert(x);
    value[ta] = x;
    return 0;
}
int main()
{
    int n, m, q;
    int a, b;
    int i,u;
    int cas=0;
    char ch[3];
    double ct = 0, sum = 0;
    multiset<PII>::iterator it;
    multiset<int>::iterator tp;
    while(scanf("%d%d%d",&n,&m,&q)==3)
    {
        e.clear();
        for (i = 1; i <= n; i++)
            v[i].clear();
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &value[i]);
            pre[i] = i;
        }
        for (i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            if(a > b)
                swap(a, b);
            e.insert(PII(a, b));
        }
        for (i = 0; i < q; i++)
        {
            scanf("%s", &ch);
            scanf("%d%d", &query[i][1], &query[i][2]);
            query[i][0] = ch[0];
            if(ch[0] == 'E')
            {
                if(query[i][1] > query[i][2])
                    swap(query[i][1], query[i][2]);
                it = e.find(PII(query[i][1], query[i][2]));
                e.erase(it);
            }
            else if(ch[0] == 'U')
                swap(value[query[i][1]], query[i][2]);
        }
        for (i = 1; i <= n; i++)
            v[i].insert(value[i]);
        for (it = e.begin(); it != e.end(); it++)
            unionSet(it->first, it->second);
        ct=0;
        sum=0;
        for(int i = q - 1; i >= 0; i--)
        {
            if(query[i][0] == 'E')
                unionSet(query[i][1], query[i][2]);
            else if(query[i][0] == 'U')
                update(query[i][1], query[i][2]);
            else
            {
                ct += 1;
                u = root(query[i][1]);
                tp = v[u].lower_bound(query[i][2]);
                if(tp != v[u].end())
                    sum += *tp;
            }
        }
        printf("Case %d: %0.3lf\n",++cas,(double)sum/ct);
    }
    return 0;
}
