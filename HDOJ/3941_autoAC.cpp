#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
const int MOD=1000000007;
const int MaxN=103;
const int MaxM=203;
int N,K,f[2][MaxN][MaxM],s[MaxN][MaxM];
int solve()
{
 int MaxK=2*K+1;
 for (int i=0; i<=K; ++i)
     for (int j=0; j<=MaxK; ++j) f[0][i][j]=s[i][j]=0;
 f[0][0][0]=1;
 s[0][0]=1;
 int cur=0,last;
 for (int i=1; i<=N; ++i)
 {
 last=cur;
 cur=1-cur;
 for (int j=0; j<=K; ++j)
     for (int k=0; k<=MaxK; ++k) f[cur][j][k]=0;
 f[cur][0][0]=1;
 for (int j=1; j<=K; ++j)
 {
     for (int k=j; k<MaxK-1; ++k)
     {
         f[cur][j][k]=f[cur][j-1][k-1]+f[last][j][k-j];
         f[cur][j][k]%=MOD;
     }
     for (int p=0; p<=j; ++p)
     {
      int cnt=MaxK-1-j;
      f[cur][j][MaxK-1]+=s[p][cnt];
      f[cur][j][MaxK-1]%=MOD;
      cnt=MaxK-j;
      f[cur][j][MaxK]+=s[p][cnt];
      f[cur][j][MaxK]%=MOD;
     }
 }
 for (int j=0; j<=K; ++j)
     for (int k=MaxK; k>=0; --k) s[j][k]=f[cur][j][k];
 for (int j=0; j<=K; ++j)
     for (int k=MaxK-2; k>=0; --k)
     {
         s[j][k]+=s[j][k+2];
         s[j][k]%=MOD;
            } 
 }
 int ans=0;
 for (int i=0; i<=K; ++i)
     for (int j=i+i; j<MaxK; j+=2) 
     {
      ans+=f[cur][i][j];
      ans%=MOD;
     }
 return ans;
}
int main()
{
 int Testnum;
 scanf("%d",&Testnum);
 for (int Test=1; Test<=Testnum; ++Test)
 {
 scanf("%d %d",&N,&K);
 printf("Case #%d: %d\n",Test,solve());
    }
}
