#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 10010;
int F[MAXN];
int find(int x)
{
    if(F[x] == -1)return x;
    return F[x] = find(F[x]);
}
pair<int,int>p[100010];
int ans[100010];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        memset(F,-1,sizeof(F));
        for(int i = 1;i <= m;i++)
        {
            scanf("%d%d",&p[i].first,&p[i].second);
        }
        ans[m] = n;
        for(int i = m;i > 1;i --)
        {
            int t1 = find(p[i].first);
            int t2 = find(p[i].second);
            if(t1 != t2)
            {
                ans[i-1] = ans[i] - 1;
                F[t1] = t2;
            }
            else ans[i-1] = ans[i];
        }
        for(int i = 1;i <= m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
