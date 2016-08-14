#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int n,a[65],vis[65],sum;
bool cmp(int a,int b)
{
    return a>b;
}
int dfs(int now,int len,int pos,int q,int num)
{
    int i,j;
    int cut;
    cut=0;
    if(len==0)cut=1;
    if(num==0)
    return 1;
    if(q%2!=(len+num*now)%2)
    return 0;
    for(i=pos;i<n;i++)
    {
        if(len+a[i]>now)
        continue;
        if(vis[i])continue;
        vis[i]=1;
        if(a[i]+len==now)
        {
            if(a[i]%2==1)
            {
                 if(dfs(now,0,0,q-1,num-1))
                 return 1;
            }
            else
            {
                 if(dfs(now,0,0,q,num-1))
                 return 1;
            }
             vis[i]=0;
             return 0;
        }
        else
        {
            if(a[i]%2==1)
            {
              if(dfs(now,len+a[i],i+1,q-1,num))
              return 1;
            }
            else
            {
                if(dfs(now,len+a[i],i+1,q,num))
                return 1;
            }
            vis[i]=0;
            if(cut)
            return 0;
            while(i<n&&a[i]==a[i+1])
            i++;
        }
    }
    return 0;
}
int main()
{
    int i,l;int q;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<1)
        break;
        sum=0;q=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==1)
            q+=1;
            sum+=a[i];
        }
        memset(vis,0,sizeof(vis));
        sort(a,a+n,cmp);
        for(i=a[0];i<=sum;i++)
        {
            if(sum%i!=0)
            continue;
            l=sum/i;
            if(dfs(i,0,0,q,l))
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
