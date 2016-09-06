#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
struct point {
    double x,y,z;
};
bool eql(point &a,point &b) {
    return fabs(a.x-b.x)<EPS && fabs(a.y-b.y)<EPS && fabs(a.z-b.z)<EPS;
}
double dist(point a,point b) {
    b.x-=a.x;
    b.y-=a.y;
    b.z-=a.z;
    return sqrt(sq(b.x)+sq(b.y)+sq(b.z));
}
double ar(point a,point b,point c) {
    double x=dist(a,b);
    double y=dist(b,c);
    double z=dist(c,a);
    double s=0.5*(x+y+z);
    return sqrt(s*(s-x)*(s-y)*(s-z));
}
int main() {
    int i,j,k,l,T,I,cn;
    double a,b,c,d,x,y,z;
    point tt[200];
    double g[3][2]={0};
    cin>>T;
    while(T--) {
        cin>>I>>g[0][1]>>g[1][1]>>g[2][1]>>a>>b>>c>>d;
        vector < pair < point , point > > r,tr;
        for(i=0;i<2;i++) {
            cn=0;
            x=g[0][i];
            for(j=0;j<2;j++) {
                y=g[1][j];
                z=(d-b*y-a*x)/c;
                if(z>=0 && z<=g[2][1]) {
                    tt[cn].x=x;
                    tt[cn].y=y;
                    tt[cn].z=z;
                    cn++;
                }
            }
            if(cn==2) {
                r.PB(make_pair(tt[0],tt[1]));
                continue;
            }
            for(j=0;j<2;j++) {
                z=g[2][j];
                y=(d-c*z-a*x)/b;
                if(y>=0 && y<=g[1][1]) {
                    tt[cn].x=x;
                    tt[cn].y=y;
                    tt[cn].z=z;
                    cn++;
                }
            }
            if(cn==2) r.PB(make_pair(tt[0],tt[1]));
            else if(cn==3) {
                bool f=1;
                for(j=0;j<3 && f;j++) for(l=0;l<j && f;l++) if(!eql(tt[j],tt[l])) {
                    r.PB(make_pair(tt[j],tt[l]));
                    f=0;
                }
            }
        }
        for(i=0;i<2;i++) {
            cn=0;
            y=g[1][i];
            for(j=0;j<2;j++) {
                x=g[0][j];
                z=(d-b*y-a*x)/c;
                if(z>=0 && z<=g[2][1]) {
                    tt[cn].x=x;
                    tt[cn].y=y;
                    tt[cn].z=z;
                    cn++;
                }
            }
            if(cn==2) {
                r.PB(make_pair(tt[0],tt[1]));
                continue;
            }
            for(j=0;j<2;j++) {
                z=g[2][j];
                x=(d-c*z-b*y)/a;
                if(x>=0 && x<=g[0][1]) {
                    tt[cn].x=x;
                    tt[cn].y=y;
                    tt[cn].z=z;
                    cn++;
                }
            }
            if(cn==2) r.PB(make_pair(tt[0],tt[1]));
            else if(cn==3) {
                bool f=1;
                for(j=0;j<3 && f;j++) for(l=0;l<j && f;l++) if(!eql(tt[j],tt[l])) {
                    r.PB(make_pair(tt[j],tt[l]));
                    f=0;
                }
            }
        }
        for(i=0;i<2;i++) {
            cn=0;
            z=g[2][i];
            for(j=0;j<2;j++) {
                y=g[1][j];
                x=(d-b*y-c*z)/a;
                if(x>=0 && x<=g[0][1]) {
                    tt[cn].x=x;
                    tt[cn].y=y;
                    tt[cn].z=z;
                    cn++;
                }
            }
            if(cn==2) {
                r.PB(make_pair(tt[0],tt[1]));
                continue;
            }
            for(j=0;j<2;j++) {
                x=g[0][j];
                y=(d-c*z-a*x)/b;
                if(y>=0 && y<=g[1][1]) {
                    tt[cn].x=x;
                    tt[cn].y=y;
                    tt[cn].z=z;
                    cn++;
                }
            }
            if(cn==2) r.PB(make_pair(tt[0],tt[1]));
            else if(cn==3) {
                bool f=1;
                for(j=0;j<3 && f;j++) for(l=0;l<j && f;l++) if(!eql(tt[j],tt[l])) {
                    r.PB(make_pair(tt[j],tt[l]));
                    f=0;
                }
            }
        }
        for(i=0;i<r.size();i++) if(!eql(r[i].first,r[i].second)) tr.PB(r[i]);
        r=tr;
        vector < point > ls;
        j=0;
        ls.push_back(r[0].first);
        j=0;
        for(i=0;i<r.size();i++) {
            for(k=0;k<r.size();k++) if(k!=j) {
                if(eql(ls.back(),r[k].first)) {
                    ls.PB(r[k].second);
                    break;
                }
                if(eql(ls.back(),r[k].second)) {
                    ls.PB(r[k].first);
                    break;
                }
            }
            j=k;
        }
        double res=0;
        for(i=0;i<ls.size();i++) 
        for(i=2;i<ls.size()-1;i++) res+=ar(ls[0],ls[i-1],ls[i]);
        z=g[2][1];
        if(fabs(r.back().first.z-z)<=EPS && fabs(r.back().second.z-z)<=EPS) {
            r.clear();
            r.PB(tr.back());
            for(i=0;i<2;i++) {
                x=g[0][i];
                if(a*x+b*g[1][0]+c*z<=d && a*x+b*g[1][1]+c*z<=d) {
                    y=(d-c*z-a*x)/b;
                    tt[0].x=x;
                    tt[0].y=g[1][0];
                    tt[0].z=z;
                    tt[1].x=x;
                    tt[1].y=g[1][1];
                    tt[1].z=z;
                    r.PB(make_pair(tt[0],tt[1]));
                }
                else if(a*x+b*g[1][0]+c*z<=d) {
                    y=(d-c*z-a*x)/b;
                    tt[0].x=x;
                    tt[0].y=g[1][0];
                    tt[0].z=z;
                    tt[1].x=x;
                    tt[1].y=y;
                    tt[1].z=z;
                    r.PB(make_pair(tt[0],tt[1]));
                }
                else if(a*x+b*g[1][1]+c*z<=d) {
                    y=(d-c*z-a*x)/b;
                    tt[0].x=x;
                    tt[0].y=y;
                    tt[0].z=z;
                    tt[1].x=x;
                    tt[1].y=g[1][1];
                    tt[1].z=z;
                    r.PB(make_pair(tt[0],tt[1]));
                }
            }
            for(i=0;i<2;i++) {
                y=g[1][i];
                if(a*g[0][0]+b*y+c*z<=d && a*g[0][1]+b*y+c*z<=d) {
                    x=(d-c*z-b*y)/a;
                    tt[0].x=g[0][0];
                    tt[0].y=y;
                    tt[0].z=z;
                    tt[1].x=g[0][1];
                    tt[1].y=y;
                    tt[1].z=z;
                    r.PB(make_pair(tt[0],tt[1]));
                }
                else if(a*g[0][0]+b*y+c*z<=d) {
                    x=(d-c*z-b*y)/a;
                    tt[0].x=g[0][0];
                    tt[0].y=y;
                    tt[0].z=z;
                    tt[1].x=x;
                    tt[1].y=y;
                    tt[1].z=z;
                    r.PB(make_pair(tt[0],tt[1]));
                }
                else if(a*g[0][1]+b*y+c*z<=d) {
                    x=(d-c*z-b*y)/a;
                    tt[0].x=x;
                    tt[0].y=y;
                    tt[0].z=z;
                    tt[1].x=g[0][1];
                    tt[1].y=y;
                    tt[1].z=z;
                    r.PB(make_pair(tt[0],tt[1]));
                }
            }
            tr.clear();
            for(i=0;i<r.size();i++) if(!eql(r[i].first,r[i].second)) tr.PB(r[i]);
            r=tr;
            for(i=0;i<r.size();i++) {
            }
            vector < point > ls;
            j=0;
            ls.push_back(r[0].first);
            j=0;
            for(i=0;i<r.size();i++) {
                for(k=0;k<r.size();k++) if(k!=j) {
                    if(eql(ls.back(),r[k].first)) {
                        ls.PB(r[k].second);
                        break;
                    }
                    if(eql(ls.back(),r[k].second)) {
                        ls.PB(r[k].first);
                        break;
                    }
                }
                j=k;
            }
            for(i=0;i<ls.size();i++) 
            for(i=2;i<ls.size()-1;i++) res+=ar(ls[0],ls[i-1],ls[i]);
        }
        cout<<I<<' '<<ceil(res-EPS)<<'\n';
    }
    return 0;
}
