#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long  a[3];
int main()
{
    while(~scanf("%I64d%I64d%I64d",&a[0],&a[1],&a[2]))
    {
       long long  n=a[0]+a[1]+a[2];
        sort(a,a+3);
        if(a[2]==0)
            printf("0\n");
        else if(a[1]==0)
        {
            if(a[2]==1)
                printf("0\n");
            else
                printf("%I64d\n",1+(n-2)*2);
        }
        else if(a[0]==0)
        {
            if(a[1]==1)
            {
                if(a[2]==1)
                    printf("1\n");
                else
                    printf("%I64d\n",1+2+(n-3)*3);
            }
            else
                printf("%I64d\n",1+2+3+(n-4)*4);
        }
        else
        {
            if(a[0]>=2)
            {
                printf("%I64d\n",15+(n-6)*6);
            }
            else if(a[0]==1)
            {
                if(a[1]==1)
                {
                    if(a[2]==1)
                    {
                        printf("%I64d\n",1*1LL+2);
                    }
                    else
                    {
                        printf("%I64d\n",1+2+3+(a[2]-2)*4);
                    }
                }
                else
                {
                    printf("%I64d\n",1+2+3+4+(n-5)*5);
                }
            }
        }
    }
    return 0;
}
