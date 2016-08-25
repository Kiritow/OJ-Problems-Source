#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=10005;
int n,m;
struct node{
    int t,x,y;
}E[M];
int dp[M];
int cmp(node n1,node n2){
    return n1.t<n2.t;
}
int main()
{
    int i,l;
    int temp;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<m;i++)    scanf("%d%d%d",&E[i].t,&E[i].x,&E[i].y);
        sort(E,E+m,cmp);
        int ans;
        ans=dp[0]=1;
        for(i=1;i<m;i++)
        {
            dp[i]=0;
            for(l=i-1;l>=0;l--)
            {
                temp=abs(E[i].x-E[l].x)+abs(E[i].y-E[l].y);
                if(temp>E[i].t-E[l].t)    continue;
                dp[i]=dp[i]>(dp[l]+1)?dp[i]:(dp[l]+1);
            }
            if(!dp[i])    dp[i]=1;
            if(dp[i]>ans)    ans=dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
