#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000010
#define esp 1e-10
using namespace std;
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
 double x,a,b;
 scanf("%lf%lf%lf",&x,&a,&b);
 int ans=0;
 while(x*(1-b)>=a+esp)
 {
 ans++;
 x*=(1-b);
 }
 printf("Samuel will change the appearance for %d time(s),before he decide to sell it.\n",ans);
 }
 return 0;
}
