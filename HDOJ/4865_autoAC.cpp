#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <vector>
#define maxn 55
using namespace std;
double dp[55][3];
int pre[55][3];
map<string,int> mp;
string str;
double p1[3][4]={0.6,0.2,0.15,0.05,0.25,0.3,0.2,0.25,0.05,0.1,0.35,0.5};
double p2[3][3]={0.5,0.375,0.125,0.25,0.125,0.625,0.25,0.375,0.375};
void init()
{
    mp.insert(make_pair("Dry",0));
    mp.insert(make_pair("Dryish",1));
    mp.insert(make_pair("Damp",2));
    mp.insert(make_pair("Soggy",3));
}
int main()
{
    int ncase,T=0;
    scanf("%d",&ncase);
    init();
    while(ncase--)
    {
        printf("Case #%d:\n",++T);
        int n;
        scanf("%d",&n);
        cin>>str;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            dp[i][j]=0;
        }
        int lab=mp[str];
        memset(pre,0,sizeof(pre));
        dp[1][0]=0.63*p1[0][lab];
        dp[1][1]=0.17*p1[1][lab];
        dp[1][2]=0.2*p1[2][lab];
        for(int i=2;i<=n;i++)
        {
            cin>>str;
            int lab=mp[str];
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    double pp=dp[i-1][k]*p2[k][j]*p1[j][lab];
                    if(pp>dp[i][j])
                    {
                        dp[i][j]=pp;
                        pre[i][j]=k;
                    }
                }
            }
        }
        vector<int> ans;
        double mi=0;
        int po;
        for(int i=0;i<3;i++)
        {
            if(dp[n][i]>mi)
            {
                mi=dp[n][i];
                po=i;
            }
        }
        ans.push_back(po);
        int now=n;
        while(now!=1)
        {
            po=pre[now][po];
            ans.push_back(po);
            now--;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(ans[i]==0)
            printf("Sunny\n");
            else if(ans[i]==1)
            printf("Cloudy\n");
            else
            printf("Rainy\n");
        }
    }
    return 0;
}
