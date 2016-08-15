#include <stdio.h>
int main()
{
    int T,N,min,max,a;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        min = 0x3f3f3f3f;
        max = -0x3f3f3f3f;
        while(N--){
            scanf("%d",&a);
            if(a>max) max = a;
            if(a<min)    min = a;
        }
        printf("%d\n",(max-min)*2);
    } 
    return 0;
}
