#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int tCase,n,a[10000+1];
int num[10000+1];
int z,f,o;
int solve(int s,int t)
{
    f=0;
    for(int i=s;i<t;i++)
    {
        if(a[i]<0) f++;
    }
    if(f%2==0)
    {
        return t-s;
    }
    else
    {
        int ans=0,tag1=s-1,tag2=t,a1,a2,a3,a4,m=t-s;
        for(int i=s;i<t;i++)
        {
            if(a[i]<0)
            {
                tag1=i;
                break;
            }
        }
        a1=m-(tag1-s+1);
        a3=tag1-s;
        if(a1<a3) a1=a3;
        for(int i=t-1;i>=s;i--)
        {
            if(a[i]<0)
            {
                tag2=i;
                break;
            }
        }
        a2=tag2-s;
        a4=t-1-tag2;
        if(a2<a4) a2=a4;
        ans=max(ans,max(a1,a2));
        return ans;
    }
}
int main()
{
    scanf("%d",&tCase);
    for(int i=1;i<=tCase;i++)
    {
        scanf("%d",&n);
        o=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]==0)
            num[o++]=j;
        }
        num[o++]=n+1;
        int t=1;
        int ans=0;
        for(int j=0;j<o;j++)
        {
            ans=max(ans,solve(t,num[j]));
            t=num[j]+1;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
