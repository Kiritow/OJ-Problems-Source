#include <iostream>
#include <cmath>
using namespace std;
const int maxp=44;
int p[maxp];
int pp;
void sai()
{
int i,j;
pp=0;
for (i=2;i<3010;i++)
{
   for (j=2;j*j<=i;j++)
    if (i%j==0) break;
   if (j*j>i) p[pp++]=i;
   if (pp>=maxp) break;
}
}
int res[maxp],a[maxp];
int n,m;
double ber[3010][maxp]={0};
double fres;
void dfs(int k,double mut,int s)
{
if (ber[n-s][k]>mut+0.01) return ;
else if (mut>ber[n-s][k]) ber[n-s][k]=mut;
int i=p[k];
if (k>=pp||p[k]>s) 
{
   if (mut>fres)
   {
    memcpy(res,a,sizeof(a));
    fres=mut;
   }
   return ;
}
dfs(k+1,mut,s);
for (a[k]=1;i<=s;a[k]++)
{
   mut=mut+log(p[k]);
   dfs(k+1,mut,s-i);
   i*=p[k];
}
a[k]=0;
}
void oot()
{
int i,j,k;
k=1;
for (i=0;i<maxp;i++)
   for (j=0;j<res[i];j++)
    k=k*p[i]%m;
printf("%d\n",k%m);
}
int main()
{
sai();
while (scanf("%d%d",&n,&m)!=EOF)
{
   memset(ber,0,sizeof(ber));
   memset(a,0,sizeof(a));
   fres=-1;
   dfs(0,0,n);
   oot();
}
return 0;
}
