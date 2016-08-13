#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int sum;
    while(scanf("%d",&sum)!=EOF)
    {
        if(sum==-1)
        break;
        int totle, num=-1;
        for(int i=10;i>1;i--)
        {
            totle=sum;
            bool bo=true;
            for(int j=1;j<=i;j++)
            {
                if((totle-1)%i==0)
                {
                    totle=(totle-1)/i*(i-1);
                }
                else
                {
                    bo=false;
                    break;
                }
            }
            if(totle%i!=0)
            bo=false;
            if(bo)
            {
                num=i;
                break;
            }
        }
        if(num!=-1)
        printf("%d coconuts, %d people and 1 monkey\n",sum,num);
        else
        printf("%d coconuts, no solution\n",sum);
    }
}
