#include<stdio.h>
int main()
{
    int temp,t,n,s,x,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=s=temp=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x>1)    temp=1;
            s^=x;
        }
        if((s&&temp)||(!s&&!temp))
            puts("John");
        else
            puts("Brother");
    }
    return 0;
}
