#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef double db;
const db PI = acos(-1.0);
const db eps = 1e-15;
const db oo = 1e100;
struct pt{
 db x,y;
 pt(){}pt(db x,db y):x(x),y(y){}
 pt operator -(pt a){return pt(x-a.x,y-a.y);}
 db operator *(pt a){return x*a.x+y*a.y;}
 db operator &(pt a){return x*a.y-y*a.x;}
 db len(){return sqrt(x*x+y*y);}
 db ang(){return atan2(y,x);}
 void getP(){scanf("%lf%lf",&x,&y);}
};
struct circle{
 pt o;
 db r,a,l;
 void getC(){o.getP();l = o.len();a = o.ang();scanf("%lf",&r);}
};
struct box{
 db s,d,c;
};
const int MaxC = 1024;
circle cl[MaxC];
box fm[MaxC][MaxC];
db dis[MaxC],w[MaxC];
bool U[MaxC];
int sign(db x){return (x > eps)-(x < -eps);}
db calTime(int x,int y,db ct){
 box &cb = fm[x][y];
 if (cb.c > oo / 2)
 return oo;
 if (sign(cb.c) == 0)
 return ct;
 db ft = cb.s+floor((ct-cb.s) / cb.c-1.0)*cb.c;
 while (sign(ft-ct) < 0 && sign(ct-ft-cb.d) > 0)
 ft += cb.c;
 return max(ft,ct);
}
int main(){
 int tCase;
 scanf("%d",&tCase);
 for (int ct = 1;ct <= tCase;ct++){
 int N;
 scanf("%d",&N);
 for (int i = 0;i < N;i++){
 cl[i].getC();
 scanf("%lf",&w[i]);
 }
 for (int i = 0;i < N;i++)
 for (int j = 0;j < N;j++)if (i != j){
 box &cb = fm[i][j];
 db a = cl[i].l,b = cl[j].l,c = cl[j].r;
 if (sign(c-fabs(a-b)) < 0){
 cb.c = oo;
 continue;
 }
 if (sign(c-a-b) >= 0){
 cb.c = 0.0;
 continue;
 }
 db cd = (a*a+b*b-c*c) / (2.0*a*b);
 if (sign(cd-1.0) >= 0) cd = 1.0;
 if (sign(cd+1.0) <= 0) cd = -1.0;
 db da = acos(cd);
 db cw = w[i]-w[j];
 db ca = cl[j].a-cl[i].a;
 while (sign(ca+PI) < 0) ca += PI*2;
 if (sign(cw) == 0){
 if (sign(fabs(ca)-da) <= 0)
 cb.c = 0.0;
 else
 cb.c = oo;
 continue;
 }
 cb.c = PI*2.0 / fabs(cw);
 cb.d = da*2.0 / fabs(cw);
 cb.s = ca / cw-cb.d*0.5;
 }
 memset(U,0,sizeof(U[0])*N);
 dis[0] = 0.0;
 for (int j = 1;j < N;j++)
 dis[j] = calTime(0,j,0.0);
 U[0] = true;
 for (int i = 1;i < N;i++){
 int mj = -1;
 db md = oo;
 for (int j = 0;j < N;j++)
 if (!U[j] && dis[j] < md)
 md = dis[mj = j];
 if (mj == N-1) break;
 U[mj] = true;
 for (int j = 0;j < N;j++)
 if (!U[j]){
 db nd = calTime(mj,j,md);
 dis[j] = min(nd,dis[j]);
 }
 }
 if (dis[N-1] > oo / 2) while(1);
 printf("%.f\n",ceil(dis[N-1]));
 }
 return 0;
}
