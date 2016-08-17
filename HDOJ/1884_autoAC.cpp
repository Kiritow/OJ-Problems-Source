#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#define ll long long
#define mod 1000000007ll
#define N 100009
#define inf 1000000000ll;
using namespace std;
typedef pair<int,int> II;
int dx[]={0,0,-1,-1,1,1},
 dy[]={-1,1,0,-1,0,1};
int n;
char s[100][100];
int d[100][100][1<<4],in[100][100][1<<4];
queue<int> Q;
int get(char c){
 if(c=='.') return 0;
 return 1<<(c-'A');
}
void update(int x,int y,int z,int v){
 if(d[x][y][z]==-1||d[x][y][z]>v){
 d[x][y][z]=v; 
 if(!in[x][y][z]) in[x][y][z]=1,Q.push(x*1600+y*16+z);
 }
}
int main(){
 while(scanf("%d",&n),n)
 {
 memset(s,0,sizeof(s));
 memset(d,-1,sizeof(d));
 memset(in,0,sizeof(in));
 while(!Q.empty()) Q.pop();
 char c;
 for(int i=1;i<=n;i++)
 for(int j=1;j<n+i;j++){
 while(!isalpha(c=getchar())&&c!='.');
 s[i][j]=c;
 } 
 for(int i=2;i<=n;i++)
 for(int j=1;j<=2*n-i;j++){
 while(!isalpha(c=getchar())&&c!='.');
 s[n+i-1][i+j-1]=c;
 } 
 n=2*n-1;
 for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
 if(isalpha(s[i][j]))
 update(i,j,get(s[i][j]),0);
 int x,y,z,tx,ty,tz;
 while(!Q.empty()){
 x=Q.front()/1600;
 y=(Q.front()%1600)/16;
 z=Q.front()%16;
 in[x][y][z]=0;
 Q.pop();
 for(int i=0;i<6;i++){
 tx=x+dx[i];
 ty=y+dy[i];
 if(!s[tx][ty]) continue;
 tz=z|get(s[tx][ty]);
 update(tx,ty,tz,d[x][y][z]+(s[tx][ty]=='.'));
 }
 int t=15-z;
 for(int i=t;i;i=(i-1)&t)
 if(d[x][y][i]!=-1)
 update(x,y,z|i,d[x][y][i]+d[x][y][z]-(s[x][y]=='.'));
 }
 int ans=n*n;
 for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
 if(s[i][j]&&d[i][j][15]!=-1)
 ans=min(ans,d[i][j][15]);
 printf("You have to buy %d parcels.\n",ans);
 }
}
