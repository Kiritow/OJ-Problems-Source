#include<stdio.h>
int su(int a)
{
    int i,t=1;
    for(i=2;i<=a/2;i++)
        if(a%i==0)
        {
            t=0;break;
        }
    return t;
}
int main()
{
    int n,i,a,b,j;
    while(~scanf("%d",&n))
    {
        if(n==0)return 0;
        int count=0;
        for(i=2;i<n/2;i++)
        {
            j=n-i;
            if(su(i)==1&&su(j)==1)
            {count++;    }            
        }
        printf("%d\n",count);
    }
}
