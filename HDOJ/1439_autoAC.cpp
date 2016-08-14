#include<cstdio>
#include<cstring>
#include<vector>
#include<utility>
using namespace std;
const int maxn = 205;
char s[maxn], ans[maxn];
int a[maxn];
bool vis[maxn];
pair<int, int> belong[maxn];
vector<int> group[maxn], tmp;
int main()
{
    int n, i, j, cnt, k;
    while (scanf("%d", &n), n)
    {
        for (i = 1; i <= n; ++i)
        {
            scanf("%d", &k);
            a[i] = k;
        }
        memset(vis, 0, sizeof(vis));
        for (i = 0; i < n; ++i) group[i].clear();
        cnt = 0;
        for (i = 1; i <= n; ++i)
        {
            if (!vis[i])
            {
                for (j = a[i]; !vis[j]; j = a[j])
                {
                    belong[j] = make_pair(cnt, group[cnt].size());
                    group[cnt].push_back(j);
                    vis[j] = true;
                }
                ++cnt;
            }
        }
        while (scanf("%d", &k), k)
        {
            getchar();
            gets(s + 1);
            for (i = strlen(s + 1) + 1; i <= n; ++i)
                s[i] = ' ';
            for (i = 1; i <= n; ++i)
            {
                tmp = group[belong[i].first];
                ans[tmp[(belong[i].second + k) % tmp.size()]] = s[i];
            }
            ans[n + 1] = 0;
            puts(ans + 1);
        }
        putchar(10);
    }
    return 0;
}
