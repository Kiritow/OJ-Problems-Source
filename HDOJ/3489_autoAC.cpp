# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;
int p[1002][26],pre[1002],n,m;
char a[10002],b[1002];
int f[10002][1002];
void relax(int &i,const int&j){if(i>j) i=j;}
int main()
{
 int Case; scanf("%d",&Case);
 while(Case--){
 scanf("%s",a+1); scanf("%s",b+1);
 n = strlen(a+1); m = strlen(b+1);
 for(int i=1; i<=n; i++)a[i]-='a',b[i]-='a';
 int k = 0; pre[1] = 0;
 for(int i=2; i<=m; i++) {
 while(k && b[k+1]!=b[i]) k = pre[k];
 if(b[k+1] == b[i]) k++; pre[i]=k;
 }
 memset(p,0,sizeof(p));
 for(int i=1; i<=m; i++) p[i-1][b[i]]=i;
 for(int i=1; i<=m; i++)
 for(int j=0; j<26; j++)
 if(!p[i][j]) p[i][j] = p[pre[i]][j];
 for(int j=0; j<26; j++) p[m][j] = m;
 memset(f,0x7f,sizeof(f)); f[0][0]=0;
 for(int i=0; i<n; i++)
 for(int j=0; j<m; j++)
 if( f[i][j]<0x7f7f7f7f )
 relax(f[i+1][j], f[i][j]+1),
 relax(f[i+1][p[j][a[i+1]]], f[i][j]);
 int ans = n+1;
 for(int i=0; i<m; i++) relax(ans, f[n][i]);
 printf("%d\n",ans);
 }
 return 0;
}
