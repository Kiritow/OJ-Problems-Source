#include <stdio.h>
double Factorical(int n)
{
    int ans=1;int i;
    double sum=1.0;
    for(i=1;i<=n;++i)
    {
        ans=ans*i;
        sum+=(double)1/ans;
    }
    return sum;
}
int main()
{
    int i;
    printf("n e\n");
    printf("- -----------\n") ;   
    for(i=0;i<10;i++)
    {
         if(i==0)
             printf("%d %d\n",i,1);
         else if(i==1)
              printf("%d %d\n",i,2);
            else if(i==2)
                 printf("%d %.1f\n",i,2.5);
                else 
                    printf("%d %.9lf\n",i,Factorical(i));
    }
    return 0;
}
