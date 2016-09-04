#include<stdio.h>
#include<math.h>
#include<iostream>
#define eps 1e-7
using namespace std;
int n,k,vis[55],tmax,dp[55],ji;
int locat[55][2],map[55][55];
double dis[55][55],distan[2000];
int cmp(const void *a,const void*b)
{
    return *(double *)a>*(double *)b?1:-1;
}
void build(int mid)
{
    int i,f;
    for(i=1;i<=n;i++)
    {
        for(f=1;f<=n;f++)
        {
            if(dis[i][f] >= distan[mid]-eps)
            {
                map[i][f]=1;
            }
            else
            {
                map[i][f]=0;
            }
        }
        map[i][i]=0;
    }
}
void dfs(int id,int cnt)
{
    int tvis[55],i,f,able=0;
    for(i=id+1;i<=n;i++)
    {
        if(1 == vis[i])
        {
            able++;
        }    
    }
    if(0 == able)
    {
        tmax=max(tmax,cnt);
    }    
    if(cnt + able <= tmax)
    {
        return ;
    }
    for(i=1;i<=n;i++)
    {
        tvis[i]=vis[i];
    }
    for(i=id+1;i<=n;i++)
    {
        if(0 == tvis[i])
        {
            continue;    
        }
        if(cnt +dp[i] <= tmax)
        {
            continue;    
        }
        for(f=id+1;f<=n;f++)
        {
            vis[f]=tvis[f]&map[i][f];
        }
        dfs(i,cnt+1);
    }
}
int max_clique()
{
    int i,f;
    tmax=1;
    dp[n]=1;
    for(i=n-1;i>=1;i--)
    {
        for(f=1;f<=n;f++)
        {
            vis[f]=map[i][f];
        }    
        dfs(i,1);
        dp[i]=tmax;
        if(n == tmax)
        {
            return tmax;
        }
    }
    return tmax;
}
double bs()
{
    int l=0,r=ji,mid;
    while(l != r-1)
    {
        mid=(l+r)>>1;    
        build(mid);        
        if(k <= max_clique())
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    } 
    return distan[l];
}
int main()
{
    int i,f,g,sum;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        ji=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&locat[i][0],&locat[i][1]);
        }
        for(i=1;i<=n;i++)
        {
            for(f=1;f<=n;f++)
            {
                sum=0;
                for(g=0;g<2;g++)
                {
                    sum+=(locat[i][g]-locat[f][g])*((locat[i][g]-locat[f][g]));
                }
                dis[i][f]=sqrt((double)sum);
                if(i > f)
                {
                    distan[ji]=dis[i][f];
                    ji++;
                }
            }
        }
        qsort(distan,ji,sizeof(distan[0]),cmp);        
        printf("%.2lf\n",bs());
    }
    return 0;
}
