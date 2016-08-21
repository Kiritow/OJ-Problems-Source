#include <iostream>
#define INF 1<<30
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#include <math.h>
using namespace std;
int f(int a,int b,int c)
{
    int mark=0;
    int sum1,sum2,sum3;
        sum1=sum2=sum3=INF;
    if((a-b)%3==0)
    {
        mark=1;
        sum1=MAX(a,b);
    }
    if((a-c)%3==0)
    {
        mark=1;
        sum2=MAX(a,c);
    }
    if((b-c)%3==0)
    {
        mark=1;
        sum3=MAX(b,c);
    }
    if(mark==0)
        return 0;
    else
        return MIN(MIN(sum1,sum2),sum3);
}
int main()
{
    int y,b,r,sum;
    while(cin>>y>>b>>r)
    {
        sum=f(y,b,r);
        if(sum==0)
            cout<<"):"<<endl;
        else    
            cout<<sum<<endl;
    }
    return 0;
}
