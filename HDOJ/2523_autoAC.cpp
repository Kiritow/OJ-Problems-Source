#include<stdio.h>
int abs(int a)
{
    return a<0 ? -a:a;
}
void main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,j;
        scanf("%d %d",&n,&k);
        int x[2001]={0};
        int inf[1000];
        for(i=0;i<n;i++)
        {
            scanf("%d",&inf[i]);
            for(j=0;j<i;j++)
                x[abs(inf[j]-inf[i])]=1;
        }
        for(i=0;k;i++)
        {
            if(x[i]==1)
                k--;
        }
        printf("%d\n",i-1);
    }
}
