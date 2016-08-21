#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iterator>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;
#define si1(a) scanf("%d",&a)
#define si2(a,b) scanf("%d%d",&a,&b)
#define sd1(a) scanf("%lf",&a)
#define sd2(a,b) scanf("%lf%lf",&a,&b)
#define ss1(s)  scanf("%s",s)
#define pi1(a)    printf("%d\n",a)
#define pi2(a,b)  printf("%d %d\n",a,b)
#define mset(a,b)   memset(a,b,sizeof(a))
#define forb(i,a,b)   for(int i=a;i<b;i++)
#define ford(i,a,b)   for(int i=a;i<=b;i++)
typedef long long LL;
const int N=100005;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
double H,D,V,R;
double xiaohao(double r)
{
    double xh=0;
    xh+=H*R*R*acos((R-r)/R)/3.0;
    xh-=2.0/3.0*(R-r)*H*sqrt(R*R-(R-r)*(R-r));
    xh+=1.0/3.0*(R-r)*(R-r)*(R-r)*H/R*log((R+sqrt(R*R-(R-r)*(R-r)))/(R-r));
    return xh;
}
int main()
{
    int i,j,T;
    si1(T);
    while(T--)
    {
        sd1(H);sd2(D,V);
        R=D/2;
        double low=0,up=R,m,tmp;
        while((up-low)>eps)
        {
            m=(up+low)/2;
            double tmp=xiaohao(m);
            if(tmp>V)
                up=m;
            else
                low=m;
        }
        printf("%.5f\n",D-m);
    }
    return 0;
}
