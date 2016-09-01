#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
using namespace std;
vector<int> Org[30][30];
char Trs[90][5];
char st[60];
int f[60][60][30];
int Max2(int a,int b)
{
 return a>b?a:b;
}
int main()
{
 int N,i,j,k,t,L,Ans;
 for (;;)
 {
 scanf("%d",&N);
 if (N==0) break;
 for (i=0;i<='T'-'A';i++)
 for (j=0;j<='T'-'A';j++)
 Org[i][j].clear();
 for (i=0;i<N;i++)
 {
 scanf("%s",Trs[i]);
 Org[Trs[i][1]-'A'][Trs[i][2]-'A'].push_back(Trs[i][0]-'A');
 }
 scanf("%s",st);
 L=strlen(st);
 memset(f,-1,sizeof(f));
 f[0][0][st[0]-'A']=0;
 for (i=1;i<L;i++)
 {
 f[i][i][st[i]-'A']=0;
 if (Org[st[i-1]-'A'][st[i]-'A'].size()!=0)
 {
 for (j=0;j<Org[st[i-1]-'A'][st[i]-'A'].size();j++)
 f[i-1][i][Org[st[i-1]-'A'][st[i]-'A'][j]]=1;
 }
 }
 for (j=2;j<L;j++)
 for (i=0;i+j<L;i++)
 {
 for (t=0;t<N;t++)
 {
 for (k=i;k<i+j;k++)
 if (f[i][k][Trs[t][1]-'A']!=-1 && f[k+1][i+j][Trs[t][2]-'A']!=-1 && (f[i][i+j][Trs[t][0]-'A']==-1 || f[i][i+j][Trs[t][0]-'A']>Max2(f[k+1][i+j][Trs[t][2]-'A'],f[i][k][Trs[t][1]-'A'])+1))
 f[i][i+j][Trs[t][0]-'A']=Max2(f[k+1][i+j][Trs[t][2]-'A'],f[i][k][Trs[t][1]-'A'])+1;
 }
 }
 Ans=-1;
 for (i=0;i<='T'-'A';i++)
 if (Ans==-1 || (f[0][L-1][i]!=-1 && Ans>f[0][L-1][i]))
 Ans=f[0][L-1][i];
 printf("%d\n",Ans);
 }
}
