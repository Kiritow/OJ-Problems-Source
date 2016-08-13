#include<stdio.h>
int cubic[54];
void init()
{
    int i,j;
    for(i=0,j=0;i<54;++i)
        cubic[j++]=i*i*i;
}
int main()
{
    int i,j,ans,sum;
    init();
    while(scanf("%d",&sum),sum)
    {
        ans=0;
        for(i=0;i*(i+1)*(i+2)/6<=sum;++i)
        {
            for(j=53;j>=0;--j)
            {
                if(cubic[j]<=sum-i*(i+1)*(i+2)/6)
                    break;
            }
            if(ans<i*(i+1)*(i+2)/6+cubic[j])
                ans=i*(i+1)*(i+2)/6+cubic[j];
        }
        printf("%d\n",ans);
    }
    return 0;
}
