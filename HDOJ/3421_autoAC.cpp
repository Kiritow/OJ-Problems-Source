#include<stdio.h>
__int64 he;
int main()
{
    int t,n,i,ret,qian,j,dang;
    scanf("%d",&t);
    for(i=1;i<=t;)
    {
        he=0;
        scanf("%d",&n);
        qian=-1;
        ret=0;
        int ji=0;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&dang);
            if(dang>0) he+=dang;
            if(ji)
            {
                if(dang<0)
                {
                    ji=0;
                }
            }else
            {
                if(dang==0)
                {
                }else if(dang>0)
                {
                    ji=1;
                    ret++;
                }
            }
        }
        if(i!=1)
            printf("\n");
        printf("Case %d:\n",i++);
        printf("%d %I64d\n",ret,he);
    }
    return 0;
}
