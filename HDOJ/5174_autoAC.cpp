#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
int const MAX = 2147483647;
ll a[105], b[105];
int re[105];
int main()
{
    int n, ca = 1;
    while(scanf("%d", &n) != EOF)
    {
        memset(re ,0 , sizeof(re));
        int ans = 0;
        for(int i = 1; i <= n; i++)
            scanf("%I64d", &a[i]);
        sort(a + 1, a + n + 1);
        int cnt = 0, pos = 1;
        a[n + 1] = -1;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == a[i + 1])
                cnt++;
            else
            {
                b[pos] = a[i];
                re[pos++] = cnt;
                if(i != n)
                    cnt = 0;
            }
        }
        if(cnt == n - 1)
        {
            printf("Case #%d: -1\n", ca++);
            continue;
        }
        b[0] = b[pos-1];
        b[pos] = b[1];
        re[0] = re[pos-1];
        re[pos] = re[1];
        for(int i = 1; i < pos; i++)
            if((b[i] + b[i - 1]) % MAX == b[i + 1])
            {
                ans ++;
                ans += re[i];
            }
        printf("Case #%d: %d\n", ca++, ans);
    }
}
