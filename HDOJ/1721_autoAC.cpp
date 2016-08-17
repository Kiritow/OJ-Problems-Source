#include<iostream>
using namespace std;
int a[8];
int main()
{
    int x;
    while(cin>>x)
    {
        int sum1;
        int sum2;
        if(x==-1)
            break;
        a[0]=x;
         for(int i=1;i<=7;i++)
         {
             cin>>a[i];
         }
         sum1=a[0]+a[2]+a[5]+a[7];
         sum2=a[1]+a[3]+a[4]+a[6];
         if(sum1==sum2)
             cout<<"All the seeds can be cleared away!"<<endl;
         else
             cout<<"Sorry,it can't be cleared away!"<<endl;
         char c=getchar();
    }
        return 0;
}
