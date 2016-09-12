#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const LL base = 1e9 + 7;
const int maxn = 105;
LL T, n, m, a[maxn][maxn], sum, x, y;
inline void read(int &x)
{
    char ch;
    while ((ch = getchar())<'0' || ch>'9');
    x = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
void get()
{
    x = 1;    y = 2;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m; j++) 
            if (((i + j) & 1) && a[x][y] > a[i][j]) x = i, y = j;
}
int main()
{
    while (scanf("%lld%lld", &n, &m) !=EOF)
    {
        sum = 0;
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%lld", &a[i][j]);
                sum += a[i][j];
            }
        if (n & 1 || m & 1)
        {
            printf("%lld\n", sum);
            if (n & 1)
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j < m; j++) 
                        if (i & 1) printf("R"); else printf("L");
                    if (i < n) printf("D"); else printf("\n");
                }
            }
            else
            {
                for (int i = 1; i <= m; i++)
                {
                    for (int j = 1; j < n; j++)
                        if (i & 1) printf("D"); else printf("U");
                    if (i < m) printf("R"); else printf("\n");
                }
            }
        }
        else
        {
            get();
            printf("%lld\n", sum - a[x][y]);
            for (int i = 1; i <= n; i += 2)
            {
                if (x == i || x == i + 1)
                {
                    for (int j = 1; j < y; j++)
                    {
                        if (j & 1) printf("D"); else printf("U");
                        printf("R");
                    }
                    if (y < m) printf("R");
                    for (int j = y + 1; j <= m; j++)
                    {
                        if (j & 1) printf("U"); else printf("D");
                        if (j < m) printf("R");
                    }
                    if (i < n - 1) printf("D");
                }
                else if (i < x)
                {
                    for (int j = 1; j < m; j++) printf("R");
                    printf("D");
                    for (int j = 1; j < m; j++) printf("L");
                    printf("D");
                }
                else
                {
                    for (int j = 1; j < m; j++) printf("L");
                    printf("D");
                    for (int j = 1; j < m; j++) printf("R");
                    if (i < n - 1) printf("D");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
