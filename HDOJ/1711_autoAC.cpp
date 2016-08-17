#include<stdio.h>
int a[1000000],b[10000],t,n,m,i,j,flag=0,k=0;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<m;i++)
            scanf("%d",&b[i]);
        i=0;
        for(j=0;j<n;j++)
        {
            if(b[i]==a[j])
                i++;
            if(i==m)
            {
                printf("%d\n",j-m+2);
                flag=1;
                i=0;
                break;
            }
            else if(i!=m&&b[i-1]!=a[j])
            {
                j=k;
                k++;
                i=0;
            }
        }
        if(flag==0)
            printf("-1\n");
        flag=0;
        k=0;
    }
    return 0;
}
