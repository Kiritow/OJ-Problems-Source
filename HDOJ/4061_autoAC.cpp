#include<stdio.h>
#include<cstring>
#include<algorithm>
#define I(x) scanf("%d",&x)
using namespace std;
int main(){
    int n,a,sum,t,b,ca=0;
    I(t);
    while(t--){
        I(n);
        sum=0;
        for(int i=0;i<n;i++){
            I(a);
            sum+=a;
            if(i==0) b=a;
        }
        printf("Case %d: %.6lf\n",++ca,1.0*b/sum);
    }
    return 0;
}
