#include<stdio.h>
int main()
{
    __int64 n;
    __int64 a[]={2,3,5,7};
    while(scanf("%I64d",&n),n)
    {
        __int64 b[4]={1,1,1,1};
        for(int i=0;i<4;i++)
        { 
       while(n%a[i]==0)
         {
          b[i]++;
          n=n/a[i];
         }
       }
       printf("%I64d\n",b[0]*b[1]*b[2]*b[3]); 
    }
    return 0;
}
