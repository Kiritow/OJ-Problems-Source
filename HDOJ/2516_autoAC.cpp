#include <iostream>
using namespace std;
int main()
{
   int a[50];
   __int64 i;
   long long int n;
   while(1)
   {
       cin>>n;
       if(n==1)
       continue;
       if(n==0)
        break;
       a[0]=1;
       a[1]=1;
       for(i=2;i<46;i++)
       {
           a[i]=a[i-1]+a[i-2];
       }
           for(i=0;i<46;i++)
                if(a[i]==n)
           {
               cout<<"Second win"<<endl;
                 break;
           }
           if(i==46)
            cout<<"First win"<<endl;
   }
    return 0;
}
