#include<stdio.h>
int parent[1001],n;
void ynaiyxc()
{
    int i;
    for(i=0;i<=1000;i++)
        parent[i]=i;
}
int yxc(int x)
{
    if(x!=parent[x]) parent[x]=yxc(parent[x]);
    return parent[x];
}
int main()
{
    int m,num,a,b,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ynaiyxc();
        num=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            a=yxc(a);
            b=yxc(b);
            if(a==b)
            {
                num++;
            }
            else
            {
                parent[a]=b;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
