#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdlib>
#define pbk push_back
using namespace std;
const int N = 25050+10;
const double eps = 1e-10;
inline double sqr(double x){
    return x * x;
}
inline int dcmp(double x){
    return x < -eps ? -1 : x > eps;
}
struct Point{
    double x,y;
    int kind;
    Point(){}
    Point(double x,double y,int kind = 0):x(x),y(y),kind(kind){}
    bool operator < (const Point &p)const{
        return dcmp(x - p.x) < 0 || ( dcmp(x - p.x) == 0 && dcmp(y - p.y) < 0 );
    }
    Point operator - (const Point &p)const{
        return Point(x - p.x, y - p.y);
    }
    Point operator + (const Point &p)const{
        return Point(x + p.x, y + p.y);
    }
    Point operator * (const double &k)const{
        return Point (x*k , y*k);
    }
    Point operator / (const double &k)const{
        return Point (x/k, y/k);
    }
    double operator * (const Point &p)const{
        return x * p.y - y * p.x;
    }
    double operator / (const Point &p)const{
        return x * p.x + y * p.y;
    }
    void input(){
        scanf("%lf%lf",&x,&y);
    }
    void ot(){
        printf("%lf %lf\n",x,y);
    }
};
struct Line{
    Point a,b;
    int kind;
    Line (){}
    Line (Point a,Point b,int kind = 0):a(a),b(b),kind(kind){}
    double operator * (const Point &p)const{
        return ( b - a ) * ( p - a );
    }
    double operator / (const Point &p)const{
        return ( p - a) / ( p - b);
    }
    bool parallel(const Line &v){
        return !dcmp( ( b - a ) * ( v.b - v.a ) ); 
    }
    int LineCrossLine(const Line &v){
        if ( (*this).parallel(v) ){
            return ( dcmp( v * a ) == 0);
        }return 2;
    }
    int SegCrossSeg(const Line &v){
        int d1 = dcmp( (*this) * v.a);
        int d2 = dcmp( (*this) * v.b);
        int d3 = dcmp( v * a);
        int d4 = dcmp( v * b);
        if ( ( d1 ^ d2 ) == -2 && ( d3 ^ d4 ) == -2 ) return 2;
        return ( ( d1 == 0 && dcmp( (*this) / v.a ) <= 0 )
            ||   ( d2 == 0 && dcmp( (*this) / v.b ) <= 0 )
            ||   ( d3 == 0 && dcmp( v / a ) <= 0 )
            ||   ( d4 == 0 && dcmp( v / b ) <= 0 )
            );
    }
    Point CrossPoint(const Line &v){
        double s1 = v * a, s2 = v * b;
        return ( a * s2 - b * s1) / (s2 - s1);
    }
    void input(){
        a.input(); b.input();
    }
    void ot(){
        a.ot(); b.ot();
    }
};
int n,poly_n,xn;
vector<double> lx;
vector<Line> line;
double ans[N];
void init(){
    int sz = line.size();
    for (int i = 0; i < sz; i++){
        for (int j = i+1; j < sz; j++){
            if (line[i].SegCrossSeg(line[j]) == 2){
                Point p = line[i].CrossPoint(line[j]);
                lx.pbk(p.x);
            }
        }
    }
    sort(lx.begin(),lx.end());
    xn = unique(lx.begin(),lx.end()) - lx.begin();
}
vector<Point> qu[N];
void work(){
    for (int i = 0; i <= n; i++) ans[i] = 0;
    for (int i = 0; i < xn-1; i++){
        int k = 0;
        for (int j = 0; j+1 < qu[i].size(); j++){
            k += qu[i][j].kind;
            ans[ k ] += (lx[i+1] - lx[i]) * (qu[i][j+1].x+qu[i][j+1].y - qu[i][j].x - qu[i][j].y) / 2;        
        }
    }
    for (int i = 1; i <= n; i++) printf("%.10lf\n",ans[i]);
}
void solve(){
    for (int i = 0; i < xn; i++) qu[i].clear();
    for (int i = 0; i < line.size(); i++){
        int j = lower_bound(lx.begin(),lx.begin()+xn,line[i].a.x) - lx.begin();
        for (; j+1 < xn; j++ ){
            double l = lx[j], r = lx[j+1];
            if (dcmp(r - line[i].b.x) > 0) break;
            Point p1 = line[i].CrossPoint(Line(Point(l,0), Point(l,1)));
            Point p2 = line[i].CrossPoint(Line(Point(r,0), Point(r,1)));
            qu[j].pbk(Point(p1.y, p2.y,line[i].kind));
        }
    }
    for (int i = 0; i < xn - 1; i++) sort(qu[i].begin(), qu[i].end());
    work();
}
int main(){
    int T; scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        lx.clear(); line.clear();;
        for (int i = 0; i < n ;i++){
            Point t[4];
            for (int j = 0; j < 3; j++ ){
                t[j].input(); 
            }
            t[3] = t[0];
            int flag = 1;
            if (dcmp( (t[1] - t[0])*(t[2] - t[0]) ) == 0) flag = 0;
            for (int i = 0; i < 3 && flag; i++ ){
                lx.pbk(t[i].x);
                for (int j = i+1; j < 3; j++){
                    Line tmp; tmp.a = t[i]; tmp.b = t[j];
                    if (dcmp( tmp.a.x - tmp.b.x ) > 0) swap(tmp.a, tmp.b);
                    Line tmp2 = Line(t[3-i-j], Point(t[3-i-j].x, t[3-i-j].y - 1));
                    if (tmp.LineCrossLine(tmp2) != 2) continue;
                    Point tp = tmp.CrossPoint(tmp2);
                    if (dcmp(tp.y - t[3-i-j].y) < 0) tmp.kind = 1;
                        else tmp.kind = -1;    
                    line.pbk(tmp);
                }
            }
        }
        init();
        solve();    
    }
    return 0;
}
