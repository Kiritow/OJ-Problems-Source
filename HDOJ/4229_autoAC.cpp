#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 int a,b,c,d,i,j,k,h,t;
 while(cin>>a>>b>>c>>d)
 {
  if(a==0&& b==0&& c==0&& d==0)
   break;
  else
  {
   if(a==b&& b==c&& c==d)
    t=0;
   else
   {
    t=0;
    while(a|| b || c|| d)
    {
     i=abs(a-b);
     j=abs(b-c);
     k=abs(c-d);
     h=abs(d-a);
     a=i,b=j,c=k,d=h;
     t++;
    }
    t-=1;
   }
   cout<<t<<endl;
  }
 }
 return 0;
}
