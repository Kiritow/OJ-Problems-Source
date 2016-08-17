#include<stdio.h>
int main()
{
    int a,b,n,q,w;
    long int t;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%ld",&a,&b,&t);
        q=t%a;w=t%b;
        if(q<w)
            printf("Sempr!\n");
        else if(q==w)
            printf("Both!\n");
        else
            printf("Xiangsanzi!\n");
    }
}
