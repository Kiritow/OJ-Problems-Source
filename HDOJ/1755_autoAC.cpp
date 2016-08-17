#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[10],n;
int num[40320*9];
int getnum()
{
    int res=0,i;
    for(i=1;i<=n;i++)
        res=res*10+a[i];
    return res;
}
int main()
{
    int m,k,x,i,t;
    bool flag;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        t=0;
        if(a[1]!=0)
            num[t++]=getnum();
        while(next_permutation(a+1,a+1+n))
        {
            if(a[1]!=0)
                num[t++]=getnum();
        }
        while(m--)
        {
            scanf("%d%d",&x,&k);
            flag=true;
            for(i=0;i<t;i++)
            {
                if((num[i]+x)%k==0)
                {
                    printf("%d\n",num[i]);
                    flag=false;
                    break;
                }
            }
            if(flag)
                printf("None\n");
        }
    }
    return 0;
}
