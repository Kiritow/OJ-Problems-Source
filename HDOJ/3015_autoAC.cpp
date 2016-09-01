#include<iostream>
#include<algorithm>
using namespace std;
#define M 100005
struct node
{
    __int64 a,b;
    int num1,num2;
}t[M];
int cmpa(node &p,node &q)
{
    if(p.a<q.a)
        return 1;
    else
        return 0;
}
int cmpb(node &p,node &q)
{
    if(p.b<q.b)
        return 1;
    else
        return 0;
}
int cmpn(node &p,node &q)
{
    if(p.num2<q.num2)
        return 1;
    else
        return 0;
}
__int64 c[M],d[M],n;                  
int lowbit(int x)                      
{
    return x&(-x);
}
void updatac(int i,int j)
{
    while(i<=n)
    {
        c[i]+=j;
        i+=lowbit(i);
    }
}
void updatad(int i,int j)
{
    while(i<=n)
    {
        d[i]+=j;
        i+=lowbit(i);
    }
}
__int64 getsumc(int x)
{
    __int64 s=0;
    while(x>0)
    {
        s+=c[x];
        x-=lowbit(x);
    }
    return s;
}
__int64 getsumd(int x)
{
    __int64 s=0;
    while(x>0)
    {
        s+=d[x];
        x-=lowbit(x);
    }
    return s;
}
int main()
{
    while(scanf("%d",&n)>0)
    {
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        int i;
        for(i=1;i<=n;i++)
        {
            scanf("%I64d%I64d",&t[i].a,&t[i].b);
        }
        sort(t+1,t+1+n,cmpa);
        for(i=1;i<=n;i++)
        {
            if(i!=1&&t[i].a==t[i-1].a)
                t[i].num1=t[i-1].num1;
            else
                t[i].num1=i;
        }
        int max=t[n].num1;
        sort(t+1,t+1+n,cmpb);
        for(i=1;i<=n;i++)
        {
            if(i!=1&&t[i].b==t[i-1].b)
                t[i].num2=t[i-1].num2;
            else
                t[i].num2=i;
        }
        sort(t+1,t+1+n,cmpn);        
        for(i=1;i<=n;i++)               
        {
            updatac(t[i].num1,t[i].num1);
            updatad(t[i].num1,1);
        }
        __int64 sum=0,m=n,tmp1,tmp2;
        for(i=1;i<n;i++)
        {  
            tmp1=getsumd(t[i].num1-1)*t[i].num1-getsumc(t[i].num1-1);
            tmp2=(getsumd(max)-getsumd(t[i].num1))*t[i].num1-(getsumc(max)-getsumc(t[i].num1));
            sum+=(tmp1-tmp2)*t[i].num2;
            updatac(t[i].num1,-t[i].num1);
            updatad(t[i].num1,-1);
            m--;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
