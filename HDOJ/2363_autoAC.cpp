#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int n;
struct A
{
    int dis;
    int high;
    int flag;
    int hash;
}E[111];
int map[111][111];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int MIN(int a,int b)
{
    return a>b?b:a;
}
int DIJ()
{
    int i,k;
    k=1;
    while(k)
    {
        E[k].flag=0;
        for(i=1;i<=n;i++)
        {
            if(k==i || !E[i].hash)        continue;
            if(map[k][i]==1111111111)    continue;
            if(E[k].dis+map[k][i]<E[i].dis)    E[i].dis=E[k].dis+map[k][i];
        }
        k=0;
        for(i=1;i<=n;i++)    if(E[i].flag && E[i].hash)    {k=i;break;}
        for(;i<=n;i++)        if(E[i].flag && E[i].hash && E[i].dis<E[k].dis)    k=i;
    }
    return E[n].dis;
}
int main()
{
    int T;
    int m;
    int i,l,j;
    int temp[111];
    int a,b,c;
    int t,t1,t2;
    int ans,dir,len;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&E[i].high);
            temp[i-1]=E[i].high;
        }
        qsort(temp,n,sizeof(temp[0]),cmp);
        for(i=1;i<=n;i++)
        {
            for(l=1;l<=n;l++)    map[i][l]=1111111111;
            map[i][i]=0;
        }
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=map[b][a]=MIN(map[a][b],c);
        }
        t1=E[1].high;
        t2=E[n].high;
        if(t1>t2)    {t=t1;t1=t2;t2=t;}
        for(i=0;i<n;i++)    if(temp[i]==t1)    {a=i;break;}
        for(i=n-1;i>=0;i--)    if(temp[i]==t2)    {b=i;break;}
        dir=1111111111;
        len=1111111111;
        for(i=a;i>=0;i--)
        {
            for(l=b;l<n;l++)
            {
                if(abs(temp[i]-temp[l])>=dir)    continue;
                for(j=1;j<=n;j++)
                {
                    E[j].dis=1111111111;
                    E[j].flag=1;
                    if(temp[i]<=E[j].high && E[j].high<=temp[l])    E[j].hash=1;
                    else                                            E[j].hash=0;
                }
                E[1].dis=0;
                len=DIJ();
                if(len!=1111111111)
                {
                    if(abs(temp[i]-temp[l])<dir)
                    {
                        dir=abs(temp[i]-temp[l]);
                        ans=len;
                    }
                }
            }
        }
        printf("%d %d\n",dir,ans);
    }
    return 0;
}
