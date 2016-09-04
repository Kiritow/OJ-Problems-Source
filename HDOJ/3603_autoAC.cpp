#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 300001
#define eps 1e-6
using namespace std;
int n;
int m;
int len[maxn];
int vis[maxn];
int mx[maxn][24];
int pre[maxn];
int search(int l,int r)
{
 int t=l;
 while(l<r)
 {
 int mid=l+r>>1;
 if(pre[mid]<t)
 {
 l=mid+1;
 }
 else
 {
 r=mid;
 }
 }
 return l;
}
void init_rmq()
{
 int i,j;
 int k=(int)(log2(n)+eps);
 for(i=1; i<=n; i++)
 {
 mx[i][0]=len[i];
 }
 for(i=1; i<=k; i++)
 {
 for(j=1; j<=n; j++)
 {
 mx[j][i]=mx[j][i-1];
 if(j+(1<<(i-1))<=n)
 {
 mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
 }
 }
 }
}
int rmq(int l,int r)
{
 int k=(int)(log2(r-l+1)+eps);
 return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int main()
{
 int i,j;
 while(scanf("%d",&n)!=EOF)
 {
 memset(len,0,sizeof(len));
 memset(vis,-1,sizeof(vis));
 memset(pre,-1,sizeof(pre));
 for(i=1; i<=n; i++)
 {
 int temp;
 scanf("%d",&temp);
 if(vis[temp]==-1)
 {
 pre[i]=1;
 }
 else
 {
 pre[i]=vis[temp]+1;
 }
 pre[i]=max(pre[i],pre[i-1]);
 len[i]=i-pre[i]+1;
 vis[temp]=i;
 }
 init_rmq();
 scanf("%d",&m);
 while(m--)
 {
 int l,r;
 scanf("%d %d",&l,&r);
 if(l>r) swap(l,r);
 int t=search(l,r);
 if(t==r)
 {
 printf("%d\n",t-l+1);
 }
 else
 {
 printf("%d\n",max(t-l,rmq(t,r)));
 }
 }
 }
 return 0;
}
