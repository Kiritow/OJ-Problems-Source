#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN = 55;
const int INF = 0x3f3f3f3f;
char s[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;
int main(void)    {      
    int T;  scanf ("%d", &T);
    while (T--) {
        scanf ("%d", &n);
        for (int i=1; i<=n; ++i)    scanf ("%s", s[i] + 1);
        memset (vis, false, sizeof (vis));  m = strlen (s[1] + 1);
        int ans = 0;
        for (int i=1; i<=n; ++i)    {
            for (int j=1; j<=m; ++j)  {
                if (s[i][j] == 'R' || s[i][j] == 'G')   {
                    if (!(s[i-1][j-1] == 'R' || s[i-1][j-1] == 'G'))    ans++; 
                }
            }
        }
        for (int i=1; i<=n; ++i)    {
            for (int j=1; j<=m; ++j)    {
                if (s[i][j] == 'B' || s[i][j] == 'G')   {
                    if (!(s[i-1][j+1] == 'B' || s[i-1][j+1] == 'G'))    ans++;
                }
            }
        }
        printf ("%d\n", ans);
    }
    return 0;
}
