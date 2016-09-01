#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> s;
map<int,int>::iterator it;
double eps=1e-10;
int n,m;
const double pi=acos(-1.0);
int fa[1001],x[1001],y[1001],cx[1001],cy[1001],r[1001];
struct Eve
{
 double ang;
 int id,L,f;
 bool operator<(const Eve &b)const
 {
 if(fabs(ang-b.ang)>eps)return ang<b.ang;
 return f>b.f;
 }
}p[8001];
int find(int x)
{
 if(x==fa[x])return x;
 return fa[x]=find(fa[x]);
}
void U(int i,int j)
{
 fa[find(i)]=find(j);
}
int main()
{
 while(~scanf("%d%d",&n,&m))
 {
 for(int i=0;i<n;i++){scanf("%d%d",x+i,y+i);fa[i]=i;}
 for(int i=0;i<m;i++)scanf("%d%d%d",cx+i,cy+i,r+i);
 if(m==0){puts("0");continue;}
 for(int i=0;i<n;i++)
 {
 int t=0;
 for(int j=i+1;j<n;j++)
 {
 p[t].ang=atan2((double)(y[j]-y[i]),(double)(x[j]-x[i]));
 if(p[t].ang<-eps)p[t].ang+=pi*2;
 p[t].id=j;
 p[t].L=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
 p[t++].f=0;
 }
 for(int j=0;j<m;j++)
 {
 double th=atan2((double)(cy[j]-y[i]),(double)(cx[j]-x[i]));
 int d=(cx[j]-x[i])*(cx[j]-x[i])+(cy[j]-y[i])*(cy[j]-y[i]);
 double dt=asin((double)r[j]/sqrt((double)d));
 int ds=d-r[j]*r[j];
 double u=th-dt,v=th+dt;
 if(u<0)u+=pi*2,v+=pi*2;
 if(v<pi*2+eps)
 {
 p[t].L=ds;
 p[t].ang=u;
 p[t++].f=1;
 p[t].L=ds;
 p[t].ang=v;
 p[t++].f=-1;
 }
 else
 {
 p[t].L=ds;
 p[t].ang=u;
 p[t++].f=1;
 p[t].L=ds;
 p[t].ang=pi*2;
 p[t++].f=-1;
 p[t].L=ds;
 p[t].ang=0;
 p[t++].f=1;
 p[t].L=ds;
 p[t].ang=v-pi*2;
 p[t++].f=-1;
 }
 }
 sort(p,p+t);
 s.clear();
 for(int j=0,tot=0;j<t;j++)
 {
 if(p[j].f==0)
 {
 if(tot==0)U(i,p[j].id);
 else
 {
 it=s.begin();
 if(it->first>p[j].L)U(i,p[j].id);
 }
 }
 else if(p[j].f==1)
 {
 s[p[j].L]++;
 ++tot;
 }
 else
 {
 s[p[j].L]--;
 if(s[p[j].L]==0)s.erase(p[j].L);
 --tot;
 }
 }
 }
 int cnt=0;
 for(int i=0;i<n;i++)if(find(i)==i)++cnt;
 printf("%d\n",--cnt);
 }
}
