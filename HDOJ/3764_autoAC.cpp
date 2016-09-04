#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1500
int a[MAX], n;
int main(void)
{
    while(scanf("%d", &n) && n)
    {
        int i, j;
        a[0] = 0;
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[n+1] = 1422;
        n = n + 2;
        sort(a, a + n);
        int flag = 0;
        for(i = 0; i + 1 < n; i++)
        {
            if(a[i+1] - a[i] > 200)
                flag = 1;
        }
 if(a[n - 1] - a[n-2] > 100) flag = 1;
        if(flag == 1)
            puts("IMPOSSIBLE");
        else puts("POSSIBLE");
    }
    return 0;
}
