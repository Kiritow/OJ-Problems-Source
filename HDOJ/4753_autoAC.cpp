#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int dp[10001];
int visit[10001];
int vis[25];
int oth[25];
int ts;
int num(int vist[])
{
    int i;
    int sum=0;
    for(i=1;i<=9;i++)
    {
        if(vist[i]&&vist[i+3]&&vist[i+12+(i-1)/3]&&vist[i+13+(i-1)/3])sum++;
    }
    return sum;
}
int dos(int x)
{
    int sum=0,i;
    int vist[26];
    for(i=0;i<=24;i++)vist[i]=0;
    for(i=1;i<=ts;i++)
    {
        if(x&(1<<(i-1)))
        {
            vist[oth[i-1]]=1;
        }
    }
    for(i=1;i<=24;i++)
    {
        if(vis[i])vist[i]=1;
    }
    sum=num(vist);
    return sum;
}
int dfs(int x)
{
    if(visit[x]!=-1)return visit[x];
    int ans=0;
    for(int i=1;i<=ts;i++)
    {
        if(!(x&(1<<(i-1))))
        {
            int y;
            y=x+(1<<(i-1));
            int ss;
            ss=dfs(y);
            ans=max(9-dp[x]-ss,ans);
        }
    }
    visit[x]=ans;
    return ans;
}
int main()
{
    int T,i,n,a,b;
    int cas;
    int anum,bnum,s;
    cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        anum=bnum=0;
        s=0;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(visit,-1,sizeof(visit));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            if(b-a==4)ts=12+a;
            else ts=a-a/4;
            vis[ts]=1;
            if(i%2==0)
            {
                anum+=num(vis)-s;
            }
            else bnum+=num(vis)-s;
            s=num(vis);
        }
        ts=0;
        for(i=1;i<=24;i++)if(vis[i]==0)oth[ts++]=i;
        for(i=0;i<(1<<ts);i++)dp[i]=dos(i);
        int have;
        have=9-s;
        int fs;
        fs=dfs(0);
        printf("Case #%d: ",cas);
        if(n%2==0)
        {
            if(anum+fs>bnum+have-fs)cout<<"Tom200"<<endl;
            else cout<<"Jerry404"<<endl;
        }
        else
        {
            if(anum+have-fs>bnum+fs)cout<<"Tom200"<<endl;
            else cout<<"Jerry404"<<endl;
        }
    }
    return 0;
}
