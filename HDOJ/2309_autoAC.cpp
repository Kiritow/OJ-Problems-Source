#include<cstdio>
#include<cstdio>
int main()
{
    int n,sum,x,max,min;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        sum=0;
        max=0,min=1000;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            sum+=x;
            if(x>max)max=x;
            if(x<min)min=x;
        }
        sum-=max+min;
        sum/=n-2;
        printf("%d\n",sum);
    }
    return 0;
}
