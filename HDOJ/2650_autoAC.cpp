#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
const int Times=10;
using namespace std;
typedef long long LL;
LL multi(LL a,LL b,LL m)
{
     LL ans=0;
     while(b)
     {
         if(b&1)
         {
             ans=(ans+a)%m;
             b--;
         }
         b>>=1;
         a=(a+a)%m;
     }
     return ans;
}
LL quick_mod(LL a,LL b,LL m)
{
     LL ans=1;
     a%=m;
     while(b)
     {
         if(b&1)
         {
             ans=multi(ans,a,m);
             b--;
         }
         b>>=1;
         a=multi(a,a,m);
     }
     return ans;
}
bool Miller_Rabin(LL n)
{
    if(n==2) return true;
    if(n<2||!(n&1)) return false;
    LL a,m=n-1,x,y;
    int k=0;
    while((m&1)==0)
    {
        k++;
        m>>=1;
    }
    for(int i=0;i<Times;i++)
    {
        a=rand()%(n-1)+1;
        x=quick_mod(a,m,n);
        for(int j=0;j<k;j++)
        {
            y=multi(x,x,n);
            if(y==1&&x!=1&&x!=n-1) return false;
            x=y;
        }
        if(y!=1) return false;
    }
    return true;
}
int main()
{
    LL a,b;
    while(~scanf("%I64d%I64d",&a,&b))
    {
        if(a==0)
        {
            if(b%4==3&&Miller_Rabin(b)) puts("Yes");
            else  puts("No");
        }
        else
        {
            LL t=a*a+2*b*b;
            if(Miller_Rabin(t)) puts("Yes");
            else  puts("No");
        }
    }
    return 0;
}
