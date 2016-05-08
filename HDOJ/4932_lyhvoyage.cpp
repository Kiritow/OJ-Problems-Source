#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    double b[120], c[60];
    int flag[60];
    int n, i, j, T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf("%lf",&c[i]);
        sort(c, c+n);
        int m = 0;
        for(i = 1; i < n; i++)
        {
            b[m++] = c[i] - c[i-1];
            b[m++] = (c[i] - c[i-1]) / 2;
        }
        sort(b, b+m);
        double ans;
        for(i = m - 1; i >= 0; i--)
        {
            memset(flag, 0, sizeof(flag));
            flag[0] = 1;
            double tmp = b[i];
            for(j = 1; j < n - 1; j++)
            {
                if(c[j] - tmp < c[j-1] && c[j] + tmp > c[j+1])  //往左往右都不行
                    break;
                if(c[j] - tmp >= c[j-1])
                {
                    if(flag[j-1] == 2) // 前一个往右
                    {
                        if(c[j] - c[j-1] == tmp) flag[j] = 1;  //两个点作为线段的两个端点
                        else if(c[j] - c[j-1] >= 2 * tmp) flag[j] = 1; //一个往左，一个往右
                        else if(c[j] + tmp <= c[j+1]) flag[j] = 2; //只能往右
                        else break;
                    }
                    else flag[j] = 1;
                }
                else if(c[j] + tmp <= c[j+1])
                    flag[j] = 2;
            }
            if(j == n - 1)
            {
                ans = tmp;
                break;
            }
        }
        printf("%.3lf\n", double(ans));
    }
    return 0;
}
