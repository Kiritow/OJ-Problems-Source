#include<stdio.h>
int a[10000002],dis[10000002],hsd[10000002];
int find(int x)
{
    if(dis[x]!=x)
        dis [x]=find(dis [x]);
    return dis[x];
}
int main()
{
    int n,i,j,max1;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            printf("1\n");
      else
        {
        for(j=1; j<=10000000; j++)
            {
                dis[j]=j;
                hsd[j]=1;
            }
            max1=0;
            for(i=1; i<=2*n; i=i+2)
            {   scanf("%d%d",&a[i],&a[i+1]);
                a[i]=find(a[i]);
                a[i+1]=find(a[i+1]);
                if(a[i]!=a[i+1])
                {
                    dis[a[i+1]]=a[i];
                    hsd[a[i]]=hsd[a[i]]+hsd[a[i+1]];
                    if(hsd[a[i]]>max1)
                    max1=hsd[a[i]];
                }
            }
            printf("%d\n",max1);
        }
    }
    return  0;
}
