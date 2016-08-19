#include <stdio.h>
#include <math.h>
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n,m){
        double x=sqrt(n*n-4*m);
        printf((int) x==x?"Yes\n":"No\n");
    }
}
