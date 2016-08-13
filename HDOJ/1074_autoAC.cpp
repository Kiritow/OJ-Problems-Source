#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int N = 16;
int dp[1<<N];
struct Node
{
    string s;
    int time,cost;
};
Node a[N];
int pre[1<<N];
int n;
void Output(int status)
{
    if(status==0)return;
    int t=0;
    for(int i=0;i<n;i++)
      if( (status&(1<<i))!=0 && (pre[status]&(1<<i))==0 )
      {
          t=i;
          break;
      }
    Output(pre[status]);
    cout<<a[t].s<<endl;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i].s>>a[i].time>>a[i].cost;
        }
        memset(dp,0x3f3f3f3f,sizeof(dp));
        memset(pre,0,sizeof(pre));
        dp[0]=0;
        for(int st=0;st<(1<<n);st++)
        {
            int tmp=0;
            for(int i=0;i<n;i++)
            {
                if(st&(1<<i))
                    tmp+=a[i].cost;
            }
            for(int i=0;i<n;i++)
            {
                //printf("fff %d %d %d",st,(1<<i),st&(1<<i));
                if((st&(1<<i))==0)
                {
                    if(dp[st|(1<<i)]>dp[st]+max(0,tmp+a[i].cost-a[i].time)){
                        dp[st|(1<<i)]=dp[st]+max(0,tmp+a[i].cost-a[i].time);
                        pre[st|(1<<i)]=st;
                    }
                }
            }
        }
        printf("%d\n",dp[(1<<n)-1]);
        Output((1<<n)-1);
    }
    return 0;
}
