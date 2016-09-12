#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x7fffffff
using namespace std;
typedef long long LL;
const LL maxn=10000+10;
LL n,m;
struct Point
{
    LL x,y,z;
    Point (LL x=0,LL y=0,LL z=0):x(x),y(y),z(z){}
}a,b,c,d;
typedef Point Vector;
double Dot(Vector A,Vector B) {return A.x*B.x + A.y*B.y; }
double Length(Vector A) {return sqrt(Dot(A,A)); }
double angle(Vector A,Vector B) {return acos(Dot(A,B)/Length(A)/Length(B)); }
LL dis(Point A,Point B)
{
    LL xx=(A.x-B.x)*(A.x-B.x);
    LL yy=(A.y-B.y)*(A.y-B.y);
    LL zz=(A.z-B.z)*(A.z-B.z);
    return xx+yy+zz;
}
int main()
{
    int t,ncase=1;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",
            &a.x,&a.y,&a.z,&b.x,&b.y,&b.z,&c.x,&c.y,&c.z,&d.x,&d.y,&d.z);
             int flag=0;
        LL len,len2,len3;
        len=dis(a,b) ;len2=dis(a,c) ;len3=dis(a,d) ;
        if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
            flag++;
        len=dis(b,a) ;len2=dis(b,c) ;len3=dis(b,d) ;
        if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
            flag++;
            len=dis(c,a) ;len2=dis(c,b) ;len3=dis(c,d) ;
        if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
            flag++;
            len=dis(d,a) ;len2=dis(d,b) ;len3=dis(d,c) ;
        if ((len==len2&&len3==len+len2)||(len==len3&&len2==len+len3)||(len2==len3&&len==len2+len3))
            flag++;
        if (flag==4) printf("Case #%d: Yes\n",ncase++);
        else printf("Case #%d: No\n",ncase++);
    }
    return 0;
}
