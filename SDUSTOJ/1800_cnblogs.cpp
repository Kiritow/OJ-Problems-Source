/* ***********************************************
Author        :devil
Created Time  :2016/4/26 21:58:52
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
const int N=1010;
int dp[N],a[N],b[N],c[N];
int main()
{
    //freopen("in.txt","r",stdin);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        int ma=0;
        memset(c,0,sizeof(c));
        c[1]=n;
        for(int i=1; i<=n; i++)
        {
            b[i]=dp[i]=1;
            for(int j=1; j<i; j++)
            {
                if(a[i]>a[j]&&dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    b[i]=b[j];
                }
                else if(a[i]>a[j]&&dp[i]==dp[j]+1) b[i]+=b[j];
            }
            if(dp[i]>1) c[dp[i]]+=b[i];
            ma=max(ma,dp[i]);
        }
        printf("%d\n",c[ma]);
    }
    return 0;
}
