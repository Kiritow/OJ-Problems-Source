#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1.0); 
double H,R, volume,ans,total;
int main(){
    while (scanf("%lf%lf",&R,&H) != EOF){
        total = 2*PI*R*R*H;
        if (H >= 2*R){
            volume = R*R*R*2/3;
        }
        else {
            volume =  H*H*sqrt(R*R-H*H*1/4)*1/4 + R*R*R*2/3 - R*R*sqrt(R*R-H*H*1/4) + (R*R-H*H*1/4)*sqrt(R*R-H*H*1/4)*1/3;
        }
        ans = total - 8*volume;
        printf("%.4lf\n",ans);
    }
}
