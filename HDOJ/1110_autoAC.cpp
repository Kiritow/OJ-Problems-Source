#include<iostream>
#include <cmath>
using namespace std;
int main()
{    
    double a,b,x,y;int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>x>>y;
        if(a<b)
        {
            double t=b;
                   b=a;
                   a=t;
        }
        if(x<y)
        {
            double t=x;
                   x=y;
                   y=t;
        }
        if(a>x&&b>y)
            cout<<"Escape is possible."<<endl;
        if((a<=x&&b<=y)|(a>x&&b<=y))
            cout<<"Box cannot be dropped."<<endl;
        if(a<=x&&b>y)
        {
            int flog=0;
            for(double i=0;i<=90;i=i+0.2)
            {
                double rad=3.1415926*i/180;
                if(x*cos(rad)+y*sin(rad)<a&&x*sin(rad)+y*cos(rad)<b)
                {flog=1;  break;}
            }
            if(flog==1)
                  cout<<"Escape is possible."<<endl;
            if(flog==0)
                  cout<<"Box cannot be dropped."<<endl;
        }
    }
    return 0;
}
