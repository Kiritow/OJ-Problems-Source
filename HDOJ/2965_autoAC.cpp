#include<stdio.h>
typedef long long LL;
LL getgcd(LL a,LL b)
{
    if(!b)return a;
    return getgcd(b,a%b);
}
void gcd(LL a,LL b,LL& d,LL& x,LL& y)
{
    if(!b){d=a;x=1;y=0;}
    else
    {
       gcd(b,a%b,d,y,x);
       y-=x*(a/b);
    }
}
bool calcu(LL a,LL b,LL x,LL y)
{
    if(x<0)
    {
       while(x<0)
       {
          x+=b;
          y-=a;
       }
       if(y>0)
          return true;
    }
      else if(y<0)
    {
      while(y<0)
      {
        x-=b;
        y+=a;
      }
      if(x>0)
        return true;
    }
    return false;
}
int main()
{
   int t;
   LL a,b,c,d;
   scanf("%d",&t);
   while(t--)
   {
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
        if(c%a==0&&d%b==0||c%b==0&&d%a==0)
           printf("YES\n");
     else
     {
         LL p=getgcd(a,b);
         if(c%p||d%p)
            printf("NO\n");
          else
          {
              a/=p;b/=p;
              c/=p;d/=p;
              LL x,y,gg=a*b,v;
              if(c%gg==0)
              {
                  gcd(a,b,v,x,y);
                  if(calcu(a,b,x*d,y*d))
                {
                    printf("YES\n");
                    continue;
                }
              }
              if(d%gg==0)
              {
                  gcd(a,b,v,x,y);
                  if(calcu(a,b,x*c,y*c))
                  {
                      printf("YES\n");
                      continue;
                  }
              }
           printf("NO\n");
          }
     }
   }
   return 0;
}
