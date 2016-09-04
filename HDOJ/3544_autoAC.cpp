#include<stdio.h>
int main()
{
    int T,c=0,n,i;
    __int64 a,b,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        a=b=0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&x,&y);
            while(x>1&&y>1)
            {
                x=x>>1;
                y=y>>1;
            }
            if(x==1) b+=y-1;
            if(y==1) a+=x-1;
        }
        printf("Case %d: ",++c);
        printf(a>b?"Alice\n":"Bob\n");
    }
    return 0;
}
