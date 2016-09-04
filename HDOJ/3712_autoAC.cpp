#include<cstdio>
#include<iostream>
#include<complex>
#include<cmath>
using namespace std;
#define Y imag
#define X real
const double eps = 1e-9;
const char *err = "Error";
const double pi = acos(-1.0);
typedef complex<double> pnt;
static double dot(const pnt &a, const pnt& b) {return X(conj(a)*b);}
static double cross(const pnt &a, const pnt &b) {return imag(conj(a)*b);}
void work(const pnt& s, double argu) {
    while(argu<0) argu+=2*pi;
    while(argu >= 2*pi) argu -=2*pi;
    if(argu < pi+eps) {
        puts(err);
        return ;
    }
    argu = - argu;
    printf("%.3lf\n", X(s) +( abs(argu + 3*pi/2)<eps ? 0 :  Y(s)/tan(argu) ));
}
pnt jdg(const pnt& p0, const pnt& p1,const pnt& p3, const pnt& p2){
    if(cross(p3-p0,p1-p0) * cross(p2-p0,p1-p0) > -eps) return p0;
    double s1 = cross(p2-p1,p0-p1), s2 = cross(p3-p1,p0-p1);
    s1 = abs(s1), s2 = abs(s2);
    double x = (X(p2) *s2 + X(p3)*s1) / (s1+ s2);
    double y = (Y(p2) *s2 + Y(p3)*s1) / (s1+ s2);
    pnt p(x,y);
    if(cross(p3-p2,p1-p2)*cross(p3-p2,p0-p2)>0 && abs(p-p0) < abs(p-p1)) return p0;
    return p;
}
double cal(double arg0, double arg1, double tmp) {
    double t1 =arg1+pi/2-(arg0+pi);
    double s1 = sin(t1);
    double s2 = s1/tmp; 
    if(s2>=1.0 || s2 <=-1.0) return 1e10;
    else return arg1-pi/2-asin(s2);
}
int main(){
    int tst;
    double tmp;
    cin >> tst;
    pnt p[3];
    while(tst--) {
        double x1,y1,x2,y2;
        while(cin >> x1 >> y1 >> x2 >> y2){
            pnt p1(x1,y1), p2(x2,y2), p0;
            int s = -1;
            double mx = 1e10;
            for(int i=0;i<3;i++){
                cin >> x1 >> y1;
                p[i] = pnt(x1,y1);
            }
            cin >> tmp;
            for(int i=0;i<3;i++) {
                pnt P = jdg(p1,p2,p[i],p[(i+1)%3]);
                if(P == p1) continue;
                double v = abs(p1-P);
                if(v < mx) mx = v, s = i, p0 = P;
            }
            if(s == -1){
                work(p1, arg(p2-p1));
                continue;
            }
            pnt p3;
            double t = 0;
            if(cross(p2-p1, p[(s+1)%3] - p[s])<0)t = pi;
            double arg0 = cal(arg(p2-p1),arg(p[(s+1)%3] - p[s])+t,tmp);
            pnt np = pnt(X(p0) + 200*cos(arg0), Y(p0) + 200*sin(arg0));
             int k = -1;
            for(int i=0;i<3;i++) {
                if(i==s) continue;
                pnt P = jdg(p0,np,p[i],p[(i+1)%3]);
                if(P == p0) continue;
                k = i;p3 = P;
            }
            t = 0;
            if(cross(p3-p0, p[(k+1)%3] - p[k])<0)t = pi;
            double arg1 = cal(arg(p3 - p0), arg(p[(k+1)%3] - p[k])+t, 1.0/tmp);
            if(arg1 == 1e10) {
                puts(err);
                continue;
            }
            work(p3,arg1);
        }
    }
}
