#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define db double
#define rt return
#define cs const
cs db eps = 1e-8 , PI = acos(-1.);
inline int sig(db x){rt (x>eps)-(x<-eps);}
#define cp const P&
#define op operator
cs int N = 511;
struct P {
    db x , y , z;
    P(db a = 0 , db b = 0 , db c = 0):x(a),y(b),z(c){}
    void in(){scanf("%lf%lf%lf" , &x , &y , &z);}
    P op+(cp a)cs{rt P(x+a.x , y+a.y , z+a.z);}
    P op-(cp a)cs{rt P(x-a.x , y-a.y , z-a.z);}
    P op*(cs db&k)cs{rt P(x*k , y*k , z*k);}
    P op^(cp a)cs{rt P(y*a.z-a.y*z , z*a.x-a.z*x , x*a.y-a.x*y);}
    db op*(cp a)cs{rt x*a.x + y*a.y + z*a.z;}
    db L(){rt sqrt(x*x + y*y + z*z);}
    db rela(P v){rt sig(*this * v) * L();}
    P cross(P a , P b){rt a-*this ^ b-*this;}
    db dot(P a , P b){rt (a-*this) * (b-*this);}
    int on_seg(P a , P b){rt cross(a,b).L() < eps && dot(a , b) < eps;}
};
P vp1[N] , vp2[N];
int cnt1 , cnt2;
struct face {
    P a , b , c , v;
    void init(){v = a.cross(b , c);}
    int side(P p){rt sig(v*(p-a));}
    int inter_line(P p , P vec , P &x) {
        if(!sig(v*vec)) rt 0;
        x = p + vec * (v*(a-p) / (v*vec));
        rt 1;
    }
};
inline db get_angle(P o , P a , P b , P v) {
    rt atan2(o.cross(a , b).rela(v) , o.dot(a , b));
}
int read() {
    scanf("%d%d" , &cnt1 , &cnt2);
    for(int i = 0 ; i < cnt1 ; i++) vp1[i].in();
    for(int i = 0 ; i < cnt2 ; i++) vp2[i].in();
    vp1[cnt1] = vp1[0] , vp2[cnt2] = vp2[0];
    rt cnt1 + cnt2;
}
inline int in_poly(P p , P vp[] , int n) {
    for(int i = 0 ;i < n ; i++)
        if(p.on_seg(vp[i] , vp[i+1])) rt 1;
    P v;
    for(int i = 2 ; i < n ; i++)
        if(sig(vp[0].cross(vp[1] , vp[i]).L())) {
            v = vp[0].cross(vp[1] , vp[i]);
            break;
        }
    db agl = 0.;
    for(int i = 0 ; i < n ; i++)
        agl += get_angle(p , vp[i] , vp[i+1] , v);
    rt !sig(agl-2.*PI) || !sig(agl+2.*PI);
}
inline int seg_seg(P a , P b , P c , P d) {
    if(sig(a.cross(b , c) * (d-a))) rt 0;
    P v = b - a ^ d - c;
    db t = v.L();
    if(sig(t) == 0)
        rt a.on_seg(c , d) || b.on_seg(c , d) || c.on_seg(a , b) || d.on_seg(a , b);
    db u1 = c.cross(d , a).rela(v) / t , u2 = a.cross(c , b).rela(v) / t;
    rt sig(u1*(u1-1.)) <= 0 && sig(u2*(u2-1.)) <= 0;
}
inline int seg_face(P a , P b , P vp[] , int n) {
    face f;
    for(int i = 2 ; i < n ; i++)
        if(sig(vp[0].cross(vp[1] , vp[i]).L())) {
            f.a = vp[0] , f.b = vp[1] , f.c = vp[i] , f.init();
            break;
        }
    int l = f.side(a) , r = f.side(b);
    if(l * r > 0) rt 0;
    if(l || r) {
        P xp;
        f.inter_line(a , b - a , xp);
        rt in_poly(xp , vp , n);
    }
    for(int i = 0 ; i < n ; i++)
        if(seg_seg(a , b , vp[i] , vp[i+1])) rt 1;
    rt in_poly(a , vp , n) || in_poly(b , vp , n);
}
inline int face_face(P vp1[] , int cn1 , P vp2[] , int cnt2) {
    for(int i = 0 ; i < cnt1 ; i++) {
        if(seg_face(vp1[i] , vp1[i+1] , vp2 , cnt2)) rt 1;
    }
    rt 0;
}
inline int test_data(P vp[] , int n) {
    int line = 1;
    for(int i = 2 ; line && i < n ; i++)
        if(sig(vp[0].cross(vp[1] , vp[i]).L())) line = 0;
    rt !line;
}
void solve() {
    int pic1 = test_data(vp1 , cnt1) , pic2 = test_data(vp2 , cnt2);
    int inter = 0;
    if(pic1 == 0 && pic2 == 0) {
        for(int i = 0 ; inter == 0 && i < cnt1 ; i++)
            for(int j = 0 ; inter == 0 && j < cnt2 ; j++)
                inter = seg_seg(vp1[i] , vp1[i+1] , vp2[j] , vp2[j+1]);
    }
    if(pic1 == 0 && pic2 == 1) {
        for(int i = 0 ; inter == 0 && i < cnt1 ; i++)
            inter = seg_face(vp1[i] , vp1[i+1] , vp2 , cnt2);
    }
    if(pic1 == 1 && pic2 == 0) {
        for(int i = 0 ; inter == 0 && i < cnt2 ; i++)
            inter = seg_face(vp2[i] , vp2[i+1] , vp1 , cnt1);
    }
    if(pic1 == 1 && pic2 == 1) {
        inter = face_face(vp1 , cnt1 , vp2 , cnt2) ||
                    face_face(vp2 , cnt2 , vp1 , cnt1);
    }
    puts(inter ? "YES" : "NO");
}
int main() {
    while(read()) {
        solve();
    }
    rt 0;
}
