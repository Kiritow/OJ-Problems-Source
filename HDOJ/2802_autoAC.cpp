#include<iostream>
using namespace std;
int main()
{
    long T,yu;
    long feng;
   while(cin>>T&&T)
   {
    yu=T%4018;
    if(yu%2==0)    
        feng=((((yu*yu)/4)%2009)*((2*yu+3)%2009));
    else
        feng=((((yu+1)*(yu+1)/4)%2009)*((2*yu-1)%2009));
    printf("%ld\n",feng%2009);
   }
return 0;
}
