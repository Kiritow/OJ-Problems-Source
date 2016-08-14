#include <cstring>
#include <cstdio>
using namespace std;
#define MAXN 10005000
int a[MAXN];
int b[MAXN];
int len;
char str[MAXN];
int main()
{
    int i=1;
    while(scanf("%s", str)==1)
    {
        int tomod = 10001;
        int ans = 0;
        for(int j = 0; str[j]; j++)
            ans = (ans * 10 + (str[j] - '0') % tomod) % tomod;
        if(ans)
            printf("Case #%d: NO\n", i++);
        else
            printf("Case #%d: YES\n", i++);
    }
    return 0;
}
