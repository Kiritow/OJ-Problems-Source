#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<string>
#define Min(a,b) a<b?a:b
#define Max(a,b) a>b?a:b
#define CL(a,num) memset(a,num,sizeof(a));
#define maxn  60100
#define eps  1e-6
#define inf 9999999
using namespace std;
struct node
{
    int f;
    int s;
    int id;
}p[maxn] ;
int vis[maxn];
int cmp(const node a,const node b)
{
    if( a.s != b.s) return a.s > b.s;
    else
       if(a.f != b.f) return a.f > b.f ;
       else
        return a.id < b.id;
}
int main()
{
    int t,i,j,n,k,cnt;
    int cas = 0 ;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
          int mx = -1;
      scanf("%d",&n);
      for(i = 1;i <=n;i++ )
      {
          scanf("%d%d",&p[i].f,&p[i].s);
          p[i].id = i;
          if(mx < p[i].f)
          {
              mx = p[i].f ;
              k  = i;
          }
     }
      printf("Case #%d:\n",++cas);
      printf("%d",k);
      vis[k] = 1 ;
      if(n > 510)cnt = 510;
      else cnt = n;
      for(i = 1;i <= cnt - 1;i++)
      {
          mx = -1;
          for(j = 1;j <= n;j++)
          {
              if(!vis[j])
              {
                  p[j].f +=p[j].s;
                  if(mx < p[j].f)
                  {
                      k = j;
                      mx = p[j].f;
                  }
              }
          }
          printf(" %d",k);
          vis[k] = 1;
      }
      if(cnt < n)
      {
          sort(p + 1,p+1+n,cmp);
          for(i = 1; i <= n;i++)
          {
              if(!vis[p[i].id])
              {
                  printf(" %d",p[i].id);
                  vis[p[i].id] = 1;
              }
          }
      }
      printf("\n");
    }
    return 0;
}
