#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string.h>
using namespace std;
int n, m, q;
vector<int> g[100010];
int a[100010], b, c, d;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i <= n; i++) g[i].clear();
        memset(a, 0, sizeof(a));
        while (m--)
        {
            scanf("%d%d",&b,&c);
            g[b].push_back(c);
            g[c].push_back(b);
        }
        scanf("%d",&q);
        while (q--)
        {
            scanf("%d",&b);
            if (b == 0)
            {
                scanf("%d%d", &c, &d);
                a[c] += d;
            }
            else
            {
                int ans = 0;
                scanf("%d",&c);
                for (int i = 0; i < g[c].size(); i++)
                    ans += a[g[c][i]];
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
