#include<stdio.h>
int main()
{
    int n,m,n1;
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        m=n;
        n/=30;
        n=15-n;
        if(n>=12)
            n-=12;
        if(m%30==0)
            printf("Exactly %d o'clock\n",n);
        else
        {
            if(n==0)     
                n1=11;
            else
                n1=n-1;
            printf("Between %d o'clock and %d o'clock\n",n1,n);
        }
    }
    return 0;
}
