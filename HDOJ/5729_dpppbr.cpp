//不初始化你给我死全家
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define MS(x,y) memset(x,y,sizeof(x)) 
#define MP(x,y) make_pair(x,y)
#define lowbit(x) (x&(-x))
typedef long long LL;
inline void fre1(){freopen("input.txt","r",stdin);/*freopen("output.txt","w",stdout);*/}
inline void fre2(){fclose(stdin);/*fclose(stdout);*/}
const int MAXN=30+5;
const double EPS=1e-8;
const int MOD=1e9+7;
LL fact[MAXN*MAXN],C[MAXN][MAXN],dp[MAXN][MAXN];

int main()
{
	int n=11;
	fact[0]=1;
	for(int i=1;i<=n*n;++i) fact[i]=fact[i-1]*3%MOD;
	C[0][0]=1;
	for(int i=1;i<MAXN;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	for(int i=1;i<=10;++i){
		for(int j=0;j<=10;++j){
			dp[i][j]=fact[i*j];
			if(i==1&&j==0) dp[i][j]=1;
			for(int ii=1;ii<=i;++ii){
				for(int jj=0;jj<=j;++jj){
					if(i==ii&&j==jj) continue;
					dp[i][j]-=C[i-1][ii-1]*C[j][jj]%MOD*dp[ii][jj]%MOD*fact[(i-ii)*(j-jj)]%MOD;
					dp[i][j]=(dp[i][j]%MOD+MOD)%MOD;
				}
			}
		}
	}
	int m;
	while(~scanf("%d%d",&n,&m)) printf("%I64d\n",dp[n][m]);
	return 0;
}
