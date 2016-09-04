#include<stdio.h>
#include<math.h>
int T,n;
int i,j,qujian[100001],began,t,res;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        t=(int)(sqrt(n)+0.99999);
        res=t*t-n;
        for(i=0;i<t;i++) qujian[i]=t;
        for(i=0;i<t;i++)
            if(qujian[i]<res+1)
            {
                qujian[i]=1;
                res-=(t-1);
            }
            else
            {
                qujian[i]-=res;
                break;
            }
        began=0;
        for(i=0;i<t;i++)
        {
            began+=qujian[i];
            for(j=0;j<qujian[i];j++)
                if(i==t-1&&j==qujian[i]-1) printf("%d\n",began-j);
                else printf("%d ",began-j);
        }
    }
    return 0;
}
