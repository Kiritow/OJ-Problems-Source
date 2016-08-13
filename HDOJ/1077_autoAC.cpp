#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 1E9
using namespace std;
double X[301],Y[301];
int n,ans;
double x,y;
inline double c(int i)
{
    return (X[i]-x)*(X[i]-x)+(Y[i]-y)*(Y[i]-y);
}
int calc()
{
    int i,ans=0;
    for(i=0;i<n;i++)
    {
        if(c(i)>1.0+1e-8)continue;
        ans++;
    }
    return ans;
}
void center(int i,int j)
{
    double x1=X[i]-X[j],y1=Y[i]-Y[j],len,k;
    double a,b;
    if(x1==0)
        a=1,b=0;
    else if (y1==0)
        a=0,b=1;
    else
    {
        k=-1/y1*x1;
        len=sqrt(1+k*k);
        a=1.0/len;
        b=k/len;
    }
    len=1-(x1*x1+y1*y1)/4;
    if(len<0)return;
    len=sqrt(len);
    x1=(X[i]+X[j])/2.0;y1=(Y[i]+Y[j])/2.0;
    a*=len;b*=len;
    x=x1+a;y=y1+b;
    ans=max(ans,calc());
    x=x1-a;y=y1-b;
    ans=max(ans,calc());
}
int main()
{
    int T;
    int i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
          scanf("%lf%lf",&X[i],&Y[i]);
        ans=0;
        for(i=0;i<n;i++)
          for(j=i;j<n;j++)
             center(i,j);
        printf("%d\n",ans);
    }
}
