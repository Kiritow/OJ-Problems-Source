#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int ans[105][105];
int dpu[105];
int dpd[105];
int main()
{
    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>ans[i][j];
            }
        }
        for(int i=2;i<=m;i++)
        {
            ans[i][1]+=ans[i-1][1];
        }
       for(int j=2;j<=n;j++)
        {
            dpu[0]=dpu[m+1]=dpd[0]=dpd[m+1]=-9999999;
            for(int i=m;i>=1;i--)
            {
                dpu[i]=max(dpu[i+1],ans[i][j-1])+ans[i][j];
            }
             for(int i=1;i<=m;i++)
            {
                dpd[i]=max(dpd[i-1],ans[i][j-1])+ans[i][j];
            }
            for(int i=1;i<=m;i++)
            {
                ans[i][j]=max(dpu[i],dpd[i]);
            }
        }
           printf("Case #%d:\n%d\n",++cas,ans[1][n]);
    }
    return 0;
}
