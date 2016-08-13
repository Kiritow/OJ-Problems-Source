#include <iostream>
#include <cmath>
#define maxn 102
#define eps 1e-8
using namespace std;
int m,k,i,j,n,ans,cnt[maxn];
struct point
{
 friend inline istream & operator >> (istream & in, point &p)
 {
  in>>p.x>>p.y>>p.z;
        return in;
     }
 point& operator -(point& b)
 {
  point a;
  a.x=x-b.x;
  a.y=y-b.y;
  a.z=z-b.z;
  return a;
 }
 double x,y,z;
};
bool equal(double a,double b)
{
 return fabs(a-b)<eps;
}
double cal(point a,point b)
{
 return a.x*b.x+a.y*b.y+a.z*b.z;
}
int main()
{
 point o,v1,v2,sate[maxn],trop[maxn];
 while(cin>>k>>m&&(m||k))
 {
  o.x=0,o.y=0,o.z=0;
  ans=0;
  memset(cnt,0,sizeof(cnt));
  for(i=0;i<k;i++)cin>>sate[i];
  for(i=0;i<m;i++)cin>>trop[i];
  for(i=0;i<k;i++)
  {
   for(j=0;j<m;j++)
   {
    v1=o-trop[j];
    v2=sate[i]-trop[j];
    if(cal(v1,v2)<0||equal(cal(v1,v2),0))cnt[j]=1;
   }
  }
  for(i=0;i<m;i++)if(cnt[i])++ans;
  cout<<ans<<endl;
 }
}
