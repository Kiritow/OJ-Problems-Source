#include <stdio.h>
int main()
{
    int N;
    int a;
    int l;
    scanf("%d",&N);
        while(N--){
            scanf("%d",&a);
            l = 0;
            while(a>1){
                if(a%2){
                    if(l == 1)
                        printf(" ");
                    l = 1;
                    printf("%d",a);
                    a = a*3+1;
                }
                if(a % 2 == 0){
                    a = a/2;
                }
            }
            if(l == 0)
                printf("No number can be output !");
            printf("\n");
        }
    return 0;
}
