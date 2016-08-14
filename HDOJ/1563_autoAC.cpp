#include<stdio.h>
int main()
{
    int n,m,x;
    while(scanf("%d",&n)!=EOF&&n)
    {
        x=0;
        while(n--)
        {
            scanf("%d",&m);
            if(x<m)
                x=m;
        }
        printf("%d\n",x);
    }
    return 0;    
}
