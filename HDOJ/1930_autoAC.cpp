#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
__int64 carry[100],yuan[100];
__int64 t,n,m1,m2,m3,m4,i,j;
__int64 a,b,c,d;
__int64 ex_gcd(__int64 a,__int64 b,__int64 &x, __int64 &y)
{
    if(b == 0)
    {
        x=1;
        y=0;
        return a;
    }
    __int64 result = ex_gcd(b,a%b,x,y);
    __int64 t=x;
    x=y;
    y=t-a/b*y;
    return result;
}
void  china(__int64 num)
{
    __int64 M,t,x,y,res=0;
    M=m1*m2*m3*m4;
    t=M/m1;
    ex_gcd(t,m1,x,y);
    res=(res+t*a*x)%M;
    t=M/m2;
    ex_gcd(t,m2,x,y);
    res=(res+t*b*x)%M;
    t=M/m3;
    ex_gcd(t,m3,x,y);
    res=(res+t*c*x)%M;
    t=M/m4;
    ex_gcd(t,m4,x,y);
    res=(res+t*d*x)%M;
    yuan[num]=(res%M+M)%M;
}
void chu(__int64 ji)
{
    if(ji == 27)printf(" ");
    else  printf("%c",ji+'A'-1);
}
int main()
{
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        scanf("%I64d %I64d %I64d %I64d",&m1,&m2,&m3,&m4);
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&carry[i]);
            a=carry[i]/1000000;
            b=carry[i]/10000%100;
            c=carry[i]/100%100;
            d=carry[i]%100;
            china(i);
            a=yuan[i]/10000;
            b=yuan[i]/100%100;
            c=yuan[i]%100;
            if(i == n-1)
            {
                chu(a);
                if(b != 27)chu(b);
                if(c != 27)chu(c);
            }
            else 
            {
                chu(a);
                chu(b);
                chu(c);
            }
        }
        puts("");
    }
    return 0;
}
