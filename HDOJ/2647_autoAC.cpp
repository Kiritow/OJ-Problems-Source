#include<stdio.h>
#include<string.h>
struct A
{
    int ts;
    int outdegree;
    int total;
    int mem[15];
}E[10011];
int max(int a,int b)
{
    return a>b?a:b;
}
int topsort(int n)
{
    int k,i,j;
    int flag;
    int temp;
    k=0;
    while(k<n)
    {
        flag=0;
        for(i=1;i<=n;i++)
        {
            if(E[i].outdegree==0)
            {
                E[i].outdegree--;
                temp=E[i].ts+1;
                for(j=0;j<E[i].total;j++)
                {
                    E[E[i].mem[j]].outdegree--;
                    E[E[i].mem[j]].ts=max(temp,E[E[i].mem[j]].ts);
                }
                flag=1;
                k++;
            }
        }
        if(flag==0)    return 1;
    }
    return 0;
}
int main()
{
    int n,m;
    int i;
    int a,b;
    int flag;
    int ans;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(i=1;i<=n;i++)    E[i].ts=E[i].total=E[i].outdegree=0;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            E[a].outdegree++;
            E[b].mem[E[b].total++]=a;
        }
        flag=topsort(n);
        if(flag)    {printf("-1\n");continue;}
        ans=0;
        for(i=1;i<=n;i++)    ans+=E[i].ts;
        ans+=888*n;
        printf("%d\n",ans);
    }
    return 0;
}
