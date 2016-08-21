#include<stdio.h>  
#include<algorithm>  
using namespace  std;  
int main(){  
    int n;  
    while(~scanf("%d",&n)){  
        int as=0,a,b;  
        int v=111;  
        for(int i=0;i<n;++i){  
            scanf("%d%d",&a,&b);  
            as+=a;  
            v=min(v,b);  
        }  
        printf("%.2lf\n",1.0*as/v);  
    }   
    return 0;  
}
