#include <cstdio>  
#include <algorithm>  
using namespace std;  
const int N = 1005;  
int n, a[N];  
int d[N], c[N], cas, ans;  
int main()  
{  
    scanf("%d", &cas);  
    while (cas--)  
    {  
        scanf("%d", &n);  
        int sum = ans = 0;  
        for (int i = 1; i <= n; ++i)  
        {  
            scanf("%d", &a[i]);  
            d[i] = 1, c[i] = 1;  
            for (int j = 1; j < i; ++j)  
            {  
                if (a[j] >= a[i]) continue;  
                if (d[j] + 1 > d[i])  
                {  
                    d[i] = d[j] + 1;  
                    c[i] = c[j];  
                }  
                else if (d[j] + 1 == d[i])    c[i] = 2;  
            }  
            if(d[i] > ans) ans = d[i];  
        }  
        for (int i = 1; i <= n; ++i)  
            if (d[i] == ans)  sum += c[i];  
        printf("%d\n", sum > 1 ? ans : ans - 1);  
    }  
    return 0;  
}
