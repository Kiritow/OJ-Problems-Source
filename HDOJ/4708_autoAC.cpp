#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
long long a[20][20];
int n;
void change(int &x,int &y,int k)
{
    if(x == k)
    {
        if(y == k)
        {
            x++;
        }
        else y--;
    }
    else if(x == n+1-k)
    {
        if(y == n+1-k)
            x--;
        else y++;
    }
    else if(y == k)
        x++;
    else x--;
}
int main()
{
    while(scanf("%d",&n) && n)
    {
        for(int i = 1;i <=  n;i++)
            for(int j = 1;j <= n;j++)
                cin>>a[i][j];
        long long ans1 = 0, ans2 = 0;
        for(int i = 1;i <= n/2;i++)
        {
            int x0 = i,y0 = i;
            int x1 = i,y1 = n+1-i;
            int x2 = n+1-i,y2 = i;
            int x3 = n+1-i,y3 = n+1-i;
            int tmp1 = a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3];
            int tmp2 = 0;
            for(int j = 0;j < (n+2-2*i-2);j++)
            {
                change(x0,y0,i);
                change(x1,y1,i);
                change(x2,y2,i);
                change(x3,y3,i);
                int tt = min(j+1,n+2-2*i-1-(j+1));
                if(tmp1 < a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3])
                {
                    tmp1 = a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3];
                    tmp2 = tt;
                }
                else if(tmp1 == a[x0][y0] + a[x1][y1] + a[x2][y2] + a[x3][y3] && tmp2 > tt)
                {
                    tmp2 = tt;
                }
            }
            ans1 += tmp1;
            ans2 += tmp2;
        }
        ans1 += a[n/2+1][n/2+1];
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
