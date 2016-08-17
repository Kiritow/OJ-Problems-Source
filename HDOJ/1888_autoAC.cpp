#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <map>
#include <stack>
using namespace std;
const int M=1200;
char dd[10]="WNES";
int rr[M];
int cnt;
int n;
struct Point
{
 int x,y;
 bool operator<(const Point &ret)const
 {
 if(x!=ret.x)
 return x<ret.x;
 return y<ret.y;
 }
}point[1200];
stack <int> re;
bool check(int i,int x,int y)
{
 int sum=0;
 if(i==0)
 {
 for(int j=1;j<=n;j++)
 {
 if(point[j].y==y&&point[j].x<x)
 sum++;
 }
 }
 else if(i==1)
 {
 for(int j=1;j<=n;j++)
 if(point[j].x==x&&point[j].y>y)
 {
 sum++;
 }
 }
 else if(i==2)
 {
 for(int j=1;j<=n;j++)
 {
 if(point[j].y==y&&point[j].x>x)
 {
 sum++;
 }
 }
 }
 else
 {
 for(int j=1;j<=n;j++)
 if(point[j].x==x&&point[j].y<y)
 {
 sum++;
 }
 }
 if(sum%2==1)
 return true;
 return false;
}
bool flag;
void dfs(int x,int y,int dir,int depth)
{
 int cdir;
 if(depth==n)
 {
 return;
 }
 if(x==point[1].x&&y==point[1].y)
 {
 if(dir==1)
 flag=true;
 else
 flag=false;
 }
 char cc=dd[dir];
 int nx,ny;
 int nid=-1;
 if(cc=='W')
 {
 for(int i=1;i<=n;i++)
 {
 if(point[i].y==y&&point[i].x<x)
 {
 if(nid==-1)
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 else if(abs(point[i].x-x)<abs(nx-x))
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 }
 }
 }
 else if(cc=='N')
 {
 for(int i=1;i<=n;i++)
 {
 if(point[i].x==x&&point[i].y>y)
 {
 if(nid==-1)
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 else if(abs(point[i].y-y)<abs(ny-y))
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 }
 }
 }
 else if(cc=='E')
 {
 for(int i=1;i<=n;i++)
 {
 if(point[i].y==y&&point[i].x>x)
 {
 if(nid==-1)
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 else if(abs(point[i].x-x)<abs(nx-x))
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 }
 }
 }
 else if(cc=='S')
 {
 for(int i=1;i<=n;i++)
 {
 if(point[i].x==x&&point[i].y<y)
 {
 if(nid==-1)
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 else if(abs(point[i].y-y)<abs(ny-y))
 {
 ny=point[i].y;
 nx=point[i].x;
 nid=i;
 }
 }
 }
 }
 for(int i=0;i<=3;i++)
 {
 if(i==dir||(i+2)%4==dir)
 continue;
 if(check(i,nx,ny))
 {
 cdir=i;
 }
 }
 dfs(nx,ny,cdir,depth+1);
 re.push(dir);
}
int main()
{
 while(scanf("%d",&n)==1)
 {
 if(n==0)
 break;
 for(int i=1;i<=n;i++)
 scanf("%d%d",&point[i].x,&point[i].y);
 int ax=point[1].x;
 int ay=point[1].y;
 sort(point+1,point+n+1);
 for(int i=3;i>=0;i--)
 {
 if(check(i,ax,ay))
 {
 dfs(ax,ay,i,0);
 break;
 }
 }
 cnt=0;
 while(!re.empty())
 {
 int c=re.top();
 re.pop();
 rr[cnt++]=c;
 }
 if(flag)
 {
 for(int i=0;i<cnt;i++)
 printf("%c",dd[rr[i]]);
 }
 else
 {
 for(int i=cnt-1;i>=0;i--)
 {
 rr[i]=(rr[i]+2)%4;
 printf("%c",dd[rr[i]]);
 }
 }
 printf("\n");
 }
 return 0;
}
