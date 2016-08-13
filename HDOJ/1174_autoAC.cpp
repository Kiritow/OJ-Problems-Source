#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int T;
   double h1,r1,x1,y1,z1;
   double h2,r2,x2,y2,z2,x3,y3,z3;
   while(cin>>T)
   {
       while(T--)
       {
            cin>>h1>>r1>>x1>>y1>>z1;
            cin>>h2>>r2>>x2>>y2>>z2>>x3>>y3>>z3;
            double x4,y4,z4;
            x4 = x1 - x2;
            y4 = y1 - y2;
            z4 = z1 + h1 - r1 - (0.9*h2 + z2 - r2 );
            double m,m1,m2;
            m = x3*x4 + y3*y4 + z3*z4;
            m1 = sqrt(x3*x3 + y3*y3 + z3*z3);
            m2 = sqrt(x4*x4 + y4*y4 + z4*z4);
            double dcos;
            dcos = m/(m1*m2);
            if(dcos<0) { cout<<"NO";continue;}
            else
            {
               double d = m2*sqrt(1 - dcos*dcos);
               if( d <= r1 ) cout<<"YES"<<endl;
               else cout<<"NO"<<endl;
            }
       }
    }
    return 0;
}
