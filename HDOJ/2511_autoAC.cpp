#include<cstdio>
#define maxn 63
using namespace std;
long long f[maxn+10];
void dfs(int s,int z,int e,long long n,long long m)
{
if(m==f[n-1]+1){printf("%I64d %d %d\n",n,s,e);return;}
if(m>f[n-1])dfs(z,s,e,n-1,m-f[n-1]-1);
if(m<=f[n-1])dfs(s,e,z,n-1,m);
}
void work()
{
int t,i,j,k; long long n,m;
for(f[0]=0,i=1;i<=maxn;i++)f[i]=f[i-1]*2+1;
while(scanf("%d",&t)==1)
for(i=1;i<=t;i++)
{
scanf("%I64d%I64d",&n,&m);
dfs(1,2,3,n,m);
}
}
int main()
{
work();
return 0;
}
