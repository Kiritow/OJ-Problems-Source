#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN= 100002;
int a[MAXN], m, n, b1, b2, len[MAXN], ch[MAXN];
long long ans;
int main()
{
    int i;
    while(scanf("%d%d%d", &n, &b1, &b2) != -1)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        ans = 0;
        len[1] = 1;
        for(i = 2; i <= n; i++)
        {
            ch[i] = a[i] - a[i-1];
            if(i == 2)
            {
                if(a[2]-a[1] == b1 || a[2] - a[1] == b2)
                    len[i] = 2;
                else len[i] = 1;
            }
            else
            {
                if(ch[i] == ch[i-1])
                {
                    if(ch[i] == b1 || ch[i] == b2)
                        len[i] = len[i-1] + 1;
                    else
                        len[i]  = 1;
                }
                else if(ch[i] == b2 && ch[i-1] == b1)
                {
                    len[i] = len[i-1] + 1;
                }
                else if(ch[i] == b1 || ch[i] == b2)
                {
                    len[i]  = 2;
                }
                else
                {
                    len[i] = 1;
                }
            }
        }
        for(i = 1; i<= n; i++)
        {
            ans += len[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
