#include <cstdio>
#include <iostream>
const int MAX = 1000005;
using namespace std;
int num[MAX], pre_max[MAX]; 
inline int max(int a, int b)
{
    return a > b ? a : b;
}
int DP(int n, int m)
{
    for(int i = 1; i <= m; ++i)
    { 
        int tmp = 0;
        for(int k = 1; k <= i; ++k)
            tmp += num[k];
        pre_max[n] = tmp;
        for(int j = i+1; j <= n; ++j)
        {
            tmp = max(pre_max[j-1], tmp) + num[j];
            pre_max[j-1] = pre_max[n];
            pre_max[n] = max(pre_max[n], tmp);         
        }
    }
    return pre_max[n];
}
int main()
{
    int n, m;
    while(~scanf("%d%d", &m, &n))
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
            pre_max[i] = 0;   
        }
        printf("%d\n", DP(n, m));
    }
    return 0;
}
