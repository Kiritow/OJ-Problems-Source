#include <cstdlib>
#include <iostream>
#include <algorithm>
#define lowbit(x)  x&(-x)
using namespace std;
const int maxn = 500050;
const __int64 mod =1000000007;
__int64 a[maxn],b[maxn],c[maxn],e[maxn];
 int k;
int find(__int64 key)
{
     int l=1,r=k;
     while(l<=r)
     {
         int mid = (l+r)>>1;               
          if(b[mid]==key) return mid;
         if(b[mid]<key) 
            l=mid+1;
         else
            r=mid-1;
     }    
}
 void insert(int p,int d)
 {
      for(int i=p;i<=k;i+=lowbit(i))
      {
          e[i]+=d;  
          e[i]%=mod;
      }
 }
  __int64 query(int p)
  {
      __int64 sum=0;
      for(int i=p;i>0;i-=lowbit(i)) 
      {
          sum+=e[i];
          sum%=mod;        
      }  
      return sum;     
  }
int main(int argc, char *argv[])
{
     int t,cas=1;
     __int64 n,m,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&m,&x,&y,&z);
        for(int i=0;i<m;i++)
             scanf("%I64d",&a[i]);
         for(int i=0;i<=n-1;i++)
         {
             b[i+1]=a[i%m];
             c[i+1]=b[i+1];
             a[i%m]=(x*a[i%m]+y*(i+1))%z;
        }
         sort(b+1,b+1+n);
         k = 1;
         for(int i=2;i<=n;i++)
          if(b[i]!=b[i-1])  b[++k]=b[i];
         memset(e,0,sizeof(e));
         __int64 sum= 0 ;
         for(int i=1;i<=n;i++)
         {
           int  ans = find(c[i]);
           int num=query(ans-1);
           num%=mod;
           sum+=num+1;
           sum%=mod;
           insert(ans,num+1);
         }
     printf("Case #%d: %I64d\n",cas++,sum);
    }
    return 0;
}
