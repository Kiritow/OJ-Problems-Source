#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=110;
char s[maxn][maxn];
int visit[maxn];
int n;
int len[maxn];
int ans[maxn];
int en[maxn],fa[maxn];
int solve(int dep,int num)
{
 if (en[dep]!=0) return en[dep]-1;
 visit[dep]=num;
 for(int i=0;i<len[dep];i++)
 {
 ans[dep]=i;
 int t=s[dep][i]-'a';
 if (visit[t])
 {
 int maxs=0;
 int counts=0;
 for(int j=0;j<n;j++)
 if (visit[j]>=visit[t])
 {
 if (ans[j]>0) return 1;
 if (len[j]>maxs) maxs=len[j];
 counts++;
 }
 if (counts>1) return 2;
 if (maxs>1) return 1;
 return 0;
 }
 int now=solve(t,num+1);
 if (now==0) continue;
 return now;
 }
 visit[dep]=0;
 return 0;
}
int find_fa(int u)
{
 if (fa[u]!=u) fa[u]=find_fa(fa[u]);
 return fa[u];
}
int main()
{
 int cas;
 scanf("%d",&cas);
 while(cas--)
 {
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 {
 scanf("%s",s[i]);
 len[i]=strlen(s[i]);
 }
 memset(en,0,sizeof(en));
 for(int i=0;i<n;i++) fa[i]=i;
 for(int i=0;i<n;i++)
 {
 int have=0;
 for(int j=0;j<n;j++)
 {
 if (en[j]!=0) continue;
 bool flag=1;
 for(int k=1;k<len[j];k++)
 if (find_fa(s[j][0]-'a')!=find_fa(s[j][k]-'a')) flag=0;
 if (flag)
 {
 int t1=find_fa(j);
 int t2=find_fa(s[j][0]-'a');
 if (t1!=t2)
 {
 if (en[t2]==0) continue;
 if (len[t2]==1) en[t1]=1;
 else en[t1]=2;
 fa[t1]=t2;
 have++;
 } else
 {
 if (len[t2]==1) en[t1]=1;
 else en[t1]=2;
 have++;
 }
 }
 }
 if (have==0) break;
 }
 memset(visit,0,sizeof(visit));
 memset(ans,-1,sizeof(ans));
 int ans=solve(0,1);
 if (ans==2) puts("NO");
 else puts("YES");
 }
}
