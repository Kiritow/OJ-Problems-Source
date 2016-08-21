#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,m,p;
    int t,ans;
    while(scanf("%d%d",&n,&p)!=-1)
    {
        if(p>n)    {printf("Where is hero from?\n");continue;}
        int count=0;
        ans=0;
        for(m=1;m<=n;m++)
        {
            if(m>n/2)    break;
            t=n-m+1;
            while(!(t%p))    {count++;t/=p;}
            t=m;
            while(!(t%p))    {count--;t/=p;}
            if(count<=0)    continue;
            if(2*m==n)    ans++;
            else        ans+=2;
        }
        if(!ans)    printf("Where is hero from?\n");
        else        printf("%d\n",ans);
    }
    return 0;
}
