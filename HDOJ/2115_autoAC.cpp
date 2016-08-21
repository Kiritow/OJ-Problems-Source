#include<stdio.h>
#include<string.h>
int main()
{
    int n,k=1,i,j,s,mc,a[10],b[10];
    char c[10][50],q[50];
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s %d:%d",c[i],&a[i],&b[i]);
            getchar();
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[i])
                {
                    s=a[j];a[j]=a[i];a[i]=s;
                    s=b[j];b[j]=b[i];b[i]=s;
                    strncpy(q,c[j],50);strncpy(c[j],c[i],50);strncpy(c[i],q,50);
                }
            }
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;a[j]==a[i];j++)
            {
                if(b[j]<b[i])
                {
                    s=a[j];a[j]=a[i];a[i]=s;
                    s=b[j];b[j]=b[i];b[i]=s;
                    strncpy(q,c[j],50);strncpy(c[j],c[i],50);strncpy(c[i],q,50);
                }
                if(j>=n)
                    break;
            }
        }
        if(k!=1)
            putchar('\n');
        printf("Case #%d\n",k);
        k++;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;a[j]==a[i]&&b[j]==b[i];j++)
            {
                if(strcmp(c[j],c[i])<0)
                {
                    strncpy(q,c[j],50);strncpy(c[j],c[i],50);strncpy(c[i],q,50);
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(i>0&&a[i]==a[i-1]&&b[i]==b[i-1])
                mc=mc;
            else
                mc=i+1;
            printf("%s %d\n",c[i],mc);
        }
    }
}
