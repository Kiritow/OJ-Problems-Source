#include<cstdio>
#include<cstring>
long long a[20][60];
int len[15];
long long dfs(int n,int k)
{
 if(n==0&&k!=0)
 return 0;
 if(k<0||n<0)
 return 0;
 if(n==0&&k==0)
 return 1;
 if(a[n][k])
 return a[n][k];
 for(int i=3; i<=10; i++)
 if(len[i])
 a[n][k]+=len[i]*dfs(n-1,k-i);
 return a[n][k];
}
int main()
{
 int t;
 scanf("%d",&t);
 while(t--)
 {
 int m,n,q;
 char c[20];
 scanf("%d%d%d",&m,&n,&q);
 memset(len,0,sizeof(len));
 for(int i=0; i<m; i++)
 {
 scanf("%s",c);
 len[strlen(c)]++;
 }
 for(int i=0; i<q; i++)
 {
 int k;
 scanf("%d",&k);
 memset(a,0,sizeof(a));
 printf("%I64d\n",dfs(n,k));
 }
 }
 return 0;
}
