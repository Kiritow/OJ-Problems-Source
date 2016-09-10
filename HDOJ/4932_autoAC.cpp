#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=55;
const int inf=1<<29;
const double eps=1e-6;
int n;
double a[maxn],dp[maxn][2];
vector<double> set;
bool check(double val)
{
    bool last=false;
    for(int i=1;i<n-1;i++)
    {
        if(!last&&a[i]-a[i-1]>=val)
        {
            last=false;
            continue;
        }
        if(last&&fabs(a[i]-a[i-1]-val)<=eps)
        {
            last=false;
            continue;
        }
        if(last&&(a[i]-a[i-1])/2>=val)
        {
            last=false;
            continue;
        }
        if(a[i+1]-a[i]>=val)
        {
            last=true;
            continue;
        }
        return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf",&a[i]);
        sort(a,a+n);
        n=unique(a,a+n)-a;
        if(n<=2)
        {
            printf("0.000\n");
            continue;
        }
        for(int i=1;i<n;i++)
        {
            set.push_back(a[i]-a[i-1]);
            set.push_back((a[i]-a[i-1])/2);
        }
        sort(set.begin(),set.end());
        double ans=0;
        for(int i=set.size()-1;i>=0;i--)
            if(check(set[i]))
            {
                ans=set[i];
                break;
            }
        printf("%.3f\n",ans);
    }
    return 0;
}
