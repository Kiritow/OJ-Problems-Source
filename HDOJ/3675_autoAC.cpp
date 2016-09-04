#include <stdio.h>
#include <string.h>
const int Mod=9973;
int cnt[2],box[2][Mod],now,pre;
struct edge{
 int to,next,num;
} e[2][120000];
void add(int u,int num)
{
 int idx=u%Mod;
 for(int p=box[pre][idx];p!=-1;p=e[pre][p].next)
 if (e[pre][p].to==u)
 {
 if (e[pre][p].num>num) e[pre][p].num=num;
 return ;
 }
 e[pre][cnt[pre]].to=u;e[pre][cnt[pre]].num=num;
 e[pre][cnt[pre]].next=box[pre][idx];box[pre][idx]=cnt[pre]++;
}
int a[100][20];
int b[20];
int base[20];
bool ok1(int i,int j)
{
 return (a[i][j]>a[i][j-1]&&a[i][j-1]>a[i][j-2])||
 (a[i][j]<a[i][j-1]&&a[i][j-1]<a[i][j-2]);
}
bool ok2(int i,int j)
{
 return (a[i][j]>a[i-1][j]&&a[i-1][j]>a[i-2][j])||
 (a[i][j]<a[i-1][j]&&a[i-1][j]<a[i-2][j]);
}
int main()
{
 int n,m;
 int T=0;
 base[0]=1;
 for(int i=1;i<=10;i++) base[i]=base[i-1]<<2;
 while(scanf("%d %d",&n,&m)==2)
 {
 if (n==0&&m==0) break;
 memset(box[0],-1,sizeof(box[0]));
 cnt[0]=0;
 now=1;pre=0;
 add(0,0);
 now=0;pre=1;
 for(int i=0;i<n;i++)
 for(int j=0;j<m;j++)
 {
 scanf("%d",&a[i][j]);
 memset(box[pre],-1,sizeof(box[pre]));
 cnt[pre]=0;
 for(int p=0;p<cnt[now];p++)
 {
 int v=e[now][p].to;
 int tmp=v;
 int num=e[now][p].num;
 int k=0;
 while(v)
 {
 b[k++]=v&3;
 v>>=2;
 }
 while(k<=m) b[k++]=0;
 tmp-=b[j+1]*base[j+1]+b[0];
 if (i==0) b[j+1]=0;
 if (j==0) b[0]=0;
 if (a[i][j]<=0)
 {
 add(tmp,num);
 continue;
 }
 if (b[0]==0) add(tmp+1,num+1); else
 if (b[0]==1&&a[i][j]!=a[i][j-1]) add(tmp+2,num) ; else
 if (ok1(i,j)) add(tmp+2,num); else
 add(tmp+1,num+1);
 if (b[j+1]==0) add(tmp+base[j+1],num+1); else
 if (b[j+1]==1&&a[i][j]!=a[i-1][j]) add(tmp+2*base[j+1],num); else
 if (ok2(i,j)) add(tmp+2*base[j+1],num); else
 add(tmp+base[j+1],num+1);
 }
 now^=1;pre^=1;
 }
 int ans=n*m;
 for(int i=0;i<cnt[now];i++)
 if (ans>e[now][i].num) ans=e[now][i].num;
 printf("Case %d: %d\n",++T,ans);
 }
 return 0;
}
