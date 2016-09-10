#include<iostream>  
#include<cstdio>  
#include<complex>  
#include<vector>  
#include<cmath>  
#include<cstdlib>  
#include<algorithm>  
using namespace std;  
const double eps=1.0e-8;  
typedef complex<double> point;  
typedef vector<point> polygon;  
struct line : public vector<point> {  
    line() {}  
    line(const point& a, const point& b) { push_back(a); push_back(b); }  
};  
inline point vec(const line& l) { return l[1]-l[0];}  
inline double dot  (const point& a, const point& b) { return (a*conj(b)).real();}  
inline double cross(const point& a, const point& b) { return (conj(a)*b).imag();}  
inline int dlcmp(const double& x){  
    return x<-eps?-1:x>eps;  
}  
bool intersectSP(const line& s, const point& p) {  
    return abs(s[0]-p)+abs(s[1]-p)<abs(s[1]-s[0])+eps;  
}  
point projection(const line &l, const point &p) {  
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);  
    return l[0] + t*(l[0]-l[1]);  
}  
double distanceSP(const line &s, const point &p) {  
    const point& r = projection(s, p);  
    if (intersectSP(s, r)) return abs(r - p);  
    return min(abs(s[0]-p), abs(s[1]-p));  
}  
polygon p;  
const int MAXN=50005;  
bool direction[MAXN];  
inline double calc(const point& start, const point& m, const point& target, const double& Vr, const double& Vs){  
    return abs(start-m)/Vr+abs(m-target)/Vs;  
}  
point m1, m2, v;  
double mid, midd;  
double solve(const line& S, const point& start, const point& target, const double& Vr, const double& Vs, double& ts){  
    double l=0.0, r=1.0;  
    v=vec(S);  
    while(l+eps<r){  
        mid=(l+r)/2.0;  
        midd=(mid+r)/2.0;  
        m1=S[0]+mid*v;  
        m2=S[0]+midd*v;  
        if(calc(start,m1,target,Vr,Vs)<calc(start,m2,target,Vr,Vs)){  
            r=midd;  
        }  
        else{  
            l=mid;  
        }  
    }  
    ts=abs(S[0]+l*v-target)/Vs;  
    return calc(start,S[0]+l*v,target,Vr,Vs);  
}  
point cut[2];  
int R[2];  
point p1, p2;  
int main(){  
    int T, n; cin>>T;  
    while(T--){  
        double Ts, Vr, Vs; cin>>Ts>>Vr>>Vs;  
        double Xo, Yo, Xp, Yp; cin>>Xo>>Yo>>Xp>>Yp;  
        point O(Xo,Yo), P(Xp,Yp);  
        cin>>n;  
        p.clear();  
        double x, y;  
        for(int i=0; i<n; i++){  
            scanf("%lf%lf",&x,&y);  
            p.push_back(point(x,y));  
        }  
        if(dlcmp(cross(p[1]-p[0],p[2]-p[1]))<0){  
            reverse(p.begin(),p.end());  
        }  
        double carry_and_swim=1.0e20;  
        for(int i=0; i<n; i++){  
            carry_and_swim=min(carry_and_swim,distanceSP(line(p[i],p[(i+1)%n]),P));  
        }  
        carry_and_swim=2.0*carry_and_swim/Vs;  
        double sum=0.0;  
        for(int i=0; i<n; i++){  
            direction[i]=dlcmp(cross(p[i]-O,p[(i+1)%n]-p[i]))>=0;  
            sum+=abs(p[i]-p[(i+1)%n]);  
        }  
        int cnt=0;  
        for(int i=0; i<n; i++){  
            if(direction[i]!=direction[(i+1)%n]){  
                R[cnt++]=(i+1)%n;  
            }  
            if(intersectSP(line(p[i],p[(i+1)%n]),O)){  
                cut[0]=p[i];  
                cut[1]=p[(i+1)%n];  
                R[0]=i; R[1]=(i+1)%n;  
            }  
        }  
        if(cnt!=0){  
            if(direction[R[0]]!=0) swap(R[0],R[1]);  
            cut[0]=p[R[0]]; cut[1]=p[R[1]];  
        }  
        double ans=1.0e20;  
        int st=R[0], ed=R[1];  
        if(ed<st) ed+=n;  
        double ft=0.0;  
        double ts, ts1, ts2, ret;  
        for(int i=st; i<ed; i++){  
            p1=p[i%n], p2=p[(i+1)%n];  
            ret=solve(line(p1,p2),O,P,Vr,Vs,ts);  
            if(ts+carry_and_swim-eps<=Ts){  
                ans=min(ans,ret);  
            }  
            ft+=abs(p1-p2);  
        }  
        swap(st,ed);  
        if(ed<st) ed+=n;  
        double bk=0.0, al=(sum-ft), d1, d2;  
        for(int i=st; i<ed; i++){  
            p1=p[i%n], p2=p[(i+1)%n];  
            d1=(abs(O-cut[1])+bk)/Vr+solve(line(p1,p2),p1,P,Vr,Vs,ts1);  
            d2=(abs(O-cut[0])+al-bk-abs(p1-p2))/Vr+solve(line(p2,p1),p2,P,Vr,Vs,ts2);  
            if(ts1+carry_and_swim-eps<=Ts){  
                ans=min(ans,d1);  
            }  
            if(ts2+carry_and_swim-eps<=Ts){  
                ans=min(ans,d2);  
            }  
            bk+=abs(p1-p2);  
        }  
        ans+=carry_and_swim;  
        if(ans<=1.0e19) printf("%.2f\n",ans);  
        else printf("-1\n");  
    }  
    return 0;  
}
