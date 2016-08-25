#include<iostream>
using namespace std;
int main()
{
    double a[4];
    while(cin>>a[0]>>a[1]>>a[2]>>a[3],(a[0]+a[1]+a[2]+a[3])!=0)
    {
        double min=0,max=0;
        int i;
        double l[3],r[3];
            l[0]=a[1]-0.5;
            l[1]=a[2]-0.5;
            l[2]=a[3]-0.5;
            if(l[0]<0)
                l[0]=0.0;
            if(l[1]<0)
                l[1]=0.0;
            if(l[2]<0)
                l[2]=0.0;
            for(i=0;i<3;i++)
            {
                r[i]=a[i+1]+0.499999;
            }
                min=l[0]*9+l[1]*4+l[2]*4;
                max=r[0]*9+r[1]*4+r[2]*4;
        if(a[0]<=max&&a[0]>=min)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
