#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50;
const __int64 INF=(__int64)1<<60;
typedef __int64 lld;
typedef struct node
{
    lld v[maxn][maxn];    
    }node;
node d,e1,e2,e;
int n,tmin,tmax;
node mul1(node a,node b)
{
    int i,j,k;
    node c;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        c.v[i][j]=-INF;
        for(k=0;k<n;k++)
        {
            if(a.v[i][k]==-INF||b.v[k][j]==-INF)continue;            
            c.v[i][j]=max(c.v[i][j],a.v[i][k]+b.v[k][j]);            
            }               
        } 
    return c;    
    }
node fen1(int k)
{
    if(k==0)return e; 
    if(k==1)return d;
    node p=d,t;
    int c=0;
    while(k)
    {
          if(k&1)
          {
             if(c==0)t=p;
             else t=mul1(t,p);
             c++;    
             } 
          p=mul1(p,p);
          k>>=1;   
          } 
    return t;      
    }     
node mul2(node a,node b)
{
    int i,j,k;
    node c=a;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            if(a.v[i][k]==-INF||b.v[k][j]==-INF)continue;            
            c.v[i][j]=max(c.v[i][j],a.v[i][k]+b.v[k][j]);            
            }               
        } 
    return c;    
    }
node fen2(int k)
{
    if(k==0)return e; 
    if(k==1)return d;
    node p=d,t;
    int c=0;
    while(k)
    {
          if(k&1)
          {
             if(c==0)t=p;
             else t=mul2(t,p);
             c++;    
             } 
          p=mul2(p,p);
          k>>=1;   
          } 
    return t;      
    }      
int main()
{
    int i,j,k;
    for(i=0;i<50;i++)for(j=0;j<50;j++)e.v[i][j]=0;
    for(i=0;i<50;i++)e.v[i][i]=1;
    while(scanf("%d%d%d",&n,&tmin,&tmax)!=EOF)
    {
          for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          {
              scanf("%I64d",&d.v[i][j]);
              if(d.v[i][j]==-500)d.v[i][j]=-INF;            
              }
          e1=fen1(tmin); 
          d.v[n-1][n-1]=0; 
          e2=fen2(tmax-tmin);
          lld ans=-INF;
          if(tmax==tmin)ans=e1.v[0][n-1];           
          else
          {   
             for(k=0;k<n;k++)if(e1.v[0][k]!=-INF&&e2.v[k][n-1]!=-INF)ans=max(ans,e1.v[0][k]+e2.v[k][n-1]);
             }
          if(ans==-INF)printf("IMPOSSIBLE\n");
          else cout<<ans<<endl;               
          }
    return 0;
}
