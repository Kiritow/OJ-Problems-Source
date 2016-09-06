#include <iostream>
#include <stdio.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
bool run_year(int z)
{
    if((z%4==0&&z%100!=0)||(z%400==0))
        return true;
    else
        return false;
}
int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
   int T,num=0;
   scanf("%d",&T);
   while(T--)
   {
       num++;
       int x,y,z;
       int fx,fy;
       int a,b;
       scanf("%d%d%d",&a,&b,&z);
       int ans=0;
       for(x=1;x<=12;x++)
       {
           for(y=1;y<=month[x];y++)
           {
               int g=gcd(x,y);
               if(a==g&&(b==(x*y)/g))
               {
                   if(x==2&&y==29&&!run_year(z)) continue;
                   ans++;
                   fx=x;fy=y;
               }
           }
       }
       if(ans==0) printf("Case #%d: -1\n",num);
       else if(ans==1)  printf("Case #%d: %04d/%02d/%02d\n",num,z,fx,fy);
       else
          printf("Case #%d: 1\n",num);
   }
    return 0;
}
