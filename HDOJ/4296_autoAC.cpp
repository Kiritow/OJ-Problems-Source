#include<cstdio>
#define ll __int64
int main()
{
    int n,w,s;
    while(~scanf("%d",&n))
    {
        ll max=0,ans=0,sum=0;
        while(n--)
        {
            scanf("%d%d",&w,&s);
            if(w+s>max) max=w+s;
            sum+=w;
        }
        sum-=max;
        if(sum>ans) ans=sum;
        printf("%I64d\n",ans);
    }
    return 0;
}
