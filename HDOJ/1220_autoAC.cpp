#include <stdio.h>
int main(){
    int n;
    while(~scanf("%d",&n)){
        printf("%d\n",n*n*(n-1)/2*(n*n*n-2)+n*n*n*(n*n-5)/2+2*n*n);
    }
    return 0;
}
