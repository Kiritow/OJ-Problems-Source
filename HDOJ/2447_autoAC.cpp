#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
const int maxn=500000;
const int mod=100000000;
int prime[maxn];
int flag[maxn];
int px[10006];
int n,K,mark;
struct bign
{
 __int64 val[1000];
 int len;
 bign(){memset(val,0,sizeof(val));len=1;}
};
bign a,b,c,d,dd,e;
int get_pri()
{
 int i,j,k;
 k=0;
 memset(flag,0,sizeof(flag));
 flag[0]=flag[1]=1;
 for(i=2;i<maxn;i++)
 {
 if(!flag[i])prime[k++]=i;
 for(j=0;j<k&&prime[j]*i<maxn;j++)
 {
 flag[prime[j]*i]=1;
 if(i%prime[j]==0)break;
 }
 }
 return k;
 }
 void Init(bign &cc,int t)
 {
 int j=0;
 while(t)
 {
 cc.val[j++]=t%mod;
 t/=mod;
 }
 cc.len=j;
 return ;
 }
 void multify(bign &aa,bign &bb)
 {
 int i,j;
 memset(dd.val,0,sizeof(dd.val));
 dd.len =1;
 for(i=0;i<aa.len;i++)
 for(j=0;j<bb.len;j++)
 {
 dd.val[i+j]+=aa.val[i]*bb.val[j];
 dd.val[i+j+1]+=dd.val[i+j]/mod;
 dd.val[i+j]%=mod;
 }
 dd.len=aa.len+bb.len;
 if(dd.val[dd.len-1]==0)dd.len--;
 aa=dd;
 return ;
 }
 void power(bign &temp,bign &x,int y)
 {
 temp.len=1;
 temp.val[0]=1;
 while(y)
 {
 if(y&1)multify(temp,x);
 multify(x,x);
 y>>=1;
 }
 return ;
 }
 void cal_xx()
 {
 int i,j,k=0,t;
 for(i=4;i<=100000;i++)
 { 
 t=i;
 for(j=0;prime[j]*prime[j]<t;j++)
 {
 if(t%prime[j])continue;
 t=t/prime[j];
 if(!flag[t])
 px[k++]=i;
 else break;
 if(k==10000)break;
 }
 if(k==10000)break;
 }
}
int cmp(bign &x,bign &y)
{
 if(x.len>y.len)return 1;
 if(x.len<y.len)return -1;
 int i;
 for(i=x.len-1;i>=0;i--)
 {
 if(x.val[i]>y.val[i])
 return 1;
 if(x.val[i]<y.val[i])
 return -1;
 }
 return 0;
}
void solve( bign &t)
{
 int i=0,j=0,k;
 int f1=0,f2=0;
 for(k=0;k<n;k++)
 { 
 if(!f1)
 {
 Init(a,px[i]);
 }
 if(!f2)
 {
 Init(d,prime[j]);
 power(b,d,mark+1);
 }
 if(cmp(a,b)==1)
 { 
 if(k==n-1)e=b;
 f1=1;f2=0; j++;
 }
 else 
 {
 if(k==n-1)e=a; 
 f1=0;f2=1;i++;
 }
 }
 power(t,e,mark-1);
}
void output(bign &x)
{
 int i=x.len;
 printf("%d",x.val[--i]);
 while(i)
 {
 printf("%08d",x.val[--i]);
 }
 printf("\n");
}
int main()
{ 
 get_pri();
 cal_xx();
 while(EOF!=scanf("%d%d",&n,&K))
 {
 if(K==1){printf("1\n");continue;}
 mark=0;
 if(flag[K]){mark=(int)sqrt(K*1.0);}
 if(!mark)
 { 
 Init(d,prime[n-1]);
 power(c,d,K-1);
 output(c);
 }
 else
 { 
 solve(c);
 output(c);
 } 
 }
 return 0;
}
