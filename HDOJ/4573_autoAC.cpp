#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define db double
#define rt return
#define cs const
#define cp const P&
#define op operator
cs db eps = 1e-9;
inline int sig(db x){rt (x>eps)-(x<-eps);}
cs int N = 10001;
struct P {
    db x, y, z;
    P(db a = 0, db b = 0, db c = 0):x(a),y(b),z(c){}
    void in(){scanf("%lf%lf%lf", &x, &y, &z);}
    P op+(cp a)cs{rt P(x+a.x, y+a.y, z+a.z);}
    P op-(cp a)cs{rt P(x-a.x, y-a.y, z-a.z);}
    P op*(cs db&k)cs{rt P(x*k, y*k, z*k);}
    P op^(cp a)cs{rt P(y*a.z-a.y*z, z*a.x-a.z*x, x*a.y-a.x*y);}
    db op*(cp a)cs{rt x*a.x + y*a.y + z*a.z;}
    P cross(P a, P b){rt a-*this ^ b-*this;}
    db dot(P a, P b){rt (a-*this) * (b-*this);}
    db L(){rt sqrt(x*x + y*y + z*z);}
    db V6(P b, P c){rt (b ^ c) * (*this);}
}p[N];
int n;
db diff_vol, max_diff;
struct convex {
    int cnt, blg[N][N];
    struct face {
       int a, b, c, is;
       face(int x=0,int y=0,int z=0,int w=0):a(x),b(y),c(z),is(w){}
       int visible(P me) {
           rt sig(p[a].cross(p[b],p[c]) * (me-p[a])) > 0;
       }
    }fac[N*10];
    int col(int a, int b, int c){rt p[a].cross(p[b],p[c]).L() < eps;}
    int cop(int a, int b, int c, int d){rt !sig(p[a].cross(p[b],p[c])*(p[d]-p[a]));}
    void deal(int k, int a, int b) {
       int f = blg[a][b];
       if(fac[f].is) {
           if(fac[f].visible(p[k])) dfs(k, f);
           else {
               diff_vol += p[b].V6(p[a], p[k]);
               face add = face(b, a, k, 1);
               blg[b][a] = blg[a][k] = blg[k][b] = cnt;
               fac[cnt++] = add;
           }
       }
    }
    void dfs(int k, int cur) {
       diff_vol -= p[fac[cur].a].V6(p[fac[cur].b], p[fac[cur].c]);
       fac[cur].is = 0;
       deal(k, fac[cur].b, fac[cur].a);
       deal(k, fac[cur].c, fac[cur].b);
       deal(k, fac[cur].a, fac[cur].c);
    }
    void init() {
        cnt = 0;
        for(int i = 0; i < 4; i++) {
           face add = face((i+1)%4, (i+2)%4, (i+3)%4, 1);
           if(add.visible(p[i])) swap(add.b, add.c);
           blg[add.a][add.b] = blg[add.b][add.c] = blg[add.c][add.a] = cnt;
           fac[cnt++] = add;
        }
    }
    void update(int k) {
        for(int i = 0; i < cnt; i++)
            if(fac[i].is && fac[i].visible(p[k])) {
                dfs(k, i); break;
            }
    }
    db volume() {
       db v = 0.;
       for(int i = 0; i < cnt; i++)
           v += fac[i].is * p[fac[i].a].V6(p[fac[i].b], p[fac[i].c]);
       rt v / 6.;
    }
}hull;
void solve(int number, int cas) {
    max_diff = 0.;
    int king = 1, tag = 1;
    p[0].in();
    for(int i = 1; i < number; i++) {
        p[i].in();
        if(tag == 1) {
            tag += sig((p[0]-p[i]).L());
            if(tag > 1) swap(p[1], p[i]);
            continue;
        }
        if(tag == 2) {
            tag += sig((p[0].cross(p[1], p[i])).L());
            if(tag > 2) swap(p[2], p[i]);
            continue;
        }
        if(tag == 3) {
            tag += sig(p[0].cross(p[1], p[2]) * (p[i]-p[0])) != 0;
            if(tag > 3) {
                swap(p[3], p[i]);
                hull.init();
                for(int j = 4; j <= i; j++) hull.update(j);
                king = i + 1, max_diff = hull.volume();
            }
            continue;
        }
        diff_vol = 0.;
        hull.update(i);
        diff_vol /= 6.;
        if(sig(diff_vol - max_diff) > 0) {
            max_diff = diff_vol;
            king = i + 1;
        }
    }
    printf("Case #%d:\n%d %.2lf\n", cas, king, max_diff);
}
int main() {
    int number, cas = 1;
    while(scanf("%d", &number) != -1) solve(number, cas++);
    rt 0;
}
