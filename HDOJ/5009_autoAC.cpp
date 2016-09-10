#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std ;
const int INF=0xfffffff ;
int n,dp[50005] ;
struct node 
{
    int num ;
    int id,rank ;
}kk[50005] ;
int a[50005] ;
int vis[50005] ;
int cmp1(node aa,node bb)
{
    return aa.num<bb.num ;
}
int cmp2(node aa,node bb)
{
    return aa.id<bb.id ;
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1 ;i<=n ;i++)
        {
            scanf("%d",&a[i]) ;
        }
        int m=n ;
        for(int i=2 ;i<=n ;i++)
        {
            if(a[i]==a[i-1])
            {
                m-- ;
            }
        }
        int cnt=2 ;
        kk[1].id=1 ;kk[1].num=a[1] ;
        for(int i=2 ;i<=n ;i++)
        {
            if(a[i]!=a[i-1])
            {
                kk[cnt].id=cnt ;
                kk[cnt].num=a[i] ;
                cnt++ ;
            }
        }
        sort(kk+1,kk+1+m,cmp1) ;
        kk[1].rank=1 ;
        cnt=2 ;
        for(int i=2 ;i<=m ;i++)
        {
            if(kk[i].num!=kk[i-1].num)
            {
                kk[i].rank=cnt++ ;
            }
            else kk[i].rank=kk[i-1].rank ;
        }
        sort(kk+1,kk+1+m,cmp2) ;
        for(int i=0 ;i<50005 ;i++)
            dp[i]=INF ;
        dp[0]=0 ;
        dp[m]=m ;
        vector <int> v ;
        for(int i=0 ;i<m ;i++)
        {
            cnt=0 ;
            for(int j=i+1 ;j<=m ;j++)
            {
                if(!vis[kk[j].rank])
                {
                    v.push_back(kk[j].rank) ;
                    vis[kk[j].rank]=1 ;
                    cnt++ ;
                }
                if(dp[i]+cnt*cnt>=dp[m])break ;
                dp[j]=min(dp[j],dp[i]+cnt*cnt) ;
            }
            for(int j=0 ;j<v.size() ;j++)
                vis[v[j]]=0 ;
            v.clear() ;
        }
        printf("%d\n",dp[m]) ;
    }
    return 0 ;
}
