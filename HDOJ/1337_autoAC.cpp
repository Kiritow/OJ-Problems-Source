#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n,a[20000],i,j,k,m,t,f;
    while(scanf("%d",&n)!=EOF&&n)
    {
        while(n--)
        {    t=0;
            memset(a,0,sizeof(a));  
            scanf("%d",&m);
            f=2;
            while(f<=m)
            {
                for(i=f;i<=m;i+=f)
                {
                    if(a[i]==1)
                        a[i]=0;
                    else
                        a[i]=1;
                }
                f++;
            }
            for(i=1;i<=m;i++)
            {    if(a[i]==0)
                    t++;
            }
            printf("%d\n",t);
        }
    }
    return 0;
}
