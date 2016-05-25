#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
 
 
 
double a,b,c,d,L,R;
double delta;
double x1,x2;
 
double fx1,fx2,fL,fR;
 
int ans=0;
int i;
double maxvalue=0;
 
double* data[4]={&fL,&fR,&fx1,&fx2};
 
int main()
{
    while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&L,&R)==6)
    {
        ans=2;
        delta=b*b-3*a*c;
        fL=fabs(a*L*L*L+b*L*L+c*L+d);
        fR=fabs(a*R*R*R+b*R*R+c*R+d);
        if(delta>0)
        {
            x1=(-b-sqrt(delta))/(3*a);
            x2=(sqrt(delta)-b)/(3*a);
            fx1=fabs(a*x1*x1*x1+b*x1*x1+c*x1+d);
            fx2=fabs(a*x2*x2*x2+b*x2*x2+c*x2+d);
            ans=4;
        }
        maxvalue=*data[0];
        for(i=1;i<ans;i++)
        {
            if(*data[i]>maxvalue) maxvalue=*data[i];
        }
        printf("%.5lf\n",maxvalue);
    }
    return 0;
}
