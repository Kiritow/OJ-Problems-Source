#include<stdio.h>
#include<string.h>
int a,b,c;
int ans;
int hash[10];
int base[11],limit;
int t_a;
int t_b;
void judge()
{
    int i;
    int t;
    int temp[10];
    t=t_a*t_b;
    if(limit<=t || t<base[c])    return ;
    memset(temp,0,sizeof(temp));
    while(t)
    {
        if(hash[t%10])    return ;
        temp[t%10]=1;
        t/=10;
    }
    t=0;
    for(i=1;i<10;i++)    if(temp[i])    t++;
    if(t!=c)    return ;
    ans++;
}
void DFS2(int k)
{
    int i;
    if(k>=base[b+1])    return ;
    if(base[b]<=k)        {t_b=k;judge();return ;}
    for(i=1;i<10;i++)
    {
        if(hash[i]==0)
        {
            hash[i]=1;
            DFS2(k*10+i);
            hash[i]=0;
        }
    }
}
void DFS(int k)
{
    int i;
    if(k>=base[a+1])    return; 
    if(base[a]<=k)
    {
        t_a=k;
        DFS2(0);
        return ;
    }
    for(i=1;i<10;i++)
    {
        if(hash[i]==0)
        {
            hash[i]=1;
            DFS(k*10+i);
            hash[i]=0;
        }
    }
}
int main()
{
    int i;
    while(scanf("%d%d%d",&a,&b,&c),a||b||c)
    {
        if(a==0 || b==0 || c==0)    {printf("0\n");continue;}
        if(a+b-2>c)                    {printf("0\n");continue;}
        base[1]=1;
        for(i=2;i<=10;i++)    base[i]=base[i-1]*10;
        limit=base[c+1];
        ans=0;
        memset(hash,0,sizeof(hash));
        DFS(0);
        printf("%d\n",ans);
    }
    return 0;
}
