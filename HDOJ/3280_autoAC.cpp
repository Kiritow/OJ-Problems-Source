#include <stdio.h>
int main()
{
    int i,j,n,t,b;
    int a[10005];
    while(scanf("%d",&t)!=EOF)
    {
        int k=1;
        while(t--)
        {
            scanf("%d %d",&b,&n);
            for(i=0;i<n;i++)
               scanf("%d",&a[i]);
            int sum=0,temp,flag;
            for(i=0;i<n;i++)
            {
                sum+=a[i];
                temp=0;
                flag=0;
                for(j=i+1;j<n;j++)
                {
                    temp+=a[j];
                    if(temp==sum)
                        temp=0;
                    else if(temp>sum)
                    {
                        flag=1;
                        break;
                    }
                    else if(j==n-1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    break;
            }
            printf("%d %d\n",k++,sum);
        }
    }
    return 0;
}
