#include<iostream>
#include<iomanip>
using namespace std;
double max(double a,double b,double c){
    if(b>a) a=b;
    if(c>a) a=c;
    return a;
}
double min(double a,double b,double c){
    if(b<a) a=b;
    if(c<a) a=c;
    return a;
}
int main(){
    const double vsm=5.9;
    const double vsh=719.0/120;
    const double vmh=11.0/120;
    const double tsm=3600.0/59;
    const double tsh=43200.0/719;
    const double tmh=43200.0/11;
    double d,t,start,end;
    while(cin>>d,d!=-1){
        t=0;
        for(int i=0;i<11;i++){
            for(int j=(int)((tmh*i+d/vmh-d/vsm)/tsm);j<=(int)((tmh*(i+1)-d/vmh-d/vsm)/tsm);j++){
                for(int k=(int)((tsm*j+d/vsm-d/vsh)/tsh);k<=(int)((tsm*(j+1)-d/vsm-d/vsh)/tsh);k++){
                    start=max(tsh*k+d/vsh,tsm*j+d/vsm,tmh*i+d/vmh);
                    end=min(tsh*(k+1)-d/vsh,tsm*(j+1)-d/vsm,tmh*(i+1)-d/vmh);
                    if(start<end) t+=end-start;
                }
            }
        }
        cout<<fixed<<setprecision(3)<<t/432<<endl;
    }
    return 0;
}
