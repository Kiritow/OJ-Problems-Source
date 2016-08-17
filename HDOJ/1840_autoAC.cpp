#include <stdio.h>
int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        if(a!=0){
            if(b*b-a*4*c>0)
                printf("2\n");
            else if(b*b==4*a*c)
                printf("1\n");
            else
                printf("0\n");
        }
        else{
            if(b==0){
                if(c==0)
                    printf("INF\n");
                else
                    printf("0\n");
            }
            else
                printf("1\n");
        }
    }
    return 0;
}
