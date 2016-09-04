#include<iostream>
#include<queue>
#include<algorithm>
int MIN(int a,int b) { if( a<b )  return a;  else return b; }
int MAX(int a,int b) { if( a>b )  return a;  else return b; }
#define CLR(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME))
using namespace std;
const int N=100+10;
int c[N][N][N];
int GetSum(int x,int y,int z) {
 int yy,zz,sum=0;
 for(;x>0;x-=(-x)&x)
  for(yy=y;yy>0;yy-=(-yy)&yy)
   for(zz=z;zz>0;zz-=(-zz)&zz)
    sum=(sum+c[x][yy][zz])&1;
 return sum;
}
void Update(int x,int y,int z) {
 int yy,zz;
 for(;x<=N;x+=(-x)&x)
  for(yy=y;yy<=N;yy+=(-yy)&yy)
   for(zz=z;zz<=N;zz+=(-zz)&zz)
    c[x][yy][zz]^=1;
}
int main() {
  int n,m,q,x,y,z,x1,y1,z1,x2,y2,z2;
  while( scanf("%d%d",&n,&m)!=EOF ) {
   CLR(c,0);
   while( m-- ) {
    scanf("%d",&q);
    if( q==1 ) {
     scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
     Update(x1,y1,z1);
     Update(x1,y1,z2+1);
     Update(x1,y2+1,z1);
     Update(x1,y2+1,z2+1);
     Update(x2+1,y1,z1);
     Update(x2+1,y1,z2+1);
     Update(x2+1,y2+1,z1);
     Update(x2+1,y2+1,z2+1);
    }
    else {
     scanf("%d%d%d",&x,&y,&z);
     printf("%d\n",GetSum(x,y,z));
    }
   }
  }       
    return 0;
}
