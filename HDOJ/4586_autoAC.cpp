#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
#define LL long long
#define _LL __int64
#define eps 1e-8
#define PI acos(-1.0)
using namespace std;
int n,m;
int vis[210];
int a[210];
int sum,cnt;
double p,q;
int main()
{
    while(~scanf("%d",&n))
    {
        sum = 0;
        cnt = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        p = (sum*1.0)/n;
        scanf("%d",&m);
        int x;
        for(int i = 1; i <= m; i++)
        {
            cin >> x;
            if(vis[x]) continue;
            cnt++;
            vis[x] = 1;
        }
        q = (cnt*1.0)/n;
        if(fabs(p) < eps)
            cout << "0.00" << endl;
        else if(fabs(q-1) < eps)
            cout << "inf" << endl;
        else
            printf("%.2lf\n",p/(1-q));
    }
    return 0;
}
