#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double PI=acos(-1.0);
int main()
{
    double a,b,c,L;
    int cout=1;
    while(cin>>a>>b>>c>>L)
    {
        if(a==0&&b==0&&c==0&&L==0)
            break;
        double p=(a+b+c)/2.0;
        double S=sqrt(p*(p-a)*(p-b)*(p-c));
        double R=S/p;
        if(L>=a+b+c)
            printf("Case %d: %.2lf\n",cout++,S);
        else if(L<=PI*R*2)
            printf("Case %d: %.2lf\n",cout++,L*L/(4*PI));
        else
        {
            double r=R*(2*p-L)/(2*p-2*PI*R);
            double s=(r/R)*(r/R)*S;
            printf("Case %d: %.2lf\n",cout++,S-s+PI*r*r);
        }
    }
    return 0;
}
