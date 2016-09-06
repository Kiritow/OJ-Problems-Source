#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10010;
int cnt[maxn];
int main()
{
    int n;
    while(scanf("%d", &n) == 1)
    {
        memset(cnt, 0, sizeof(cnt));
        int ans = -1;
        for(int i = 0; i < n+1; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            cnt[tmp]++;
            if(cnt[tmp] >= 2)
                ans = tmp;
        }
        printf("%d\n", ans);
    }
}
