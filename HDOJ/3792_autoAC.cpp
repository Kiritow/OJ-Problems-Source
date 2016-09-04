#include<stdio.h>
#include<math.h>
#include<string.h>
int vis[100000+100];
int prime[80000],c;
int a[100000+10];
void get_prime()
{
    int i,j,n,m;
    c=0;
    n=100000;
    m=(int)sqrt(n+0.5);
    memset(vis,0,sizeof(vis));
    for(i=2;i<=m;i++) if(!vis[i])
    {
        for(j=i*i;j<=n;j+=i) vis[j]=1;
    }
}
int main()
{
    int  i,j,n,max;
    get_prime();
    n=0;
    a[1]=0;a[0]=0;a[2]=0;a[3]=0;a[4]=0;
    for(i=4;i<=100000;i++)
    {
         if(!vis[i]&&!vis[i-2])
         {
             n++;
         }
         a[i]=n;
    }
    while(i<=100000)
    {
        a[i++]=n;
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0) break;
        printf("%d\n",a[n]);
    }
    return 0;
}
