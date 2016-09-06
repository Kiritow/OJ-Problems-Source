#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#define MAXN 1005
using namespace std;
double dp[55][MAXN], cost[MAXN][MAXN];
map<int ,double> has;
struct Info{
double pos;
double p;
}info[MAXN];
int main()
{
    int N, M, i, n, a, j, k, pos;
    double l, r, suml, sumr;
    double b, min, temp, t;
    while(scanf("%d%d",&N, &M)&&(N + M))
    {
        has.clear();
        for( i = 1; i <= N; ++ i )
        {
            scanf("%d", &n);++n;
            while(--n)
            {
                scanf("%d%lf", &a, &b);
                has[a]+=b;
            }
        }
        N = 0;
        for(map<int, double>::iterator it = has.begin(); it != has.end(); ++it)
        {
            info[++N].pos = it->first;
            info[N].p = it->second;
        }
          for(j = N; j >= 1; j--)
            {
                pos = j;
                cost[j][j] = 0;
                l = r = suml = 0;
                sumr = info[j].p;
                for(k = j-1; k >= 1; --k )
                {
                    suml += info[k].p;
                    l += (info[pos].pos-info[k].pos) * info[k].p;
                    temp =  l + r;
                    while((pos > 1)&&(temp>(t = (l + r + (sumr - suml) * (info[pos].pos - info[pos - 1].pos)))))
                    {
                        l -= suml *  (info[pos].pos - info[pos - 1].pos);
                        r +=  sumr *  (info[pos].pos - info[pos - 1].pos);
                        --pos;
                        suml -= info[pos].p;
                        sumr +=info[pos].p;
                        temp = t;
                    }
                    cost[k][j] = temp;
                }
            }
        for(i = 1; i <= N; i++)dp[0][i] = 1e300;
        for(i = 0; i <= M; i++)dp[i][0] = 0;
        for(i = 1; i <= M; i++)
        {
            for(j = N; j >= 1; j--)
            {
                min = dp[i-1][j-1] + cost[j][j];
                for(k = j-1; k >= 1; --k )
                {
                        if(dp[i - 1][k - 1] + cost[k][j] < min)min = dp[i - 1][k - 1] + cost[k][j];
                }
                dp[i][j] = min;
            }
        }
        printf("%0.2lf\n",dp[M][N]);
    }
    return 0;
}
