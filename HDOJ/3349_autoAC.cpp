#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
double a,b,c;
int main() {
    int t;
    cin>>t;
    while(t--) {
        scanf("%lf%lf%lf",&a,&b,&c);
        if(b<c)
            swap(b,c);
        double x=b/2;
        double y=c/2;
        double r=sqrt(2*a*a);
        double ans;
        if(r<y) {
            ans=a*a;
        } else {
            if(y<r/2) {
                ans=y*y;
            } else {
                double z=r-y;
                ans=a*a-z*z;
            }
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
