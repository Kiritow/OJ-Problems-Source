#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define SORT(x) sort(x.OP,x.ED)
#define SQ(x) ((x)*(x))
#define SSP system("pause")
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
typedef long long LL;
typedef pair<int, int> PII;
const double eps=1e-8;
const double PI=acos(-1.);
const LL MOD = 1000000007;
int sign(double x) {return x<-eps?-1:x>eps;}
struct spt {
    double x,y,z;
    spt(double _x=0,double _y=0,double _z=0) :x(_x),y(_y),z(_z) {}
    spt operator + (spt s) {return spt(x+s.x,y+s.y,z+s.z);}
    spt operator - (spt s) {return spt(x-s.x,y-s.y,z-s.z);}
    spt operator * (double s) {return spt(x*s,y*s,z*s);}
    spt operator / (double s) {return spt(x/s,y/s,z/s);}
    double len() const {return sqrt(SQ(x)+SQ(y)+SQ(z));}
    double operator * (spt s) {return x*s.x+y*s.y+z*s.z;}   
    spt operator ^ (spt s) {    
        spt ret;
        ret.x=y*s.z-z*s.y;
        ret.y=z*s.x-x*s.z;
        ret.z=x*s.y-y*s.x;
        return ret;
    }
    void output(char *s="") {printf("%s:%.6f %.6f %.6f\n",s,x,y,z);}
    void input() {scanf("%lf%lf%lf",&x,&y,&z);}
} Orz(0,0,0);
spt S,T,V,A,B,C;
double disLP(spt p1,spt p2,spt q) {
    return fabs((p2-p1)*(q-p1)/(p2-p1).len());
}
double disLL(spt p1,spt p2,spt q1,spt q2) {
    spt p=q1-p1,u=p2-p1,v=q2-q1;
    double d=(u*u)*(v*v)-SQ(u*v);
    if(sign(d)==0)return disLP(q1,q2,p1);
    double s=((p*u)*(v*v)-(p*v)*(u*v))/d;
    return disLP(q1,q2,p1+u*s);
}
int isFL(spt p,spt o,spt q1,spt q2,spt &is) {
    double a=o*(q2-p),b=o*(q1-p);
    double d=a-b;
    if(sign(d)==0)return 0;
    is=(q1*a-q2*b)/d;
    return 1;
}
int isFF(spt p1,spt o1,spt p2,spt o2,spt &ip,spt &io) {
    spt e=o1^o2;
    spt v=o1^e;
    double d=o2*v;
    if(sign(d)==0)return 0;
    ip=p1+v*(o2*(p2-p1))/d,io=e;
    return 1;
}
int inner(spt O,spt A,spt B,spt C) {
    double S=((B-A)^(C-A)).len();
    double S1=((A-O)^(B-O)).len();
    double S2=((A-O)^(C-O)).len();
    double S3=((C-O)^(B-O)).len();
    return sign(S-S1-S2-S3)==0;
}
int inner(double o,double a,double b) {
    return sign(max(a,b)-o)>=0&&sign(min(a,b)-o)<=0;
}
int inner(spt O,spt A,spt B) {
    return inner(O.x,A.x,B.x)&&inner(O.y,A.y,B.y)&&inner(O.z,A.z,B.z);
}
int main() {
    int i,j,k,u,v,w,p,q,r,n,m;
    while(~scanf("%d",&n)) {
        S.input(),T.input();
        V.input();
        double ans=0;
        spt U= (S-T) ^V;
        for(j=0; j<n; j++) {
            A.input(),B.input(),C.input();
            spt D= (B-A) ^ (C-A);
            if(sign(D.len()) ==0) continue;
            if(sign(U.len())==0) {
                spt is;
                int f=isFL(A,D,S,S+V,is);
                if(f) {
                    ans+=inner(is,A,B,C);
                    continue;
                }
                if(sign((S-A)*D))continue;
                spt iAB,iBC,iAC;
                int fAB=isFL(A,D^(A-B),S,S+V,iAB);
                int fBC=isFL(B,D^(B-C),S,S+V,iBC);
                int fAC=isFL(C,D^(C-A),S,S+V,iAC);
                fAB&=inner(iAB,A,B);
                fBC&=inner(iBC,B,C);
                fAC&=inner(iAC,A,C);
                ans+=fAB|fBC|fAC;
                continue;
            }
            if(sign(V*D)==0) {
                if(sign((S-A)*D)==0&&sign((T-A)*D)==0) {
                    //TODO V//ABC && STABC on flat
                    spt iA,iB,iC;
                    int fA=isFL(S,(T-S)^D,A,A+V,iA);
                    int fB=isFL(S,(T-S)^D,B,B+V,iB);
                    int fC=isFL(S,(T-S)^D,C,C+V,iC);
                    double len=(T-S).len();
                    double le=0,re=len;
                    vector<double>L;
                    if(fA)L.PB((iA-S)*(T-S)/len);
                    if(fB)L.PB((iB-S)*(T-S)/len);
                    if(fC)L.PB((iC-S)*(T-S)/len);
                    sort(L.OP,L.ED);
                    if(L.SZ<2)continue;
                    double pe=L[0],qe=L[L.SZ-1];
                    cmax(pe,le);
                    cmin(qe,re);
                    if(qe>pe)ans+=(qe-pe)/len;
                }
                continue;
            }
            spt SP,TP,iAB,iBC,iAC;
            assert(isFL(A,D,S,S+V,SP));
            assert(isFL(A,D,T,T+V,TP));
            if(inner(SP,A,B,C)&&inner(TP,A,B,C)) {ans+=1; continue;}
            vector<spt>L;
            L.PB(SP),L.PB(TP);
            int fAB=isFL(A,D^(A-B),SP,TP,iAB);
            int fBC=isFL(B,D^(B-C),SP,TP,iBC);
            int fAC=isFL(C,D^(C-A),SP,TP,iAC);
            double len=(SP-TP).len();
            if(fAB&&inner(iAB,SP,TP))for(i=0; i+1<L.SZ; i++)
                    if(inner(iAB,L[i],L[i+1])) {L.insert(L.OP+i+1,iAB); break;}
            if(fBC&&inner(iBC,SP,TP))for(i=0; i+1<L.SZ; i++)
                    if(inner(iBC,L[i],L[i+1])) {L.insert(L.OP+i+1,iBC); break;}
            if(fAC&&inner(iAC,SP,TP))for(i=0; i+1<L.SZ; i++)
                    if(inner(iAC,L[i],L[i+1])) {L.insert(L.OP+i+1,iAC); break;}
            for(i=0; i+1<L.SZ; i++) {
                spt mid=(L[i]+L[i+1])/2;
                if(inner(mid,A,B,C))
                    ans+=(L[i+1]-L[i]).len()/len;
            }
        }
        printf("%.8f\n",ans);
    }
    return 0;
}
