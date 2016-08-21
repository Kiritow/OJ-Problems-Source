#include <iostream>
#include <math.h>
#define PI 3.1415926535898
using namespace std;
double xx,yy,l,w;
double d(double x){
       double s=sin(x),c=cos(x);
       return yy*c+xx*s-l*s*c;
       }
int main(){
    double dl,dr,ml,mr;
    while(cin >> xx >> yy >> l >> w){
       dl=0;dr=PI/2;
       while(dr-dl>0.0000001){
          ml=dl/3*2+dr/3;
          mr=dl/3+dr/3*2;
          if(d(ml)<d(mr))dr=mr;else dl=ml;
          }       
       if(w<d(dl))cout << "yes" << endl;
       else cout << "no" << endl;
       }
    return 0;
}
