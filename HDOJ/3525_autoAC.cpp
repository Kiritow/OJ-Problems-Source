#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=20001,maxm=maxn*100;
inline int Max(int a,int b){return a>b?a:b;}
int a[maxm],b[maxm];
int f[maxn][20],ff[maxn];
int ne[maxm];
int tree[maxm];
int lowbit(int t)
{
return t&-t;
}
int ask(int k)
{
int res=0;
while (k)
{
   res=Max(res,tree[k]);
   k-=lowbit(k);
}
return res;
}
void change(int k,int d,int n)
{
while (k<=n)
{
   tree[k]=Max(tree[k],d);
   k+=lowbit(k);
}
}
int n,m;
char buf[2048576],*o;
int getint() {
while (!isdigit(*o)) o++;
int f = 0;
while (isdigit(*o)) f=f*10+*o-'0',o++;
return f;
}
void iin()
{
int i,j,k,col,pos;
scanf("%d%d\n",&n,&m);
for (i=0;i<=n*m*2+10;i++) 
{
   ne[i]=i+1;
   a[i]=0;
}
for (i=0;i<n*m;i++)
{
   scanf("%d%d",&col,&pos);
   k=pos;
   while (a[k]!=0) k=ne[k];
   a[k]=col;
   j=k;
   k=pos;
   while (k!=j)
   {
    int kk=ne[k];
    ne[k]=ne[j];
    k=kk;
   }
}
k=i=1;
while (k<=n*m)
{
   while (a[i]==0) i++;
   a[k++]=a[i++];
}
for (i=0;i<=n*m*2+10;i++) 
{
   ne[i]=i+1;
   b[i]=0;
}
for (i=0;i<n*m;i++)
{
   scanf("%d%d",&col,&pos);
   k=pos;
   while (b[k]!=0) k=ne[k];
   b[k]=col;
   j=k;
   k=pos;
   while (k!=j)
   {
    int kk=ne[k];
    ne[k]=ne[j];
    k=kk;
   }
}
k=i=1;
while (k<=n*m)
{
   while (b[i]==0) i++;
   b[k++]=b[i++];
}
for (i=1;i<=n;i++) ff[i]=0;
for (i=1;i<=n*m;i++)
   f[b[i]][ff[b[i]]++]=i;
}
void dp()
{
memset(tree,0,sizeof(tree));
int i,j,k;
int maxres=0;
for (i=1;i<=n*m;i++)
   for (j=m-1;j>=0;j--)
   {
    k=f[a[i]][j];
    int t=ask(k-1)+1;
    maxres=Max(maxres,t);
    change(k,t,n*m);
   }
printf("%d\n",maxres);
}
int main()
{
int cass,cas=0;
for (scanf("%d\n",&cass);cass--;)
{
   iin();
   cas++;
   printf("Case #%d: ",cas);
   dp();
}
return 0;
}
