#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 1000+100
using namespace std;
int f[MAXN][12][12];
int times[12][12];
int n,m;
char s[MAXN],t[MAXN];
int a[MAXN],b[MAXN];
int min(int a,int b){return (a<b)?a:b;}
int main()
{
    for (int i=0;i<10;++i){
        int j=1;
        while ((i+j)%10!=i) {
              times[i][(i+j)%10]=j;
              j++;
        }
    }
    while (scanf("%s%s",s,t)!=EOF)
    {
          n=strlen(s);
          for (int i=0;i<=n;++i)
              for (int j=0;j<=10;++j)
              for (int k=0;k<=10;++k) f[i][j][k]=n*10;
          int ans=n*10;    
          for (int i=0;i<n;++i) 
          {
              a[i+1]=s[i]-'0';
              b[i+1]=t[i]-'0';
          }
          f[0][a[1]][a[2]]=0;
          for (int i=0;i<n;++i)
          for (int j=0;j<10;++j)
          for (int k=0;k<10;++k)
          if (f[i][j][k]<10*n)
          {
              int t=times[j][b[i+1]];               
              for (int l=0;l<=t;++l)
                  for(int p=0;p<=l;++p){
                  f[i+1][(k+l)%10][(a[i+3]+p)%10]=
                  min(f[i+1][(k+l)%10][(a[i+3]+p)%10],f[i][j][k]+t); 
              }
              for (int l=0;l<=10-t;++l)
                  for(int p=0;p<=l;++p){
                  f[i+1][(k-l+10)%10][(a[i+3]-p+10)%10]=
                  min(f[i+1][(k-l+10)%10][(a[i+3]-p+10)%10],f[i][j][k]+10-t);
              }
          }
          for (int i=0;i<10;++i)
              for (int j=0;j<10;++j)
              if(f[n][i][j]<ans) ans=f[n][i][j];
          cout << ans << endl;
    }
    return 0;
}
