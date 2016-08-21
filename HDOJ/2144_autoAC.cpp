#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=111;
int n;
double limit;
char str[N][N];
int pre[N],len[N],dp[N][N];
int find(int k)
{
    if(pre[k]==k)    return k;
    pre[k]=find(pre[k]);
    return pre[k];
}
int cal(int a,int b)
{
    int i,l;
    int max=0;
    memset(dp[0],0,sizeof(dp[0]));
    for(i=1;i<=len[a];i++)
    {
        dp[i][0]=0;
        for(l=1;l<=len[b];l++)
        {
            if(str[a][i]==str[b][l])    dp[i][l]=dp[i-1][l-1]+1;
            else    dp[i][l]=0;
            if(dp[i][l]>max)    max=dp[i][l];
        }
    }
    return max;
}
int main()
{
    int Case=1;
    int i,l;
    int f1,f2,cnt,ans;
    while(scanf("%d%lf",&n,&limit)!=-1)
    {
        for(i=0;i<n;i++)    pre[i]=i;
        for(i=0;i<n;i++)
        {
            scanf("%s",str[i]+1);
            str[i][0]=' ';
            len[i]=strlen(str[i])-1;
            for(l=0;l<i;l++)
            {
                f1=find(i);
                f2=find(l);
                if(f1==f2)    continue;
                cnt=cal(i,l);
                if(cnt*100.0/len[i]>limit && cnt*100.0/len[l]>limit)    pre[f1]=f2;
            }
        }
        ans=0;
        for(i=0;i<n;i++)    if(pre[i]==i)    ans++;
        printf("Case %d:\n",Case++);
        cout<<ans<<endl;
    }
    return 0;
}
