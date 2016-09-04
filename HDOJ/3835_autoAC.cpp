#include<stdio.h>
#include<math.h>
int main()
{
    int k,i,j,n,ans;
    while(~scanf("%d",&n))
    {
        if(!n)
        {
            printf("1\n");
            continue;
        }
        ans=0;
        k=(int)sqrt(n/2.0);
        for(i=0;i<=k;++i)
        {
            j=(int)sqrt(n-i*i);
            if(i*i+j*j==n)
            {
                if(i==j||i==0||j==0)  
                    ans+=4;
                else
                    ans+=8;   
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
