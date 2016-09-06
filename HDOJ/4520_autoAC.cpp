#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
double s[25],temp[25];
int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lf", &s[i]);
            temp[i] = s[i];
        }
        sort(temp + 1, temp + n + 1);
        double sum = 0;
        for(int i = 2; i < n; ++i)
            sum += temp[i];
        sum /= (n - 2);
        double min = 10000000;
        int ans;
        for(int i = 1; i <= n; ++i)
        {
            if(fabs(s[i] - sum) < min)
            {
                min = fabs(s[i] - sum);
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
