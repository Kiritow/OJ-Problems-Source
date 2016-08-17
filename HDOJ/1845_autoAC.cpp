#include<stdio.h>
int main()
{
    int T;
    int t;
    int a,b;
    int n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        t=3*n/2;
        while(t--)    scanf("%d%d",&a,&b);
        printf("%d\n",n/2);
    }
    return 0;
}
