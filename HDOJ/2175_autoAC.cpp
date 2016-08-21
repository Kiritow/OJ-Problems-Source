#include<stdio.h>
int main()
{
    unsigned __int64 temp,m,a[65]={0,1};
    int i,n,res;
    for(i=2;i<=64;i++)
    {
        a[i]=a[i-1]*2+1;
    }
    while(scanf("%d%I64d",&n,&m)!=EOF&&(n!=0||m!=0))
    {
        temp=a[n]+1;
       for(i=n;i>=1;i--)
       {
        temp=temp/2;  
       if(temp==m)
       {
          res=i;
          break;
       }
       if(temp<m)
           m=m-temp;
       else
           m=temp-m;
       }
       printf("%d\n",res);
    }
return 0;
}
