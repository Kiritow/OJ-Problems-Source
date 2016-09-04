#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<iostream>
#include<queue>
#include <map>
using namespace std;
typedef long long ll;
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define inf 1000000000
#define N 205
class match{
public:
    int lx[N],ly[N];
    int Stack[N],next[N];
    bool visx[N],visy[N];
    int n;
    vector<int>vec[N];
    void init()
    {
        rep(i,n+1) vec[i].clear();
        memset(next,-1,sizeof(next));
    }
    bool bfs(int u)
    {
        visx[u]=true;
        rep(i,vec[u].size())
        {
            if(visy[i]==true) continue;
            if(lx[u]+ly[i]==vec[u][i])
            {
                visy[i]=true;
                if(next[i]==-1 || bfs(next[i]))
                {
                    next[i]=u; return true;
                }
            }
            else 
                Stack[i]=min(Stack[i],lx[u]+ly[i]-vec[u][i]);
        }
        return false;
    }
    int km()
    {
        rep(i,n) lx[i]=-inf;
        rep(i,n)
        {
            ly[i]=0;
            rep(j,n) 
                lx[i]=max(lx[i],vec[i][j]);
        } 
        rep(i,n)
        {
            while(true)
            {
                memset(visx,false,sizeof(visx));
                memset(visy,false,sizeof(visy));
                rep(j,n) Stack[j]=inf;
                if(bfs(i)) break;
                int Min=inf;
                rep(j,n)
                    if(visy[j]==false)
                        Min=min(Min,Stack[j]);
                rep(j,n)
                {
                    if(visx[j]==true) lx[j]-=Min;
                    if(visy[j]==true) ly[j]+=Min;
                }
            }
        }
        int ans=0;
        rep(i,n)
            ans+=vec[next[i]][i];
        return ans;
    }
};
match sa;
int n,m;
int a[N][N];
void solve()
{
     scanf("%d%d",&n,&m);
     rep(i,m)
         rep(j,n) 
         scanf("%d",&a[i][j]),--a[i][j];
     sa.n=n;
     sa.init();
     rep(i,n)
     {
         rep(j,n)
         {
             int sum=0;
             rep(k,m)
                 sum+=-abs(j-a[k][i]);
             sa.vec[i].push_back(sum);
         }
     }
     printf("%d\n",-sa.km());
}
int main()
{
      int test;
      scanf("%d",&test);
      repf(ror,1,test)
      {
          printf("Case #%d: ",ror);
          solve();
      }
      return 0;
}
