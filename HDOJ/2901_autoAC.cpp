#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int maxN=305;
const int maxM=35;
typedef double db;
const db eps=1e-12;
db dp[maxN][maxM];
int pre[maxN][maxM];
db cur[maxM][maxM];
db Prev[maxM][maxM];
int shot[500],N;
int inv[maxM];
int main()
{
 int T;scanf("%d",&T);
 while(T--)
 {
 scanf("%d",&N);
 memset(shot,-1,sizeof(shot));
 for(int i=0;i<N;++i)
 {
 char a[2];scanf("%s",a);
 shot[a[0]]=i;
 inv[i]=a[0];
 }
 for(int i=0;i<N;++i)
 for(int j=0;j<N;++j){
 scanf("%lf",&cur[i][j]);
 cur[i][j]=log(cur[i][j]);
 }
 for(int i=0;i<N;++i)
 for(int j=0;j<N;++j) {
 scanf("%lf",&Prev[i][j]);
 Prev[i][j]=log(Prev[i][j]);
 }
 int M;scanf("%d",&M);
 while(M--)
 {
 char ss[500];scanf("%s",ss);
 int l=strlen(ss);
 for(int i=0;i<=l;++i)
 for(int j=0;j<N;++j)
 dp[i][j]=-1e200,pre[i][j]=-1;
 dp[0][0]=0;
 for(int i=0;i<l;++i)
 {
 int hj=shot[ss[i]];
 for(int j=0;j<N;++j)
 {
 for(int k=0;k<N;++k)
 {
 db tmp=dp[i][j]+cur[k][hj];
 if(i!=0) tmp=tmp+Prev[j][k];
 if(tmp>dp[i+1][k])
 {
 pre[i+1][k]=j;
 dp[i+1][k]=tmp;
 }
 }
 }
 }
 db maxx=-1e200;
 int idx=-1;
 for(int i=0;i<N;++i)
 {
 if(dp[l][i]>maxx)
 {
 maxx=dp[l][i];
 idx=i;
 }
 }
 int ans[500];
 int mm=l;
 while(mm)
 {
 ans[mm]=idx;
 idx=pre[mm][idx];
 mm--;
 }
 for(int i=1;i<=l;++i)
 printf("%c",inv[ans[i]]);
 printf("\n");
 }
 }
}
