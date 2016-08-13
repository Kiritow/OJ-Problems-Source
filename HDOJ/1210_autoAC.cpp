#include<stdio.h>
int main()
{
    int m,x,ans;
    while(~scanf("%d",&m))
    {
        x=1;
        ans = 0;
        do
        {
            if(x<=m)
             x = 2*x;
            else
             x = 2*(x-m)-1; 
             ans++; 
        }
        while(x!=1); 
        printf("%d\n",ans);
    }
}
