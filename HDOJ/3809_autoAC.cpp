#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    int t,tt;
    double x,y,x1,y1;
    scanf("%d",&t);
    tt=t;
    while (t--){
          scanf("%lf%lf",&x1,&y1);
          x=x1,y=y1; 
          for (int i=0;i<30;i++){
              x=x1+sqrt(y);
              y=y1+sqrt(x);
              }
          printf("Case %d: %.6lf %.6lf\n",tt-t,x,y);
          }
    return 0;
}
