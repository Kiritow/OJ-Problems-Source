#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;
int sgn(double x){
if(fabs(x) <= eps) return 0;
return x > 0 ? 1 : -1;
}
struct P{
double x , y;
P(double _x = 0,double _y = 0){
x = _x , y =  _y;
}
void set(double _x,double _y){
x = _x , y = _y;
}
void out(){
printf("%.6lf %.6lf\n",x,y);
}
P operator + (P b){
return P(x+b.x,y+b.y);
}
P operator - (P b){
return P(x-b.x,y-b.y);
}
P operator / (double k){
return P(x/k , y/k);
}
bool operator == (const P&b) const{
return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
}
double lenq(){
return x*x + y*y;
}
double len(){
return sqrt(lenq());
}
};
double dis(P a,P b){
return (a-b).len();
}
struct Cir{
P o;
double r;
Cir(P _o,double _r = 0){
o = _o , r = _r;
}
void set(P _o,double _r){
o = _o , r = _r;
}
bool operator == (const Cir&b) const{
return o == b.o && sgn(r - b.r) == 0;
}
};
void c2point(Cir c1,Cir c2,P &rp1,P &rp2){
if(c1 == c2){
rp1 = c1.o + P(0,c1.r);
rp2 = c1.o - P(0,c1.r);
return;
}
P p1 = c1.o , p2 = c2.o;
double r1 = c1.r , r2 = c2.r;
double a = p2.x - p1.x , b = p2.y - p1.y , r = (a*a + b*b + r1*r1 - r2*r2) / 2;
double tmp;
if(a == 0 && b != 0){
rp1.y = rp2.y = r / b;
tmp = r1 * r1 - rp1.y * rp1.y;
if(sgn(tmp) <= 0) tmp = 0;
rp1.x = sqrt(tmp);
rp2.x = -rp1.x;
}
else if(a != 0 && b == 0){
rp1.x = rp2.x = r / a;
tmp = r1 * r1 - rp1.x * rp1.x;
if(sgn(tmp) <= 0) tmp = 0;
rp1.y = sqrt(tmp);
rp2.y = -rp1.y;
}
else if(a != 0 && b != 0){
double delta = b*b*r*r - (a*a + b*b) * (r*r - r1*r1*a*a);
if(sgn(delta) <= 0) delta = 0;
rp1.y = (b*r + sqrt(delta)) / (a*a + b*b);
rp2.y = (b*r - sqrt(delta)) / (a*a + b*b);
rp1.x = (r - b*rp1.y) / a;
rp2.x = (r - b*rp2.y) / a;
}
rp1.x += p1.x , rp1.y += p1.y;
rp1.x += p1.x , rp2.y += p1.y;
}
int T;
double AB , BC , CD , DA , EF;
P A , B , C , D , A2 , G;
void graph_construct(){
C.set(0,0);
B.set(BC,0);
Cir O1(C,DA) , O2(B,2 * EF);
P discard;
c2point(O1,O2,A2,discard);
G = A2 + (B - C);
O1.set(C,CD);O2.set(G,AB);
c2point(O1,O2,D,discard);
A = D + (C - A2);
}
const double eps2 = 1e-4;
int sgn2(double x){
if(fabs(x) <= eps2) return 0;
return 1;
}
void spj(){
bool ff = true;
if(sgn2(AB - dis(A,B)) != 0) ff = false;
if(sgn2(BC - dis(B,C)) != 0) ff = false;
if(sgn2(CD - dis(C,D)) != 0) ff = false;
if(sgn2(DA - dis(D,A)) != 0) ff = false;
if(sgn2(EF - dis((A+B)/2,(C+D)/2)) != 0) ff = false;
}
int main(){
scanf("%d",&T);
for(int _=1;_<=T;++_){
scanf("%lf%lf%lf%lf%lf",&AB,&BC,&CD,&DA,&EF);
graph_construct();
printf("Case #%d:\n",_);
A.out();B.out();C.out();D.out();
spj();
}
return 0;
}
