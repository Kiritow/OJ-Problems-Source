#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c[1005];
long long ans[405],tot[405],g[405];
void chenggao(long long a[],long long b[])
{    int i,j;
    memset(g,0,sizeof(g));
    g[0]=a[0]+b[0];
    for(i=1;i<=a[0];i++)
        for(j=1;j<=b[0];j++)
            g[i+j-1]+=a[i]*b[j];
    for(i=1;i<=g[0];i++)
        {    g[i+1]+=g[i]/10000;
            g[i]=g[i]%10000;
        }        
    while(g[g[0]]==0&&g[0]>0)g[0]--;
    for(i=0;i<=g[0];i++)
        a[i]=g[i];        
}
void jia(long long a[],long long b[])
{    int i;
    a[0]=max(a[0],b[0]);
    for(i=1;i<=a[0];i++)
        a[i]=a[i]+b[i];
    for(i=1;i<=a[0];i++)
        {    a[i+1]+=a[i]/10000;
            a[i]=a[i]%10000;
        }    
    while(a[a[0]+1]!=0)
        {    a[0]++;
            a[a[0]+1]=a[a[0]]/10000;
            a[a[0]]=a[a[0]]%10000;
        }    
}
void chudan(long long a[],int x)
{    long long d=0;
    int i;
    for(i=a[0];i>=1;i--)
        {    d=d*10000+a[i];
            a[i]=d/x;
            d=d%x;
        }
    while(a[a[0]]==0&&a[0]>0)a[0]--;
}
void chengdan(long long a[],int x)
{    int i;
    for(i=1;i<=a[0];i++)
        a[i]=a[i]*x;
    for(i=1;i<=a[0];i++)
        {    a[i+1]+=a[i]/10000;
            a[i]=a[i]%10000;
        }    
    while(a[a[0]+1]!=0)
        {    a[0]++;
            a[a[0]+1]=a[a[0]]/10000;
            a[a[0]]=a[a[0]]%10000;
        }    
}
void print(long long a[])
{    int i;
    printf("%lld",a[a[0]]);
    for(i=a[0]-1;i>=1;i--)
        {    printf("%lld",a[i]/1000);
            printf("%lld",a[i]/100%10);
            printf("%lld",a[i]/10%10);
            printf("%lld",a[i]%10);
        }
    printf("\n");    
}
void Mulpow(int x,int tmp)
{    int i;
    memset(tot,0,sizeof(tot));
    c[0]=0;
    while(tmp>0)
        {    c[0]++;
            c[c[0]]=tmp%2;
            tmp=tmp/2;
        }
    tot[0]=1;
    tot[1]=x;
    for(i=c[0]-1;i>=1;i--)
        {    chenggao(tot,tot);
            if(c[i]==1)
                chengdan(tot,x);
        }    
}
int main()
{
    int p,x,y,i,tmp,N;
    while(scanf("%d%d",&n,&p)!=EOF)
        {    N=n*n;
            memset(ans,0,sizeof(ans));
            if(n==1)
                {    printf("%d\n",p);
                    continue;
                }
            if(n%2==0)
                {    Mulpow(p,N);//0
                    jia(ans,tot);
                    Mulpow(p,N/4);//90
                    jia(ans,tot);
                    Mulpow(p,N/2);//180
                    jia(ans,tot);
                    Mulpow(p,N/4);//270
                    jia(ans,tot);
                    Mulpow(p,N/2);
                    jia(ans,tot);
                    Mulpow(p,N/2);
                    jia(ans,tot);
                    Mulpow(p,n+(N-n)/2);
                    jia(ans,tot);
                    Mulpow(p,n+(N-n)/2);
                    jia(ans,tot);
                    y=8;
                }    
            else
                {    Mulpow(p,N);//0
                    jia(ans,tot);
                    Mulpow(p,1+(N-1)/4);//90
                    jia(ans,tot);
                    Mulpow(p,1+(N-1)/2);//180
                    jia(ans,tot);
                    Mulpow(p,1+(N-1)/4);//270
                    jia(ans,tot);
                    Mulpow(p,n+(N-n)/2);
                    jia(ans,tot);
                    Mulpow(p,n+(N-n)/2);
                    jia(ans,tot);
                    Mulpow(p,n+(N-n)/2);
                    jia(ans,tot);
                    Mulpow(p,n+(N-n)/2);
                    jia(ans,tot);
                    y=8;
                }    
            chudan(ans,y);    
            print(ans);    
        }
    return 0;
}
